
#include "easytar.h"
#include "mycross.h"

#include <string.h>
#include <sys/stat.h>


#include <fstream>

using namespace std;


void EasyTar::EasyTarPack(deque <string> & files, string tarfile)
{
    char buf[512];
    tar_header header;
    int i;
    fstream tarFileStream;
    fstream fileStream;
    string onlyName;
    int fileLen;

    tarFileStream.open((tarfile + ".tmp").c_str(), ios::out | ios::trunc);

    if (!tarFileStream.is_open())
    {
        MyPrint("EasyTarPack:cannot create file:%s\n", (tarfile + ".tmp").c_str());
        tarFileStream.close();
        return;
    }

    for (i = 0; i < files.size(); i++)
    {
        fileStream.open(files[i].c_str(), ios::in);
        if (!fileStream.is_open())
        {
            MyPrint("EasyTarPack:cannot read file:%s\n", files[i].c_str());
            fileStream.close();
            continue;
        }

        fileStream.seekg(0, ios_base::end);
        fileLen = fileStream.tellg();
        fileStream.seekg(0, ios::beg);

        onlyName = files[i].substr(files[i].rfind('/') + 1);

        set_header(&header, onlyName.c_str(), fileLen, tar_file_type_normal);

        tarFileStream.write((const char *) &header, sizeof(tar_header));

        while (!fileStream.eof())
        {
            fileStream.read(buf, 512);
            tarFileStream.write(buf, fileStream.gcount());
        }
        fileStream.close();

        while (fileLen % sizeof(tar_header) != 0)
        {
            tarFileStream.put('\0');
            fileLen++;
        }


    }

    for (i = 0; i < 2 * sizeof(tar_header); i++)
    {
        tarFileStream.put('\0');
    }

    tarFileStream.close();

    rename((tarfile + ".tmp").c_str(), tarfile.c_str());
}


void EasyTar::EasyTarUnpack(string tarfile, string targetPath, deque <string> & files)
{
    char buf[512];
    fstream tarFileStream;
    tar_header header;
    fstream fileStream;
    long long unsigned int longfileLen;
    int fileLen;
    string fileWithPath;

    files.clear();

    MyPrint("EasyTarUnpack:[%s],target:[%s]\n", tarfile.c_str(), targetPath.c_str());

    tarFileStream.open(tarfile.c_str(), ios::in);
    if (!tarFileStream.is_open())
    {
        return;
    }

//    int x = 0;
    while (!tarFileStream.eof())
    {
//        MyPrint("%d\n", x++);
        tarFileStream.read((char *) &header, sizeof(tar_header));

        fileWithPath = targetPath + header.name;

        files.push_back(fileWithPath);

        fileStream.open(fileWithPath.c_str(), ios::out | ios::trunc);
        if (!fileStream.is_open())
        {
            tarFileStream.close();
            return;
        }

        sscanf(header.size, "%011llo", &longfileLen);
        fileLen = (int) longfileLen;
        while (fileLen > 512)
        {
            tarFileStream.read(buf, 512);
            fileStream.write(buf, 512);
            fileLen -= 512;
        }
        tarFileStream.read(buf, fileLen);
        fileStream.write(buf, fileLen);
        fileStream.close();

        while (tarFileStream.peek() == '\0')
        {
            tarFileStream.get();
        }
    }

    tarFileStream.close();
}


/* From Wikipedia: The checksum is calculated by taking the sum of the
 * unsigned byte values of the header record with the eight checksum
 * bytes taken to be ascii spaces. */
void EasyTar::header_set_checksum(tar_header * header)
{
    unsigned int sum = 0;

    char * pointer = (char *) header;
    char * end = pointer + sizeof(tar_header);

    // Iterate over header struct until we are at checksum field.
    while (pointer < header->checksum)
    {
        sum += *pointer & 0xff;
        pointer++;
    }

    // ... then add eight 'ascii spaces' ...
    sum += ' ' * 8;
    pointer += 8;

    // ... and go until the end.
    while (pointer < end)
    {
        sum += *pointer & 0xff;
        pointer++;
    }

    sprintf(header->checksum, "%06o", sum);
}

/* Every file in a tar file starts with the tar header */
void EasyTar::set_header(tar_header * header, const char * file_name, int file_size, tar_file_type_t file_type)
{

    memset(header, 0, sizeof(tar_header));

    sprintf(header->magic, "ustar");
    sprintf(header->mtime, "%011lo", (long unsigned int) 0);
    sprintf(header->mode, "%07o", 0644);

    sprintf(header->uname, "unkown");  // ... a bit random
    sprintf(header->gname, "users");
    header->typeflag[0] = 0;  // always just a normal file

    sprintf(header->name, "%s", file_name);
    sprintf(header->size, "%011llo", (long long unsigned int) file_size);
    sprintf(header->typeflag, "%c", file_type);
    header_set_checksum(header);
}


#if 0
int main()
{
    EasyTar easyTar;
    string files[3] = {
        "/srv/share/02_client/32_algorithm_lib/easytar/Spiel Mit Mir[1].mp3",
        "/srv/share/02_client/32_algorithm_lib/easytar/Carehub Schedule.xlsx",
        "/srv/share/02_client/32_algorithm_lib/easytar/ddd.sss"};

    easyTar.EasyTarPack(3, files,"/srv/share/02_client/32_algorithm_lib/easytar/src/haha.tar");
    easyTar.EasyTarUnpack("/srv/share/02_client/32_algorithm_lib/easytar/src/haha.tar");

    
    return 0;
}
#endif

