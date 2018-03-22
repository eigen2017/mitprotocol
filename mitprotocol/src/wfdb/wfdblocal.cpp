
#include "wfdblocal.h"

#include "mycross.h"

#include <string.h>

#include <iomanip>

using namespace std;

WfdbLocal::WfdbLocal()
{
    InitMembers();
}

WfdbLocal::~WfdbLocal()
{
    ResetMe();
}

void WfdbLocal::ResetParams()
{
    ResetMe();
}

void WfdbLocal::InitMembers()
{
    filePathName = "";
    recordName = "";

    signalNum = 0;
    fmt = 0;
    samplingRate = 0;
    adcZero = 0;
    adcGain = 0;
    adcBits = 0;

    signalNameArray = NULL;
    checkSum16Array = NULL;
    firstValArry = NULL;

    isFirstWrite = 1;
    sampleCnt = 0;

    datFile = NULL;
    atrFile = NULL;

}

void WfdbLocal::ResetMe()
{
    ResetMembersHeaDat();
    ResetMembersAtr();
}

void WfdbLocal::ResetMembersHeaDat()
{
    filePathName = "";
    recordName = "";

    signalNum = 0;
    fmt = 0;
    samplingRate = 0;
    adcZero = 0;
    adcGain = 0;
    adcBits = 0;

    if (signalNameArray != NULL)
    {
        delete[] signalNameArray;
        signalNameArray = NULL;
    }

    if (checkSum16Array != NULL)
    {
        delete[] checkSum16Array;
        checkSum16Array = NULL;
    }

    if (firstValArry != NULL)
    {
        delete[] firstValArry;
        firstValArry = NULL;
    }

    isFirstWrite = 1;
    sampleCnt = 0;

    if (datFile != NULL)
    {
        fclose(datFile);
        datFile = NULL;
    }


}

void WfdbLocal::ResetMembersAtr()
{
    if (atrFile != NULL)
    {
        fclose(atrFile);
        atrFile = NULL;
    }

}

void WfdbLocal::GetAtrByte(int type, int interval, unsigned char & low8bit, unsigned char & high8bit)
{
    unsigned int tmp1;
    unsigned int tmp2;

    low8bit = (unsigned char) (interval & 0x000000ff);
    tmp1 = (unsigned int) (type & 0x0000003f);
    tmp1 = tmp1 << 2;
    tmp2 = (unsigned int) (interval & 0x00000300);
    tmp2 = tmp2 >> 8;
    high8bit = (unsigned char) (tmp1 | tmp2);
}

void WfdbLocal::GetAtrValue(unsigned char low8bit, unsigned char high8bit, int & type, int & interval)
{
    unsigned int tmp1;
    unsigned int tmp2;

    type = (int) ((high8bit & 0xfc) >> 2);

    tmp1 = (unsigned int) (high8bit & 0x03);
    tmp1 = tmp1 << 8;
    tmp2 = (unsigned int) low8bit;
    interval = (int) (tmp1 | tmp2);
}


void WfdbLocal::StartWriteLocal(
        string filePathName,
        string recordName,
        string * signalNameArray,
        int signalNum,
        int fmt,
        int samplingRate,
        int adcZero,
        double adcGain,
        int adcBits)
{
    int i;
    string datFileName;

//    MyPrint("StartWriteLocal:[%s]\n", filePathName.c_str());

    ResetMe();

    datFileName = filePathName + ".dat";


    this->filePathName = filePathName;
    this->recordName = recordName;
    this->signalNum = signalNum;
    this->fmt = fmt;
    this->samplingRate = samplingRate;
    this->adcZero = adcZero;
    this->adcGain = adcGain;
    this->adcBits = adcBits;

    this->signalNameArray = new string[signalNum];
    this->checkSum16Array = new short[signalNum];
    this->firstValArry = new int[signalNum];

    for (i = 0; i < signalNum; i++)
    {
        this->signalNameArray[i] = signalNameArray[i];
        this->checkSum16Array[i] = 0;
        this->firstValArry[i] = 0;
    }


    datFile = fopen(datFileName.c_str(), "wb+");

    if (datFile == NULL)
    {
        MyPrint("StartWriteLocal:error:path is illegal:[%s]\n", datFileName.c_str());
    }

}

