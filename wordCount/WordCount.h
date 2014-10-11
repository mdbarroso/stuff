#ifndef WORDCOUNT_H
#define WORDCOUNT_H
#endif

#include "DataTypes.h"
#include <iostream>
#include <fstream> 
#include <boost/regex.hpp>

#define WORD_NUMBER 20

using namespace std;

struct MostRepeatedWord {
    string word;
    unsigned int occurance;
};

class WordCount {
   MostRepeatedWord words[WORD_NUMBER]; 
  
public:
   MostRepeatedWord* getRepeatedWords();
   bool setWord(MostRepeatedWord word);
   void splitLine(string lineToSplit, string* wordList, unsigned int& wordNumber);
};
