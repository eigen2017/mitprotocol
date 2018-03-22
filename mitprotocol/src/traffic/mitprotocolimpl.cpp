#include <mycross.h>
#include "mitprotocolimpl.h"
#include "wfdblocal.h"
#include "easytar.h"

void MitProtocolImpl::ReleaseMe()
{
    delete this;
}

void MitProtocolImpl::SetCallBack(MitProtocolCallBack * mitProtocolCallBack)
{
    this->mitProtocolCallBack = mitProtocolCallBack;
}

void MitProtocolImpl::SetMitTarFilePathAndName(const string & mitTarFilePathAndName, int isWrite)
{
    if (0 != SplitFilePathAndName(mitTarFilePathAndName))
    {
        return;
    }

    if (isWrite == 0)
    {
        UnTarAndReNameFiles();
    }

    this->isWrite = isWrite;
}

void MitProtocolImpl::GetMitHea(int & sigLen, int & sigCnt, double & frequency, double & gain, int & adcZero, deque <string> & sigNames, deque <string> & noteLines)
{
    GetHea(sigLen, sigCnt, frequency, gain, adcZero, sigNames, noteLines);
}

const deque <int> & MitProtocolImpl::GetMitDat(int channel, int sigStartPos, int sigLen)
{
    return GetDat(channel, sigStartPos, sigLen);
}

const deque <MitProtocolAnnNode> & MitProtocolImpl::GetMitAnn(int sigStartPos, int sigLen)
{
    return GetAnn(sigStartPos, sigLen);
}

void MitProtocolImpl::SetMitAnn(const deque <MitProtocolAnnNode> & annNodes, int sigStartPos, int sigLen)
{
    SetAnn(annNodes, sigStartPos, sigLen);
}

int MitProtocolImpl::SplitFilePathAndName(const string & filePathAndName)
{
    int i;
    string new_filePath = "";
    string new_filePathAndName = "";
    string nameWithNoSurfix = "";

    mitTarFilePathName = "";
    mitFilePath = "";
    mitFileName = "";

    SplitFilePathAndName(filePathAndName, new_filePath, new_filePathAndName, nameWithNoSurfix);

    MyPrint("MitProtocolImpl::SplitFilePathAndName:new_filePath:[%s],new_filePathAndName:[%s],nameWithNoSurfix:[%s]\n",
            new_filePath.c_str(),
            new_filePathAndName.c_str(),
            nameWithNoSurfix.c_str());

    if (1 == IsNotFileName(nameWithNoSurfix))
    {
        MyPrint("MitProtocolImpl::SplitFilePathAndName:IsNotFileName:nameWithNoSurfix:[%s], return\n", nameWithNoSurfix.c_str());
        return 1;
    }

    if (1 == IsNotFileName(new_filePathAndName))
    {
        MyPrint("MitProtocolImpl::SplitFilePathAndName:IsNotFileName:new_filePathAndName:[%s], return\n", new_filePathAndName.c_str());
        return 1;
    }

    if (1 == IsNotPath(new_filePath))
    {
        MyPrint("MitProtocolImpl::SplitFilePathAndName:IsNotPath:new_filePath:[%s], return\n", new_filePath.c_str());
        return 1;
    }

    mitTarFilePathName = new_filePathAndName;
    mitFilePath = new_filePath;
    mitFileName = nameWithNoSurfix;


    MyPrint("MitProtocolImpl::SplitFilePathAndName:mitTarFilePathName:[%s],mitFilePath:[%s],mitFileName:[%s] and mitSufixs as follows:\n",
            mitTarFilePathName.c_str(),
            mitFilePath.c_str(),
            mitFileName.c_str());

    for (i = 0; i < mitSufixs.size(); i++)
    {
        MyPrint("MitProtocolImpl::SplitFilePathAndName:mitSufixs:[%d][%s]\n", i, mitSufixs[i].c_str());
    }

    return 0;
}

void MitProtocolImpl::UnTarAndReNameFiles()
{
    EasyTar easyTar;
    deque <string> files;

    easyTar.EasyTarUnpack(mitTarFilePathName, mitFilePath, files);

    RenameFiles(files, mitFileName);

}

void MitProtocolImpl::GetHea(int & sigLen, int & sigCnt, double & frequency, double & gain, int & adcZero, deque <string> & sigNames, deque <string> & noteLines)
{
    ReadMitFileHea(mitFilePath, mitFileName, gain, frequency, sigLen, adcZero, sigCnt, sigNames, noteLines);
}

const deque <int> & MitProtocolImpl::GetDat(int channel, int sigStartPos, int sigLen)
{
    RearrangeDequeList(channelDat, channel);

    ReadMitFileDat(mitFilePath, mitFileName, channel, channelDat[channel], sigStartPos, sigLen);

    return channelDat[channel];
}

