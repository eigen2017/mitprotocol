
#ifndef MITPROTOCOL_MITPROTOCOLIMPL_H
#define MITPROTOCOL_MITPROTOCOLIMPL_H

#include "mitprotocol.h"

class MitProtocolImpl : public MitProtocolInterface
{
public:
    virtual void ReleaseMe();

    virtual void SetCallBack(MitProtocolCallBack * mitProtocolCallBack);

    virtual void SetMitTarFilePathAndName(const string & mitTarFilePathAndName, int isWrite);

public:
    virtual void GetMitHea(int & sigLen, int & sigCnt, double & frequency, double & gain, int & adcZero, deque <string> & sigNames, deque <string> & noteLines);

    virtual const deque <int> & GetMitDat(int channel, int sigStartPos, int sigLen);

    virtual const deque <MitProtocolAnnNode> & GetMitAnn(int sigStartPos, int sigLen);

public:
    virtual void SetMitAnn(const deque <MitProtocolAnnNode> & annNodes, int sigStartPos, int sigLen);


private:
    MitProtocolCallBack * mitProtocolCallBack;
    int isWrite;
    string mitTarFilePathName;
    string mitFilePath;
    string mitFileName;
    deque <string> mitSufixs;
    deque <deque <int>> channelDat;
    deque <MitProtocolAnnNode> annNodes;

private:
    int SplitFilePathAndName(const string & filePathAndName);

    void UnTarAndReNameFiles();

    void GetHea(int & sigLen, int & sigCnt, double & frequency, double & gain, int & adcZero, deque <string> & sigNames, deque <string> & noteLines);

    const deque <int> & GetDat(int channel, int sigStartPos, int sigLen);

    const deque <MitProtocolAnnNode> & GetAnn(int sigStartPos, int sigLen);

    void SetAnn(const deque <MitProtocolAnnNode> & annNodes, int sigStartPos, int sigLen);

    void TarMitFiles(const string & tarFileNameWithNoPathAndSuffix);

private:
    void ResetMe();

    void RearrangeDequeList(deque <deque <int>> & dequeList, int channel);

    void BackSlant(string & str);

    void AddSlantInTheFront(string & str);

    void SplitFilePathAndName(const string & filePathAndName, string & path_filePathAndName, string & new_filePathAndName, string & nameWithNoSurfix);


    int PathIsNotLegal(const string & path);

    void ReadMitFileAtr(const string & path, const string & name, deque <MitProtocolAnnNode> & atr, int startPos, int len);

    void ReadMitFileDat(const string & path, const string & name, int channel, deque <int> & dat, int startPos, int len);

    void ReadMitFileHea(const string & path, const string & name, double & gain, double & fq, int & sigLen, int & adcZ, int & sigCnt, deque <string> & sigNames, deque <string> & noteLines);

    int IsNotFileName(const string & filePathAndName);

    int IsNotPath(const string & path);

    void RenameFiles(deque <string> & files, string newName);


    void RemoveAllMitFiles();

public:
    MitProtocolImpl();

    ~MitProtocolImpl();
};


#endif //MITPROTOCOL_MITPROTOCOLIMPL_H