void WfdbLocal::WriteLocalDat(int * signalGroup)
{
    int i;
    unsigned char high8bit;
    unsigned char low8bit;
    short tmpShort;

    if (datFile == NULL)
    {
        return;
    }

    sampleCnt++;

    if (isFirstWrite == 1)
    {
        isFirstWrite = 0;
        for (i = 0; i < signalNum; i++)
        {
            if (signalGroup[i] >= 32767)
            {
                tmpShort = 32767;
            }
            else if (signalGroup[i] <= -32768)
            {
                tmpShort = -32768;
            }
            else
            {
                tmpShort = (short) (signalGroup[i]);
            }

            checkSum16Array[i] += tmpShort;
            firstValArry[i] = tmpShort;

            high8bit = (tmpShort & 0xff00) >> 8;
            low8bit = tmpShort & 0x00ff;

            fwrite(&low8bit, 1, 1, datFile);
            fwrite(&high8bit, 1, 1, datFile);

        }
        return;
    }

    for (i = 0; i < signalNum; i++)
    {
        if (signalGroup[i] >= 32767)
        {
            tmpShort = 32767;
        }
        else if (signalGroup[i] <= -32768)
        {
            tmpShort = -32768;
        }
        else
        {
            tmpShort = (short) (signalGroup[i]);
        }

        checkSum16Array[i] += tmpShort;

        high8bit = (tmpShort & 0xff00) >> 8;
        low8bit = tmpShort & 0x00ff;
        fwrite(&low8bit, 1, 1, datFile);
        fwrite(&high8bit, 1, 1, datFile);
    }
}

void WfdbLocal::StopWriteLocal()
{
    int i;
    fstream heaFile;
    string heaFileName;

//    MyPrint("StopWriteLocal:[%s]\n", filePathName.c_str());

    if (filePathName == "")
    {
        MyPrint("StopWriteLocal:double close return\n");
        return;
    }

    heaFileName = filePathName + ".hea";

    heaFile.open(heaFileName.c_str(), ios::out | ios::trunc);

    if (!heaFile)
    {
        MyPrint("StopWriteLocal open fail!\n");
        return;
    }

    heaFile << recordName.c_str() << " " << signalNum << " " << samplingRate << " " << sampleCnt << "\r\n";

    for (i = 0; i < signalNum; i++)
    {
        heaFile << recordName << ".dat " << fmt << " " << setprecision(10) << adcGain << " " << adcBits << " " << adcZero << " " << firstValArry[i] << " " << checkSum16Array[i] << " 0 " << signalNameArray[i].c_str() << "\r\n";
    }

    heaFile.close();

    ResetMe();
}