const deque <MitProtocolAnnNode> & MitProtocolImpl::GetAnn(int sigStartPos, int sigLen)
{
    ReadMitFileAtr(mitFilePath, mitFileName, annNodes, sigStartPos, sigLen);

    return annNodes;

}

void MitProtocolImpl::SetAnn(const deque <MitProtocolAnnNode> & annNodes, int sigStartPos, int sigLen)
{
    int i;
    MyPrint("SetAnn:sigStartPos:%d,sigLen:%d\n", sigStartPos, sigLen);
    for (i = 0; i < annNodes.size(); i++)
    {
        MyPrint("SetAnn:%d,%d,%d,%d,%d,%s\n", annNodes[i].intervalFromLastAnn, annNodes[i].annType,
                annNodes[i].subType,
                annNodes[i].num, annNodes[i].chan, annNodes[i].aux.c_str());
    }


}

void MitProtocolImpl::TarMitFiles(const string & tarFileNameWithNoPathAndSuffix)
{
    EasyTar easyTar;

    deque <string> files;
    string target;

    if (1 == IsNotFileName(tarFileNameWithNoPathAndSuffix))
    {
        MyPrint("IsNotFileName:%s\n", tarFileNameWithNoPathAndSuffix.c_str());
        return;
    }

    target = mitFilePath + tarFileNameWithNoPathAndSuffix + ".tar";
    files.push_back(mitFilePath + mitFileName + ".hea");
    files.push_back(mitFilePath + mitFileName + ".dat");
    files.push_back(mitFilePath + mitFileName + ".atr");


    easyTar.EasyTarPack(files, target);

    return;
}

void MitProtocolImpl::ResetMe()
{
    int i;

    mitProtocolCallBack = NULL;

    isWrite = 0;

    mitTarFilePathName = "";
    mitFilePath = "";
    mitFileName = "";
    mitSufixs.clear();
    mitSufixs.push_back(".hea");
    mitSufixs.push_back(".dat");
    mitSufixs.push_back(".atr");

    for (i = 0; i < channelDat.size(); i++)
    {
        channelDat[i].clear();
    }
    channelDat.clear();

    annNodes.clear();
}

void MitProtocolImpl::RearrangeDequeList(deque <deque <int>> & dequeList, int channel)
{
    int i;
    int dequeCount = (int) dequeList.size();
    deque <int> oneDeque;

    oneDeque.clear();

    if (dequeCount > channel)
    {
        return;
    }

    for (i = 0; i < channel - dequeCount + 1; i++)
    {
        dequeList.push_back(oneDeque);
    }
}

void MitProtocolImpl::BackSlant(string & str)
{
    int i;

    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == '\\')
        {
            str[i] = '/';
        }
    }
}

void MitProtocolImpl::AddSlantInTheFront(string & str)
{
    if (str == "")
    {
        str = "./";
        return;
    }

    if (str[0] != '/' && str[0] != '.')
    {
        str = "./" + str;
    }
}

void MitProtocolImpl::SplitFilePathAndName(const string & filePathAndName, string & path_filePathAndName, string & new_filePathAndName, string & nameWithNoSurfix)
{
    path_filePathAndName = "";
    new_filePathAndName = filePathAndName;
    BackSlant(new_filePathAndName);
    AddSlantInTheFront(new_filePathAndName);
    path_filePathAndName = new_filePathAndName.substr(0, new_filePathAndName.rfind('/') + 1);
    nameWithNoSurfix = new_filePathAndName.substr(new_filePathAndName.rfind('/') + 1);
    nameWithNoSurfix = nameWithNoSurfix.substr(0, nameWithNoSurfix.rfind('.'));
}

int MitProtocolImpl::PathIsNotLegal(const string & path)
{
    if (path == "" || path.size() == 1)
    {
        return 1;
    }

    return 0;
}

void MitProtocolImpl::ReadMitFileDat(const string & path, const string & name, int channel, deque <int> & dat, int startPos, int len)
{
    int i;

    WfdbLocal wfdbLocalTmp;

    string recordName = "";
    int signalNum = 0;
    int fmt = 0;
    int samplingRate = 0;
    int sampleCnt = 0;
    int adcZero = 0;
    double adcGain = 0;
    int adcBits = 0;
    deque <string> sigNames;
    deque <string> noteLines;


    dat.clear();

    if (1 == PathIsNotLegal(path) || name == "")
    {
        return;
    }

    wfdbLocalTmp.StartReadLocal(path + name, recordName, signalNum, fmt, samplingRate, sampleCnt, adcZero, adcGain, adcBits, sigNames, noteLines);

    if (channel >= signalNum || signalNum <= 0 || channel <= 0 || startPos < 0 || len <= 0 || startPos >= sampleCnt || startPos + len > sampleCnt)
    {
        wfdbLocalTmp.StopReadLocal();
        return;
    }

    int * signalGroup = new int(signalNum);

    for (i = 0; i < sampleCnt; i++)
    {
        if (wfdbLocalTmp.ReadLocalDat(signalGroup) != 0)
        {
            break;
        }

        if (i >= startPos && i < startPos + len)
        {
            dat.push_back((int) ((double) signalGroup[channel]));
        }
    }

    delete (signalGroup);

    wfdbLocalTmp.StopReadLocal();
}

