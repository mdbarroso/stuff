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
    }
    return 0;
}

void HashMap::setValue(string key)
{
    unsigned long hash = this->hashFunction(key, this->lengthM);
    if (this->hashNodes[hash] == NULL)
    {
        this->hashNodes[hash] = new HashEntry(key);
    }
    else 
    {
        HashEntry* nextNode = this->hashNodes[hash];
        while (nextNode != NULL) 
        {
            if (nextNode->getKey().compare(key) == 0)
            {
                nextNode->incrementCounter();
                break;
            }
            nextNode = nextNode->getNext();
        }
        nextNode->nextM = new HashEntry(key);
    }
}

int main(int argc, char* argv[])
{
  HashEntry paco = HashEntry("paco");
  HashMap pepe = HashMap(MAX_LENGTH);

 pepe.setValue("pixas");
 pepe.setValue("pixas");
 pepe.setValue("pixas");
 pepe.setValue("pixas");
 pepe.setValue("xas");
 pepe.setValue("pixas");
 pepe.setValue("xas");
 pepe.setValue("pixas");
 pepe.setValue("xas");

 cout << "Value: " << pepe.getValue("pixas") << endl;
 cout << "Value: " << pepe.getValue("xas") << endl;
}
