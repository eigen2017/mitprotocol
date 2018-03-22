

cd build/centos_x64/

rm -rf output
mkdir -p output

rm -rf objfolder
mkdir -p objfolder
cd objfolder

cmake -DCMAKE_INSTALL_PREFIX=./ \
      -DCENTOS_X64=1 \
      ../../../../mitprotocol/.

sudo make

cp libmitprotocol.so ../output/
cp ../../../../mitprotocol/src/traffic/mitprotocol.h ../output/


