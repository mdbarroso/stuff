#include "DataTypes.h"

HashEntry::HashEntry(string key)
{
    this->keyM = key;
    this->valueM = 1;   // when the entry is created, is because the word exists
    this->nextM = NULL;
}

string HashEntry::getKey()
{
    return this->keyM;
}

unsigned int HashEntry::getValue()
{
    return this->valueM;
}


void HashEntry::incrementCounter()
{
    this->valueM++;
}

HashMap::HashMap(int maxLength)
{
    lengthM = maxLength;
    hashNodes = new HashEntry*[maxLength];
    for (int i = 0; i < maxLength; i++) hashNodes[i] = NULL;
}

HashMap::~HashMap()
{
    for (int i = 0; i < this->getLength(); i++)
    {
        HashEntry* node = hashNodes[i];
        while(node != NULL)
        {
            HashEntry* previous = node;
            node = node->nextM;
            delete previous;
        }
    }
    delete[] hashNodes;
}

int HashMap::getLength()
{
    return lengthM;
}

unsigned long
HashMap::hashFunction(string word, int maxSize)
{
    // quick hash copied from internet
    unsigned long hash = 5381;
    int c;
    const char* str = word.c_str();

    while (c = *str++) hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % maxSize;
}

unsigned int HashMap::getValue(string key)
{
    unsigned long hash = this->hashFunction(key, this->lengthM);
    HashEntry* nextNode = this->hashNodes[hash];
    while (nextNode != NULL)
    {
        if (nextNode->getKey().compare(key) == 0)
        {
            return nextNode->getValue();
        }
        else nextNode = nextNode->nextM;
    }
    return 0;
}

unsigned int HashMap::setValue(string key)
{
    unsigned long hash = this->hashFunction(key, this->lengthM);
    if (this->hashNodes[hash] == NULL)
    {
        this->hashNodes[hash] = new HashEntry(key);
        return 1;   // first occurance
    }
    else 
    {
        HashEntry* nextNode = this->hashNodes[hash];
        while (nextNode != NULL) 
        {
            if (nextNode->getKey().compare(key) == 0)
            {
                nextNode->incrementCounter();
                return nextNode->getValue();
            }
            if (nextNode->nextM == NULL)
            {
                nextNode->nextM = new HashEntry(key);
                return 1;   // first occurance
            }
            else nextNode = nextNode->nextM;
        }
    }
}

void HashMap::sortHash(unsigned int size, MostRepeatedWord* words)
{
    for (int i = 0; i < size; i++) 
    {
        words[i].occurance = 0;
        words[i].word = "";
    }

    // every hash root
    for (int i = 0; i < this->lengthM; i++)
    {
        HashEntry* node = this->hashNodes[i];
        // every 'collided' node
        while(node != NULL) 
        {
            for (int j = 0; j < size; j++) 
            {
                if (node->getValue() > words[j].occurance) 
                {
                    // this loop offsets the remaining most frequent words to the right
                    for (int k = size - 1; k > j; k--) 
                    {
                        words[k].occurance = words[k - 1].occurance;
                        words[k].word = words[k - 1].word;
                    }
                    // afterwards, add the frequent word in place
                    words[j].occurance = node->getValue();
                    words[j].word = node->getKey();
                    break;
                }
            }
            if (node->nextM != NULL) node = node->nextM;
            else break;
        }
    }
}

