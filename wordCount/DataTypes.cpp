#include "DataTypes.h"

HashEntry::HashEntry(string key)
{
    this->keyM = key;
    this->valueM = 0;
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

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % maxSize;
}

unsigned int HashMap::getValue(string key)
{
    unsigned long hash = this->hashFunction(key, this->lengthM);
//    cout << "hash: " << hash << endl;
    unsigned int value = this->hashNodes[hash]->getValue();
    cout << "Value: " << value << endl;
}

void HashMap::setValue(string key, unsigned int value)
{
    unsigned long hash = this->hashFunction(key, this->lengthM);
//    cout << "aqui?!" << hash <<endl;
    if (this->hashNodes[hash] == NULL)
    {
        this->hashNodes[hash] = new HashEntry(key);
//        cout << "Null: adding at the front of the queue" << endl;
    }
    else 
    {
//        cout << "Collision; advancing pointer" << endl;
        HashEntry* nextNode = this->hashNodes[hash];
        if (nextNode->getKey().compare(key) == 0) nextNode->incrementCounter();
        while (nextNode->getNext() != NULL) 
        {
            if (nextNode->getKey().compare(key) == 0) nextNode->incrementCounter();
            nextNode = nextNode->getNext();
        }
        nextNode->nextM = new HashEntry(key);
    }
}

int main(int argc, char* argv[])
{
  HashEntry paco = HashEntry("paco");
  HashMap pepe = HashMap(MAX_LENGTH);
//  cout << "Key: " << paco.getKey() << "; Value: " << paco.getValue() << endl;

  pepe.setValue("pixas", 0);       pepe.setValue("pixas", 0);
 pepe.setValue("pixas", 0);
 pepe.setValue("pixas", 0);
 pepe.setValue("pixas", 0);
 pepe.setValue("pixas", 0);
 pepe.setValue("pixas", 0);

 pepe.getValue("pixas");

}
