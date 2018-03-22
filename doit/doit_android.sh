





export ANDROID_NDK=${NDK_ROOT}
export ANDROID_NDK_r12b=$ANDROID_NDK
export ANDROID_NDK_r10e=$ANDROID_NDK



export PATH="$PATH:/usr/share/maven/bin"

cd build/android/javainterface/
rm -rf ./*.h
rm -rf ./*.cxx
rm jarprj/src/main/java/com/zhuxin/mitprotocol/*.java
cd ../../../swig/
swig -c++ -java -package com.zhuxin.mitprotocol mitprotocol.i
mv *.java ../build/android/javainterface/jarprj/src/main/java/com/zhuxin/mitprotocol/
mv *.h ../build/android/javainterface/
mv *.cxx ../build/android/javainterface/
cd ../build/android/

rm -rf output
mkdir -p output

rm -rf objfolder
mkdir -p objfolder
cd objfolder


#cmake -DCMAKE_TOOLCHAIN_FILE=../../../toolchain/polly/android-ndk-r12b-api-9-armeabi.cmake \
#    -DANDROID_PHONE=1 -DANDROID_ABI=armeabi-v7a -DANDROID_STL=gnustl_shared -DANDROID_NATIVE_API_LEVEL=9 -DANDROID_TOOLCHAIN_VERSION=gcc-4.9 -DANDROID_TOOLCHAIN_NAME=arm-linux-androideabi-4.9\
#    -DCMAKE_BUILD_TYPE=Release \
#    -DCMAKE_INSTALL_PREFIX=./ \
#    -DCMAKE_SHARED_LINKER_FLAGS="-lz -lm -llog -pthread -ldl" \
#    ../../../../61_ecg_sdk/.



#cmake -DCMAKE_TOOLCHAIN_FILE=../../../toolchain/polly/android-ndk-r10e-api-9-armeabi-v7a.cmake \
#    -DANDROID_PHONE=1 \
#    -DCMAKE_BUILD_TYPE=Release \
#    -DCMAKE_INSTALL_PREFIX=./ \
#    -DCMAKE_SHARED_LINKER_FLAGS="-lz -lm -llog -pthread -ldl" \
#    ../../../../61_ecg_sdk/.

cmake -DCMAKE_TOOLCHAIN_FILE=../../../toolchain/polly/android-ndk-r12b-api-19-armeabi-v7a-neon.cmake \
    -DANDROID_PHONE=1 \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=./ \
    -DCMAKE_SHARED_LINKER_FLAGS="-lz -lm -llog -pthread -ldl" \
    ../../../../mitprotocol/.

make clean && make -j4

mv libmitprotocol.so ../output/

cd ../javainterface/jarprj
mvn package
cd target
mv mitprotocol-1.0.jar ../../../output/mitprotocol.jar






