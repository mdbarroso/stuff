#ifndef WORDCOUNT_H
#define WORDCOUNT_H
#endif

#include "DataTypes.h"
#include <iostream>
#include <fstream> 
#include <boost/regex.hpp>

#define WORD_NUMBER 20

using namespace std;

class WordCount {
   //void exchange(unsigned int index, MostRepeatedWord word);
  
public:
   MostRepeatedWord words[WORD_NUMBER];
   WordCount();
   bool setWord(unsigned int occurances, string word);
   MostRepeatedWord* getWords();
   void splitLine(string lineToSplit, string* wordList, unsigned int& wordNumber);
};