void WfdbLocal::StartReadLocal(
        string filePathName,
        string & recordName,
        int & signalNum,
        int & fmt,
        int & samplingRate,
        int & sampleCnt,
        int & adcZero,
        double & adcGain,
        int & adcBits,
        deque <string> & sigNames,
        deque <string> & noteLines)
{
    int i;
    string datFileName;

    fstream heaFile;
    string heaFileName;
    string noteLine;

    string trash;

    ResetMe();

    datFileName = filePathName + ".dat";

    heaFileName = filePathName + ".hea";


    heaFile.open(heaFileName.c_str(), ios::in);

    if (!heaFile)
    {
        MyPrint("StartReadLocal open fail:%s!\n", heaFileName.c_str());
        return;
    }


    heaFile >> this->recordName;
    heaFile >> this->signalNum;
    heaFile >> this->samplingRate;
    heaFile >> this->sampleCnt;

    this->signalNameArray = new string[this->signalNum];
    this->checkSum16Array = new short[this->signalNum];
    this->firstValArry = new int[this->signalNum];

    for (i = 0; i < this->signalNum; i++)
    {
        heaFile >> trash;
        heaFile >> this->fmt;
        heaFile >> this->adcGain;
        heaFile >> this->adcBits;
        heaFile >> this->adcZero;
        heaFile >> this->firstValArry[i];
        heaFile >> this->checkSum16Array[i];
        heaFile >> trash;
        heaFile >> this->signalNameArray[i];
    }

    noteLines.clear();
    noteLine = "";
    while (getline(heaFile, noteLine))
    {
        if (0 == noteLine.find("# ") && noteLine.size() >= 3)
            noteLines.push_back(noteLine.substr(2));
    }

    heaFile.close();

    recordName = this->recordName;
    signalNum = this->signalNum;
    fmt = this->fmt;
    samplingRate = this->samplingRate;
    sampleCnt = this->sampleCnt;
    adcZero = this->adcZero;
    adcGain = this->adcGain;
    adcBits = this->adcBits;

    sigNames.clear();
    for (i = 0; i < this->signalNum; i++)
    {
        sigNames.push_back(this->signalNameArray[i]);
    }

    datFile = fopen(datFileName.c_str(), "rb+");

    if (datFile == NULL)
    {
        MyPrint("StartReadLocal:error:path is illegal:[%s]\n", datFileName.c_str());
    }

    return;
}

void WfdbLocal::ReadSignalNameArray(deque <string> & signalNameArray)
{
    int i;

    for (i = 0; i < signalNum; i++)
    {
        signalNameArray.push_back(this->signalNameArray[i]);
    }
}


int WfdbLocal::ReadLocalDat(int * signalGroup)
{
    int i;
    unsigned char high8bit;
    unsigned char low8bit;

    if (datFile == NULL)
    {
        return -1;
    }

    for (i = 0; i < signalNum; i++)
    {
        if (0 == fread(&low8bit, 1, 1, datFile))
        {
            return -1;
        }

        if (0 == fread(&high8bit, 1, 1, datFile))
        {
            return -1;
        }
        signalGroup[i] = (int) ((short) ((((unsigned short) high8bit) << 8) + low8bit));
    }

    return 0;
}

void WfdbLocal::StopReadLocal()
{
//    MyPrint("StopReadLocal\n");

    ResetMe();
}


void WfdbLocal::StartWriteAtr(string filePathName)
{
    string atrFileName;

//    MyPrint("StartWriteAtr:[%s]\n", filePathName.c_str());


    ResetMe();

    atrFileName = filePathName + ".atr";
    atrFile = fopen(atrFileName.c_str(), "wb+");

    if (atrFile == NULL)
    {
        MyPrint("StartWriteAtr:error:path is illegal:[%s]\n", atrFileName.c_str());
    }

}

void WfdbLocal::WriteAtrDat(int type, int interval)
{
    int cnt1023 = (int) (interval / 1023);
    int last1023 = interval % 1023;
    int i;
    unsigned char low8bit;
    unsigned char high8bit;

    if (atrFile == NULL)
    {
        return;
    }

    if (last1023 == 0)
    {
        if (interval != 0)
        {
            for (i = 0; i < cnt1023 - 1; i++)
            {
                GetAtrByte(0, 1023, low8bit, high8bit);
                fwrite(&low8bit, 1, 1, atrFile);
                fwrite(&high8bit, 1, 1, atrFile);
            }

            GetAtrByte(type, 1023, low8bit, high8bit);
            fwrite(&low8bit, 1, 1, atrFile);
            fwrite(&high8bit, 1, 1, atrFile);

        }
        else
        {
            GetAtrByte(type, 0, low8bit, high8bit);
            fwrite(&low8bit, 1, 1, atrFile);
            fwrite(&high8bit, 1, 1, atrFile);
        }

    }
    else
    {
        for (i = 0; i < cnt1023; i++)
        {
            GetAtrByte(0, 1023, low8bit, high8bit);
            fwrite(&low8bit, 1, 1, atrFile);
            fwrite(&high8bit, 1, 1, atrFile);
        }

        GetAtrByte(type, last1023, low8bit, high8bit);
        fwrite(&low8bit, 1, 1, atrFile);
        fwrite(&high8bit, 1, 1, atrFile);
    }
}

