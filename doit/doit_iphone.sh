

cd build/ios/

rm -rf output
mkdir -p output

rm -rf objfolder
mkdir -p objfolder
cd objfolder

cmake -DCMAKE_TOOLCHAIN_FILE=../../../toolchain/polly/iOS.cmake -Wno-deprecated -DIOS_IPHONE=1 \
		-GXcode -DCMAKE_INSTALL_PREFIX=./ \
		../../../../61_ecg_sdk/.

xcodebuild

cp Debug-iphoneos/libecg_sdk.a ../output/

cp ../../../../61_ecg_sdk/src/core/ecganalyzesdk.h ../output/


