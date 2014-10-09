#/usr/bin/bash

# get gtest
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip

# config & make
unzip gtest-1.7.0.zip
cd gtest-1.7.0
./configure
make

sudo cp -a include/gtest /usr/include
sudo cp -a lib/.libs/* /usr/lib/

sudo ldconfig -v | grep gtest

rm -rf gtest-1.7.0.zip