void WfdbLocal::StopWriteAtr()
{
//    MyPrint("StopWriteAtr\n");
    unsigned char low8bit;
    unsigned char high8bit;

    low8bit = 0;
    high8bit = 0;

    fwrite(&low8bit, 1, 1, atrFile);
    fwrite(&high8bit, 1, 1, atrFile);

    ResetMe();
}


void WfdbLocal::StartReadAtr(string filePathName)
{
    string atrFileName;

//    MyPrint("StartReadAtr:[%s]\n", filePathName.c_str());

    ResetMe();

    atrFileName = filePathName + ".atr";
    atrFile = fopen(atrFileName.c_str(), "rb+");

    if (atrFile == NULL)
    {
        MyPrint("StartReadAtr:error:path is illegal:[%s]\n", atrFileName.c_str());
    }

}

int WfdbLocal::ReadAtrDat(int & type, int & interval)
{
    unsigned char high8bit;
    unsigned char low8bit;
    int tmpType;
    int tmpInterval;

    interval = 0;

    if (atrFile == NULL)
    {
        return -1;
    }


    while (1)
    {
        if (0 == fread(&low8bit, 1, 1, atrFile))
        {
            return -1;
        }

        if (0 == fread(&high8bit, 1, 1, atrFile))
        {
            return -1;
        }

        GetAtrValue(low8bit, high8bit, tmpType, tmpInterval);

        if (tmpType == 0)
        {
            interval += tmpInterval;
        }
        else
        {
            interval += tmpInterval;
            type = tmpType;
            break;
        }
    }

    return 0;
}

void WfdbLocal::StopReadAtr()
{
//    MyPrint("StopReadAtr\n");

    ResetMe();
}


void WfdbLocal::RemoveFile(string filePathName)
{
    string fileName;

    fileName = filePathName + ".hea";
    remove(fileName.c_str());

    fileName = filePathName + ".dat";
    remove(fileName.c_str());

    fileName = filePathName + ".atr";
    remove(fileName.c_str());

}

void WfdbLocal::RemoveDir(string filePath)
{
    string fileName;

    fileName = filePath + "ecg.hea";
    remove(fileName.c_str());

    fileName = filePath + "ecg.dat";
    remove(fileName.c_str());

    fileName = filePath + "ecg.atr";
    remove(fileName.c_str());

    remove(filePath.c_str());
}

void OneColumnWR::ResetParams()
{
    ResetMe();
}

void OneColumnWR::StartWrite(string filePathName)
{
//    MyPrint("OneColumnWR::StartWrite:[%s]\n", filePathName.c_str());

    if (filePathName == "")
    {
//        MyPrint("OneColumnWR::StartWrite:double close return\n");
        return;
    }

    theFile = fopen(filePathName.c_str(), "wb+");
}

void OneColumnWR::WriteOneData(double oneData)
{
    if (theFile == NULL)
    {
        return;
    }

    char input[50];
    sprintf(input, "%lf\n", oneData);
    fwrite(input, strlen(input), 0x01, theFile);
}

void OneColumnWR::WriteOneDataInt(int oneData)
{
    if (theFile == NULL)
    {
        return;
    }

    char input[50];
    sprintf(input, "%d\n", oneData);
    fwrite(input, strlen(input), 0x01, theFile);
}

void OneColumnWR::StopWrite()
{
//    MyPrint("OneColumnWR::StopWrite\n");

    if (theFile == NULL)
    {
        return;
    }

    fclose(theFile);
    theFile = NULL;
}


