#ifndef DATATYPES_H
#define DATATYPES_H
#endif

#include <cmath>
#include <iostream>
//#include <cstdlib>
#include <string>
//#include <cstdio>
using namespace std;

#define	MAX_LENGTH	4096	// 4K elements

template <class K, class V>
class HashEntry {
  K keyM;
  V valueM;

public:
  HashEntry* nextM;
  HashEntry(K key, V value);
  K getKey();
  V getValue();
  HashEntry* getNext();
};

template <class K, class V>
class HashMap {
  
  HashEntry<K,V> **hashNodes;
  int lengthM;

public:
  HashMap(int maxLength);
  ~HashMap();
  int getLength();
  V getValue(K key);
  void setValue(K key, V value);
  unsigned long hashFunction(string key);

};
