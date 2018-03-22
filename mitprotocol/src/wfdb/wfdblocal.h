
#ifndef WFDBLOCAL_H
#define WFDBLOCAL_H

#include <stdio.h>

#include <string>
#include <fstream>
#include <deque>

using namespace std;

#define    NOTQRS    0    /* not-QRS (not a getann/putann code) */
#define NORMAL    1    /* normal beat */
#define    LBBB    2    /* left bundle branch block beat */
#define    RBBB    3    /* right bundle branch block beat */
#define    ABERR    4    /* aberrated atrial premature beat */
#define    PVC    5    /* premature ventricular contraction */
#define    FUSION    6    /* fusion of ventricular and normal beat */
#define    NPC    7    /* nodal (junctional) premature beat */
#define    APC    8    /* atrial premature contraction */
#define    SVPB    9    /* premature or ectopic supraventricular beat */
#define    VESC    10    /* ventricular escape beat */
#define    NESC    11    /* nodal (junctional) escape beat */
#define    PACE    12    /* paced beat */
#define    UNKNOWN1    13    /* unclassifiable beat */
#define    NOISE    14    /* signal quality change */
#define ARFCT    16    /* isolated QRS-like artifact */
#define STCH    18    /* ST change */
#define TCH    19    /* T-wave change */
#define SYSTOLE    20    /* systole */
#define DIASTOLE 21    /* diastole */
#define    NOTE    22    /* comment annotation */
#define MEASURE 23    /* measurement annotation */
#define PWAVE    24    /* P-wave peak */
#define    BBB    25    /* left or right bundle branch block */
#define    PACESP    26    /* non-conducted pacer spike */
#define TWAVE    27    /* T-wave peak */
#define RHYTHM    28    /* rhythm change */
#define UWAVE    29    /* U-wave peak */
#define    LEARN    30    /* learning */
#define    FLWAV    31    /* ventricular flutter wave */
#define    VFON    32    /* start of ventricular flutter/fibrillation */
#define    VFOFF    33    /* end of ventricular flutter/fibrillation */
#define    AESC    34    /* atrial escape beat */
#define SVESC    35    /* supraventricular escape beat */
#define LINK    36    /* link to external data (aux contains URL) */
#define    NAPC    37    /* non-conducted P-wave (blocked APB) */
#define    PFUS    38    /* fusion of paced and normal beat */
#define WFON    39    /* waveform onset */
#define PQ    WFON    /* PQ junction (beginning of QRS) */
#define WFOFF    40    /* waveform end */
#define    JPT    WFOFF    /* J point (end of QRS) */
#define RONT    41    /* R-on-T premature ventricular contraction */

#define IK_PACKET_LOST = 42, /* ikinloop extention: ecg data packet lost */

/* ... annotation codes between RONT+1 and ACMAX inclusive are user-defined */

#define    ACMAX    49    /* value of largest valid annot code (must be < 50) */


class WfdbLocal
{
public:
    void ResetParams();


    void StartWriteLocal(
            string filePathName,
            string recordName,
            string * signalNameArray,
            int signalNum,
            int fmt,
            int samplingRate,
            int adcZero,
            double adcGain,
            int adcBits);

    void WriteLocalDat(int * signalGroup);

    void StopWriteLocal();


    void StartReadLocal(
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
            deque <string> & noteLines);

    void ReadSignalNameArray(deque <string> & signalNameArray);

    int ReadLocalDat(int * signalGroup);

    void StopReadLocal();

    void StartWriteAtr(string filePathName);

    void WriteAtrDat(int type, int interval);

    void StopWriteAtr();


    void StartReadAtr(string filePathName);

    int ReadAtrDat(int & type, int & interval);

    void StopReadAtr();


    static void RemoveFile(string filePathName);

    static void RemoveDir(string filePath);


private:
    string filePathName;
    string recordName;
    string * signalNameArray;
    int signalNum;
    int fmt;
    int samplingRate;
    int adcZero;
    double adcGain;
    int adcBits;

    short * checkSum16Array;
    int * firstValArry;

    int isFirstWrite;
    int sampleCnt;

    FILE * datFile;
    FILE * atrFile;


private:
    void InitMembers();

    void ResetMe();

    void ResetMembersHeaDat();

    void ResetMembersAtr();

    void GetAtrByte(int type, int interval, unsigned char & low8bit, unsigned char & high8bit);

    void GetAtrValue(unsigned char low8bit, unsigned char high8bit, int & type, int & interval);


public:
    WfdbLocal();

    ~WfdbLocal();
};

class OneColumnWR
{
public:
    void ResetParams();

    void StartWrite(string filePathName);

    void WriteOneData(double oneData);

    void WriteOneDataInt(int oneData);

    void StopWrite();


    void StartRead(string filePathName);

    int ReadOneData(double & oneData);

    int ReadOneDataInt(int & oneData);

    void StopRead();

private:
    FILE * theFile;

private:
    void ResetMe();

public:
    OneColumnWR();

    ~OneColumnWR();
};


#endif // WFDBLOCAL_H
