#/usr/bin/bash

if [ -d "/usr/include/gtest" ]; then
  echo "gtest already installed"
  exit 0
else
  echo "About to install gtest libraries..."
fi

cd ~/
mkdir redis
cd redis

wget http://download.redis.io/releases/redis-2.8.17.tar.gz
tar xzf redis-2.8.17.tar.gz
cd redis-2.8.17

make
cd ..
rm redis-2.8.17.tar.gz
