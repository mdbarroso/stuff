#include "DataTypes.h"

HashEntry::HashEntry(string key)
{
    this->keyM = key;
    this->valueM = 1;
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


HashEntry* HashEntry::getNext()
{
    return nextM;
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
            node = node->getNext();
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
        else nextNode = nextNode->getNext();
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
            if (nextNode->getNext() == NULL)
            {
                nextNode->nextM = new HashEntry(key);
                return 1;   // first occurance
            }
            else nextNode = nextNode->getNext();
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

    for (int i = 0; i < this->lengthM; i++)
    {
        HashEntry* node = this->hashNodes[i];
        while(node != NULL) 
        {
            for (int j = 0; j < size; j++) 
            {
                if (node->getValue() > words[j].occurance) 
                {
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