void MitProtocolImpl::ReadMitFileAtr(const string & path, const string & name, deque <MitProtocolAnnNode> & atr, int startPos, int len)
{
    atr.clear();

    WfdbLocal wfdbLocalTmp;
    int type;
    int interval;
    int globalPosition = 0;
    int realInterval;
    MitProtocolAnnNode mitProtocolAnnNode;

    wfdbLocalTmp.StartReadAtr(path + name);

    while (0 == wfdbLocalTmp.ReadAtrDat(type, interval))
    {
        globalPosition += interval;

        if (!(globalPosition >= startPos && globalPosition < startPos + len))
        {
            continue;
        }

        if (globalPosition - startPos < interval)
        {
            realInterval = globalPosition - startPos;
        }
        else
        {
            realInterval = interval;
        }

        mitProtocolAnnNode.intervalFromLastAnn = realInterval;
        mitProtocolAnnNode.annType = type;
        mitProtocolAnnNode.subType = 0;
        mitProtocolAnnNode.chan = 0;
        mitProtocolAnnNode.num = 0;
        mitProtocolAnnNode.aux = "";

        atr.push_back(mitProtocolAnnNode);
    }

    wfdbLocalTmp.StopReadAtr();

}

void MitProtocolImpl::ReadMitFileHea(
        const string & path,
        const string & name,
        double & gain,
        double & fq,
        int & sigLen,
        int & adcZ,
        int & sigCnt,
        deque <string> & sigNames,
        deque <string> & noteLines)
{
    WfdbLocal wfdbLocalTmp;

    string recordName = "";
    int signalNum = 0;
    int fmt = 0;
    int samplingRate = 0;
    int sampleCnt = 0;
    int adcZero = 0;
    double adcGain = 0;
    int adcBits = 0;

    gain = 0;
    fq = 0;
    sigLen = 0;
    adcZ = 0;
    sigCnt = 0;

    if (1 == PathIsNotLegal(path) || name == "")
    {
        return;
    }

    wfdbLocalTmp.StartReadLocal(path + name, recordName, signalNum, fmt, samplingRate, sampleCnt, adcZero, adcGain, adcBits, sigNames, noteLines);

    if (signalNum <= 0)
    {
        wfdbLocalTmp.StopReadLocal();
        return;
    }

    gain = adcGain;
    fq = (double) samplingRate;
    sigLen = sampleCnt;
    adcZ = adcZero;
    sigCnt = signalNum;

    wfdbLocalTmp.StopReadLocal();
}

int MitProtocolImpl::IsNotFileName(const string & filePathAndName)
{
    if (filePathAndName.size() == 0)
    {
        return 1;
    }

    if (filePathAndName[filePathAndName.size() - 1] == '/')
    {
        return 1;
    }

    return 0;
}

int MitProtocolImpl::IsNotPath(const string & path)
{
    if (path.size() == 0)
    {
        return 1;
    }

    if (path[path.size() - 1] != '/')
    {
        return 1;
    }

    return 0;
}

void MitProtocolImpl::RenameFiles(deque <string> & files, string newName)
{
    int i;
    string prefix = "";
    string surfix = "";
    string newFilePath = "";

    for (i = 0; i < files.size(); i++)
    {
        prefix = files[i].substr(0, files[i].rfind('/') + 1);
        surfix = files[i].substr(files[i].rfind('.'));
        newFilePath = prefix + newName + surfix;
        rename(files[i].c_str(), newFilePath.c_str());
    }
}


void MitProtocolImpl::RemoveAllMitFiles()
{
    int i;
    for (i = 0; i < mitSufixs.size(); i++)
    {
        remove((mitFilePath + mitFileName + mitSufixs[i]).c_str());
    }
}


MitProtocolImpl::MitProtocolImpl()
{
    ResetMe();
}

MitProtocolImpl::~MitProtocolImpl()
{
    if (isWrite == 0)
    {
        RemoveAllMitFiles();
    }

    ResetMe();
}

MitProtocolInterface * CreateMitProtocolInterface()
{
    return new MitProtocolImpl();
}