
#ifndef MITPROTOCOL_MITPROTOCOL_H
#define MITPROTOCOL_MITPROTOCOL_H

#include <string>
#include <deque>
using namespace std;

class MitProtocolInterface
{
public:
    virtual void ReleaseMe() = 0;
    virtual void UnTar(const string & filePathAndName) = 0;
    virtual void SetMitFilePath(const string & mitFilePath, const string & mitFileName) = 0;
    virtual const deque<int> & GetDat(int channel) = 0;
};

MitProtocolInterface * CreateMitProtocolInterface();

#endif //MITPROTOCOL_MITPROTOCOL_H
