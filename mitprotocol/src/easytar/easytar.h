
#ifndef EASYTAR_H
#define EASYTAR_H

#include <string>
#include <deque>

using namespace std;

class EasyTar
{
public:
    void EasyTarPack(deque <string> & files, string tarfile);

    void EasyTarUnpack(string tarfile, string targetPath, deque <string> & files);

private:
    // From http://en.wikipedia.org/wiki/Tar_(computing)#UStar_format
    typedef enum tar_file_type
    {
        tar_file_type_normal = '0',
        tar_file_type_hard_link = '1',
        tar_file_type_soft_link = '2',
        tar_file_type_directory = '5'
    } tar_file_type_t;

    struct tar_header
    {
        char name[100];               // file name
        char mode[8];                 // file mode
        char uid[8];                  // Owner's numeric user ID
        char gid[8];                  // Group's numeric user ID
        char size[12];                // File size in bytes (octal base)
        char mtime[12];               // Last modification time in
        // numeric Unix time format (octal)
        char checksum[8];             // Checksum for header record
        char typeflag[1];             // file type, see tar_file_type_t
        char linkname[100];           // Name of linked file
        char magic[6];                // UStar indicator "ustar"
        char version[2];              // UStar version "00"
        char uname[32];               // Owner user name
        char gname[32];               // Owner group name
        char devmajor[8];             // Device major number
        char devminor[8];             // Device minor number
        char prefix[155];             // Filename prefix
        char pad[12];                 // padding
    };

    void header_set_checksum(tar_header * header);

    void set_header(tar_header * header, const char * file_name, int file_size, tar_file_type_t file_type);

};


#endif // EASYTAR_H