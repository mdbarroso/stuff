#ifndef DATATYPES_H
#define DATATYPES_H
#endif

#include <cmath>
#include <iostream>
//#include <cstdlib>
#include <string>
//#include <cstdio>
using namespace std;

#define	MAX_LENGTH	1024	// 1K elements

class HashEntry {
  string keyM;
  unsigned int valueM;

public:
  HashEntry* nextM;
  HashEntry(string key);
  string getKey();
  unsigned int getValue();
  void incrementValue();
  HashEntry* getNext();
  void incrementCounter();
};

struct MostRepeatedWord {
    string word;
    unsigned int occurance;
};

class HashMap {
  
  HashEntry **hashNodes;
  int lengthM;

public:
  HashMap(int maxLength);
  ~HashMap();
  int getLength();
  unsigned int getValue(string key);
  unsigned int setValue(string key);
  unsigned long hashFunction(string key, int maxSize);
  void sortHash(unsigned int size, MostRepeatedWord* words);
};
