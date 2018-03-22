
#ifndef MITPROTOCOL_MITPROTOCOL_H
#define MITPROTOCOL_MITPROTOCOL_H

#include <string>
#include <deque>

using namespace std;

class MitProtocolAnnNode
{
public:
    int intervalFromLastAnn;
    int annType;
    int subType;
    int chan;
    int num;
    string aux;
};

class MitProtocolCallBack
{
public:
    virtual void TestFunc(deque <int> & param) = 0;
};

class MitProtocolInterface
{
public:
    virtual void ReleaseMe() = 0;

    virtual void SetCallBack(MitProtocolCallBack * mitProtocolCallBack) = 0;

    virtual void SetMitTarFilePathAndName(const string & mitTarFilePathAndName, int isWrite) = 0;

public:
    virtual void GetMitHea(int & sigLen, int & sigCnt, double & frequency, double & gain, int & adcZero, deque <string> & sigNames, deque <string> & noteLines) = 0;

    virtual const deque <int> & GetMitDat(int channel, int sigStartPos, int sigLen) = 0;

    virtual const deque <MitProtocolAnnNode> & GetMitAnn(int sigStartPos, int sigLen) = 0;

public:
    virtual void SetMitAnn(const deque <MitProtocolAnnNode> & annNodes, int sigStartPos, int sigLen) = 0;

};

MitProtocolInterface * CreateMitProtocolInterface();

#endif //MITPROTOCOL_MITPROTOCOL_H
