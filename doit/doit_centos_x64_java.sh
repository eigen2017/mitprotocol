

export PATH="$PATH:/usr/share/maven/bin"

cd build/centos_x64_java/javainterface/
rm -rf ./*.h
rm -rf ./*.cxx
rm jarprj/src/main/java/com/zhuxin/mitprotocol/*.java
cd ../../../swig/
swig -c++ -java -package com.zhuxin.mitprotocol mitprotocol.i
mv *.java ../build/centos_x64_java/javainterface/jarprj/src/main/java/com/zhuxin/mitprotocol/
mv *.h ../build/centos_x64_java/javainterface/
mv *.cxx ../build/centos_x64_java/javainterface/
cd ../build/centos_x64_java/

rm -rf output
mkdir -p output

rm -rf objfolder
mkdir -p objfolder
cd objfolder


cmake -DCMAKE_INSTALL_PREFIX=./ \
      -DCENTOS_X64_JAVA=1 \
      ../../../../mitprotocol/.

sudo make

mv libmitprotocol.so ../output/

cd ../javainterface/jarprj
mvn package
cd target
mv mitprotocol-1.0.jar ../../../output/mitprotocol.jar






