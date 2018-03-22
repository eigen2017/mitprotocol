# coding=utf-8

import matplotlib.pyplot as plt

import mitprotocol


class myclass(mitprotocol.MitProtocolCallBack):
    def __init__(self):
        mitprotocol.MitProtocolCallBack.__init__(self)
        self.mitProtocolInterface = mitprotocol.CreateMitProtocolInterface()
        self.mitProtocolInterface.SetCallBack(self)

    def __delete__(self):
        self.mitProtocolInterface.ReleaseMe()

    def TestFunc(self, param):
        print len(param)

    def playhaha(self):
        self.mitProtocolInterface.UnTar("")
        abcde = mitprotocol.MitProtocolAnnNode()
        abcde.annType = 435
        abcde.aux = 'aeevn'
        abcde.chan = 234
        abcde.intervalFromLastAnn = 4524;
        abcde.num = 23;
        abcde.subType = 5478;
        listabc = mitprotocol.MitProtocolAnnNodeDeque()
        listabc.push_back(abcde)
        listabc.push_back(abcde)
        abcde.aux = 'sefwer'
        listabc.push_back(abcde)
        self.mitProtocolInterface.setAnn(listabc, 1443,65)

abc = mitprotocol.CreateMitProtocolInterface()

ddd = "/home/data/issue/realaf/1476709047603.tar"

abc.UnTar(ddd)

abc.SetMitFilePath("/home/data/issue/realaf/", "ecg")

channel0 = abc.GetDat(0, 323, 32)

channel1 = abc.GetDat(1, 44, 22)

sigLen = mitprotocol.new_intp()
sigCnt = mitprotocol.new_intp()
frequency = mitprotocol.new_doublep()
gain = mitprotocol.new_doublep()
adcZero = mitprotocol.new_intp()
sigNames = mitprotocol.StringDeque()

abc.GetHea(sigLen, sigCnt, frequency, gain, adcZero, sigNames)

print "=================="
print mitprotocol.intp_value(sigLen)
print mitprotocol.intp_value(sigCnt)
print mitprotocol.doublep_value(frequency)
print mitprotocol.doublep_value(gain)
print mitprotocol.intp_value(adcZero)
print sigNames[3]
print "=================="

sd = abc.GetAnn(0, mitprotocol.intp_value(sigLen))

mitprotocol.delete_intp(sigLen)
mitprotocol.delete_intp(sigCnt)
mitprotocol.delete_doublep(frequency)
mitprotocol.delete_doublep(gain)
mitprotocol.delete_intp(adcZero)



for sdone in sd:
    print("sdone:%d,%s,%d,%d,%d,%d" % (
    sdone.annType, sdone.aux, sdone.chan, sdone.intervalFromLastAnn, sdone.num, sdone.subType))

print channel0

# print channel0
# print channel1

# plt.plot(channel1)
# plt.show()


abc.ReleaseMe()

print '#####################################'

ffsa = myclass()
ffsa.playhaha()
