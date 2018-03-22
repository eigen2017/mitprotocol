
#include <mycross.h>
#include <cstring>
#include "mitprotocol.h"
#include "mitprotocolimpl.h"


class testclass : public MitProtocolCallBack
{

public:
    void playhaha();

private:
    string str_res;

public:
    virtual void TestFunc(deque <int> & param);

private:
    MitProtocolImpl * mitProtocolInterface;

public:
    testclass();

    ~testclass();
};

void testclass::playhaha()
{

    double frequency;
    double gain;
    int sigLen;
    int adcZero;
    int sigCnt;
    deque <string> sigNames;
    deque <string> noteLines;

//    mitProtocolInterface->SetMitTarFilePathAndName("/home/data/issue/realaf/1476709047603.tar");
    mitProtocolInterface->SetMitTarFilePathAndName("./1476709047603.tar", 0);

    mitProtocolInterface->GetMitHea(sigLen, sigCnt, frequency, gain, adcZero, sigNames, noteLines);

    const deque <int> & dat = mitProtocolInterface->GetMitDat(1, 843, 5);

//    WriteDequeToFile(dat, "/home/data/issue/1502422234871797/filterd.txt");



    int x = 17;
    printf("x:%d\n", x);

    printf("[%f,%f,%d,%d,%d]\n", frequency, gain, sigLen, sigCnt, adcZero);
    for (int i = 0; i < sigCnt; ++i)
    {
        printf("sigNames:%s\n", sigNames[i].c_str());
    }

    printf("size:[%d][%d,%d,%d,%d]\n",
           dat.size(), dat[dat.size() - 1], dat[dat.size() - 2], dat[dat.size() - 3], dat[dat.size() - 4]);


    const deque <MitProtocolAnnNode> & nimei = mitProtocolInterface->GetMitAnn(843, sigLen - 843);

    for (int i = 0; i < nimei.size(); i++)
    {
        printf("GetAnn:%d,%d,%d,%d,%d,%s\n",
               nimei[i].annType,
               nimei[i].intervalFromLastAnn,
               nimei[i].subType,
               nimei[i].chan,
               nimei[i].num,
               nimei[i].aux.c_str()
        );
    }

    deque <MitProtocolAnnNode> nimeimei;
    MitProtocolAnnNode a;
    a.aux = "sdf";
    a.chan = 0;
    a.num = 0;
    a.annType = 123;
    a.subType = 456;
    a.intervalFromLastAnn = 34;
    nimeimei.push_back(a);
    nimeimei.push_back(a);
    a.aux = "asdf";
    nimeimei.push_back(a);
    mitProtocolInterface->SetMitAnn(nimeimei, 123, 555);

//    mitProtocolInterface->TarMitFiles("nimei");

    return;
}

void testclass::TestFunc(deque <int> & param)
{
    str_res = "";
    for (int i = 0; i < param.size(); i++)
    {
        if (param[i] > 3)
        {
            str_res += "[>3]";
        }
        else
        {
            str_res += "[<=3]";
        }

        str_res += "d";
    }

//    return str_res;
}

testclass::testclass()
{
    mitProtocolInterface = (MitProtocolImpl *) CreateMitProtocolInterface();
    mitProtocolInterface->SetCallBack(this);
}

testclass::~testclass()
{
    mitProtocolInterface->ReleaseMe();
}


void WriteDequeToFile(const deque <int> & dat, const string & fileName)
{
    int i;
    FILE * fp123 = fopen(fileName.c_str(), "wb+");

    for (i = 0; i < dat.size(); i++)
    {
        char input[100];
        sprintf(input, "%d\r\n", dat[i]);
        fwrite(input, strlen(input), 0x01, fp123);
    }

    fclose(fp123);
}

int main(int argc, char ** argv)
{
//    MitProtocolInterface * mitProtocolInterface = CreateMitProtocolInterface();
//
//    mitProtocolInterface->UnTarAndReNameFiles("/home/data/issue/1502422234871797/1502422234871797.tar");
//    mitProtocolInterface->SetMitFilePath("/home/data/issue/1502422234871797/", "ecg");
//    const deque<int> & dat = mitProtocolInterface->GetDat(1);
//
//    WriteDequeToFile(dat, "/home/data/issue/1502422234871797/filterd.txt");
//
//    printf("gain:%f,fq:%f\n", mitProtocolInterface->GetGain(), mitProtocolInterface->GetFrequency());
//
//    mitProtocolInterface->ReleaseMe();

    testclass haha;
    haha.playhaha();

    return 0;
}