#/usr/bin/bash

if [ -d "/usr/include/gtest" ]; then
  echo "gtest already installed"
  exit 0
else
  echo "About to install gtest libraries..."
fi

# get gtest
cd ~/
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip

# config & make
unzip gtest-1.7.0.zip
cd gtest-1.7.0
./configure
make

sudo cp -a include/gtest /usr/include
sudo cp -a lib/.libs/* /usr/lib/

sudo ldconfig -v | grep gtest

cd ..
rm gtest-1.7.0.zip


