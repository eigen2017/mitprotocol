# coding=utf-8


import mitprotocol

mitProtocolInterface = mitprotocol.CreateMitProtocolInterface()

mitProtocolInterface.UnTar("/home/data/issue/realaf/1476709047603.tar")

mitProtocolInterface.SetMitFilePath("/home/data/issue/realaf/", "ecg")

sigLen = mitprotocol.new_intp()
sigCnt = mitprotocol.new_intp()
frequency = mitprotocol.new_doublep()
gain = mitprotocol.new_doublep()
adcZero = mitprotocol.new_intp()
sigNames = mitprotocol.StringDeque()

mitProtocolInterface.GetHea(sigLen, sigCnt, frequency, gain, adcZero, sigNames)

dat = mitProtocolInterface.GetDat(1, 0, mitprotocol.intp_value(sigLen))
atr = mitProtocolInterface.GetAnn(0, mitprotocol.intp_value(sigLen))

print dat

for one_atr in atr:
    print one_atr.annType, one_atr.intervalFromLastAnn

mitprotocol.delete_intp(sigLen)
mitprotocol.delete_intp(sigCnt)
mitprotocol.delete_doublep(frequency)
mitprotocol.delete_doublep(gain)
mitprotocol.delete_intp(adcZero)


mitProtocolInterface.ReleaseMe()