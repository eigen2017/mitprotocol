
cd build/centos_x64_python/pythoninterface/
rm -rf ./*
cd ../../../swig/
swig -c++ -python mitprotocol.i
mv *.py ../build/centos_x64_python/pythoninterface/
mv *.h ../build/centos_x64_python/pythoninterface/
mv *.cxx ../build/centos_x64_python/pythoninterface/
cd ../build/centos_x64_python/

rm -rf output
mkdir -p output

rm -rf objfolder
mkdir -p objfolder
cd objfolder

cmake -DCMAKE_INSTALL_PREFIX=./ \
      -DCENTOS_X64_PYTHON=1 \
      ../../../../mitprotocol/.

sudo make

mv libmitprotocol.so ../output/_mitprotocol.so

cp ../pythoninterface/mitprotocol.py ../output/
