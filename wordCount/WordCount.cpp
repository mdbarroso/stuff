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
            string words[200];
            wordCount->splitLine(line, words, numberOfWords);
            for (int i = 0; i < numberOfWords; i++) 
            {
                unsigned int occurances = map->setValue(words[i]);
                for (int j = 0; j < MAX_LENGTH; j++)
                {
                    continue;
                }
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
