#include "WordCount.h"

int main(int argc, char* argv[])
{
    cout << "argc: " << argc << endl;
    cout << "argv: " << argv[1] << endl;

    if (argc != 2) 
    {
        cout << "Program takes 1 argument - path of file to read." << endl;
        return -1;
    }
    string fileName = argv[1];

    WordCount* wordCount = new WordCount();

    ifstream myfile (fileName.c_str(), ios::out|ios::binary);
    string line;

    if (myfile.is_open())
    {
        while(getline(myfile, line))
        {
            cout << line << endl;

        }
        myfile.close();
    }
    else cout << "Unable to open file" << endl;


}