void OneColumnWR::StartRead(string filePathName)
{
//    MyPrint("OneColumnWR::StartRead:[%s]\n", filePathName.c_str());

    if (filePathName == "")
    {
//        MyPrint("OneColumnWR::StartRead:double close return\n");
        return;
    }

    theFile = fopen(filePathName.c_str(), "r");
}

int OneColumnWR::ReadOneData(double & oneData)
{
    double data;

    if (theFile == NULL)
    {
        return -1;
    }

    fscanf(theFile, "%lf", &data);

    if (!feof(theFile))
    {
        oneData = data;
        return 0;
    }
    else
    {
        return -1;
    }

}

int OneColumnWR::ReadOneDataInt(int & oneData)
{
    int data;

    if (theFile == NULL)
    {
        return -1;
    }

    fscanf(theFile, "%d", &data);

    if (!feof(theFile))
    {
        oneData = data;
        return 0;
    }
    else
    {
        return -1;
    }
}

void OneColumnWR::StopRead()
{
//    MyPrint("OneColumnWR::StopRead\n");
    if (theFile == NULL)
    {
        return;
    }

    fclose(theFile);
    theFile = NULL;
}


void OneColumnWR::ResetMe()
{
    if (theFile != NULL)
    {
        fclose(theFile);
        theFile = NULL;
    }
}

OneColumnWR::OneColumnWR()
{
    theFile = NULL;
}

OneColumnWR::~OneColumnWR()
{
    ResetMe();
}

#if 0
int main()
{
#if 0
    int i;

    int val;
    
    WfdbLocal wfdbLocal;
    
    string recordName; 
    string signalNameArrayread[1]; 
    int signalNum; 
    int fmt;
    int samplingRate; 
    int sampleCnt;
    int adcZero;
    double adcGain;
    int adcBits;

    int readdat;

    string signalNameArray[1] = {"ECG_I"};

    wfdbLocal.StartWriteLocal("/srv/share/kaka/k_000001","k_000001",signalNameArray,1,16,512,0,6990.506667,16);

    for ( i = -32768 ; i <= 32767 ; i++ )
    {
        val = i;

        wfdbLocal.WriteLocalDat(&val);
    }
    
    wfdbLocal.StopWriteLocal();


    wfdbLocal.StartReadLocal("/srv/share/kaka/k_000001", recordName,signalNum,fmt,samplingRate,sampleCnt,adcZero,adcGain,adcBits);

    wfdbLocal.ReadSignalNameArray(signalNameArrayread);

    MyPrint("[%s][%d][%d][%d][%d][%d][%lf][%d][%s]\n",recordName.c_str(),signalNum,fmt,samplingRate,sampleCnt,adcZero,adcGain,adcBits,signalNameArrayread[0].c_str());
    
    for (i = 0; i < sampleCnt; i++ )
    {
        wfdbLocal.ReadLocalDat(&readdat);
        MyPrint("%d ",readdat);
        if (i%16 == 0)
        {
            MyPrint("\n");
        }
    }

    MyPrint("\n");

    wfdbLocal.StopReadLocal();
#else
    int i = 0;
int j =0;
    int val;

    int readdat;
    
    WfdbLocal wfdbLocal;

    int type;
    int interval;


    wfdbLocal.StartWriteAtr("/srv/share/kaka/k_000001");

    for ( j = 1024 ; j < 2000; j++ )
    {
        for ( i = 1 ; i <= 50 ; i++ )
        {
            val = i;
        
            wfdbLocal.WriteAtrDat(i,j);
        }

    }

    
    wfdbLocal.StopWriteAtr();


    wfdbLocal.StartReadAtr("/srv/share/kaka/k_000001");

    while (-1 != wfdbLocal.ReadAtrDat(type, interval))
    {i++;
        MyPrint("[%d:%d] ",type,interval);
        if (i%16 == 0)
        {
            MyPrint("\n");
        }
    }
    MyPrint("\n");
    wfdbLocal.StopReadAtr();

#endif
    
    return 0;
}
#endif

