#include "WordCount.h"

WordCount::WordCount()
{
    for (int i = 0; i < WORD_NUMBER; i++) 
    {
        this->words[i].word = "";
        this->words[i].occurance = 0;
    }
}

void WordCount::splitLine(string lineToSplit, string* wordList, unsigned int& wordNumber)
{
    int size = lineToSplit.length();

    // could not do it in your time requirements without boost....
    boost::regex re("[ \\,\\.\\;\\(\\)\\[\\]\\{\\}]");
    boost::sregex_token_iterator i(lineToSplit.begin(), lineToSplit.end(), re, -1);
    boost::sregex_token_iterator j;

    unsigned count = 0;
    while(i != j) {*i++; count++;}
    wordNumber = count;

    boost::sregex_token_iterator i2(lineToSplit.begin(), lineToSplit.end(), re, -1);
    for (int k = 0; k < count; k++) if (*i2 != NULL) wordList[k] = (string) *i2++;
}

int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        cout << "Program takes 1 argument - path of file to read." << endl;
        return -1;
    }
    string fileName = argv[1];

    WordCount* wordCount = new WordCount();
    HashMap* map = new HashMap(MAX_LENGTH);

    ifstream myfile (fileName.c_str(), ios::out|ios::binary);
    string line;

    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            unsigned int numberOfWords = 0;
            string words[200];      // supposing that 1 line will have at most 200 words... fair assumption I guess
            wordCount->splitLine(line, words, numberOfWords);
            for (int i = 0; i < numberOfWords; i++) 
            {
                if (words[i].length() == 0) continue;
                map->setValue(words[i]);
            }
        }
        myfile.close();
        MostRepeatedWord repeatedWords[20];
        map->sortHash(20, repeatedWords);
        for (int i = 0; i < WORD_NUMBER; i++) 
        {
            cout << repeatedWords[i].occurance << " " << repeatedWords[i].word << endl;
        }
    }
    else cout << "Unable to open file" << endl;
}
