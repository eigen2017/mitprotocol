package com.zhuxin;


import com.zhuxin.mitprotocol.*;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

public class test extends MitProtocolCallBack
{

    public MitProtocolInterface mitProtocolInterface;

    public void start()
    {
        mitProtocolInterface = mitprotocol.CreateMitProtocolInterface();
        mitProtocolInterface.SetCallBack(this);
    }

    public void stop()
    {
        mitProtocolInterface.ReleaseMe();
    }

    public void TestFunc(IntDeque param)
    {
//        super.TestFunc(param);
        for (int i = 0; i < param.size(); i++)
            System.out.println("call back suc!!" + param.getitem(i));
    }

    public void playhaha()
    {
        mitProtocolInterface.UnTar("/home/data/issue/realaf/1476709047603.tar");
        mitProtocolInterface.SetMitFilePath("/home/data/issue/realaf", "ecg");
        SWIGTYPE_p_int sigLen = mitprotocol.new_intp();
        SWIGTYPE_p_int sigCnt = mitprotocol.new_intp();
        SWIGTYPE_p_double frequency = mitprotocol.new_doublep();
        SWIGTYPE_p_double gain = mitprotocol.new_doublep();
        SWIGTYPE_p_int adcZero = mitprotocol.new_intp();
        mitProtocolInterface.GetHea(sigLen, sigCnt, frequency, gain, adcZero);


        IntDeque he = mitProtocolInterface.GetDat(0, 3, 300);
        System.out.println("playhaha:" + he.getitem(100) + ",sigLen:" + mitprotocol.intp_value(sigLen) + ",sigCnt:" +
                mitprotocol.intp_value(sigCnt) + ",frequency:" + mitprotocol.doublep_value(frequency)
                + ",gain:" + mitprotocol.doublep_value(gain) + ",adcZero:" + mitprotocol.intp_value(adcZero));


        MitProtocolAnnNodeDeque abc = mitProtocolInterface.GetAnn(12, 444);

        int i;
        for (i = 0; i < abc.size(); i++)
        {

            System.out.println("playhaha:"
                    + abc.getitem(i).getIntervalFromLastAnn()
                    + ":" + abc.getitem(i).getAux()
                    + ":" + abc.getitem(i).getChan()
                    + ":" + abc.getitem(i).getNum()
                    + ":" + abc.getitem(i).getAnnType()
                    + ":" + abc.getitem(i).getSubType()
            );
        }

        MitProtocolAnnNode node = new MitProtocolAnnNode();
        node.setAnnType(1453);
        node.setAux("awefs");
        node.setChan(23);
        node.setIntervalFromLastAnn(2233);
        node.setNum(34);
        node.setSubType(5552);

        MitProtocolAnnNodeDeque ddd = new MitProtocolAnnNodeDeque();
        ddd.push_back(node);
        ddd.push_back(node);

        node.setAnnType(1423453);
        node.setAux("awsdf4efs");
        node.setChan(22343);
        node.setIntervalFromLastAnn(223233);
        node.setNum(3444);
        node.setSubType(55352);

        ddd.push_back(node);

        mitProtocolInterface.setAnn(ddd, 23, 4441);


        mitprotocol.delete_intp(sigLen);
        mitprotocol.delete_intp(sigCnt);
        mitprotocol.delete_doublep(frequency);
        mitprotocol.delete_doublep(gain);
        mitprotocol.delete_intp(adcZero);


    }

    public void testarry(String[] deepIds, AtomicInteger duixiang1, AtomicInteger dou2)
    {
        duixiang1.set(deepIds.length);
        int nimei = 0;
        for (int i = 0; i < deepIds.length; i++)
        {
            nimei += deepIds[i].length();
        }
        dou2.set(nimei);

    }

    public static void main(String[] args)
    {
        test abc = new test();
        abc.start();
        abc.playhaha();
        String[] deepIds = new String[5];
        Integer len = new Integer(0);

        deepIds[0] = "nimei1";

        deepIds[1] = "nime2";

        deepIds[2] = "nimei3";

        deepIds[3] = "nimei4";

        deepIds[4] = "nimei5";
        Integer i1 = 0;
        Integer i2 = 2;

        AtomicInteger duixiang = new AtomicInteger();
        AtomicInteger duixiang2 = new AtomicInteger();


        abc.testarry(deepIds, duixiang, duixiang2);

        abc.stop();

        System.out.println("come on : " + len + "\n" + duixiang.get() + "\n" + duixiang2.get() + "\n");
    }
}
