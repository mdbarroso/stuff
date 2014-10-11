#include "WordCount.h"

void WordCount::splitLine(string lineToSplit, string* wordList, unsigned int& wordNumber)
{
    int size = lineToSplit.length();
    
    boost::regex re("\\s+");
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
    HashMap* map = new HashMap(3 * MAX_LENGTH);

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
                map->setValue(words[i]);
        }
            cout << "the was found: " << map->getValue("the") << endl;
        myfile.close();
    cout << "of was found: " << map->getValue("of") << endl;
        myfile.close();
cout << "this was found: " << map->getValue("this") << endl;
        myfile.close();
}
    else cout << "Unable to open file" << endl;
}
