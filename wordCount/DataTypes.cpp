#include "DataTypes.h"

template <class K, class V>
HashEntry<K,V>::HashEntry(K key, V value)
{
    this->keyM = key;
    this->valueM = value;
    this->nextM = NULL;
}


template <class K, class V>
K HashEntry<K,V>::getKey()
{
    return this->keyM;
}

template <class K, class V>
V HashEntry<K,V>::getValue()
{
    return this->valueM;
}

template <class K, class V>
HashEntry<K,V>* HashEntry<K,V>::getNext()
{
    return nextM;
}

template <class K, class V>
HashMap<K,V>::HashMap(int maxLength)
{
    lengthM = maxLength;
    hashNodes = new HashEntry<K,V>*[maxLength];
    for (int i = 0; i < maxLength; i++) hashNodes[i] = NULL;
}

template <class K, class V>
HashMap<K,V>::~HashMap<K,V>()
{
    for (int i = 0; i < this->getLength(); i++)
    {
        HashEntry<K,V>* node = hashNodes[i];
        while(node != NULL)
        {
            HashEntry<K,V>* previous = node;
            node = node->getNext();
            delete previous;
        }
    }
    delete[] hashNodes;
}

template <class K, class V>
int HashMap<K,V>::getLength()
{
    return lengthM;
}

template <class K, class V>
unsigned long
HashMap<K,V>::hashFunction(string word)
{
    unsigned long hash = 5381;
    int c;
    const char* str = word.c_str();

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

/*template <class K, class V>
int HashMap<K,V>::hashFunction(string key, int hashSize)
{
  int intLength = key.length() / 4;
  double sum = 0;
  for (int j = 0; j < intLength; j++) 
  {
    char c[1024];
    strncpy(key.substr(j * 4, (j * 4) + 4).c_str(), c, 1024);
    int stringSize = key.length();
    long mult = 1;
    for (int k = 0; k < stringSize; k++) 
    {
      sum += c[k] * mult;
      mult *= 256;
    }
  }

  char c[] = key.substr(intLength * 4).c_str();
  long mult = 1;
  int stringSize = key.length();
  for (int k = 0; k < stringSize; k++) {
    sum += c[k] * mult;
    mult *= 256;
  }

  return((int) abs(sum) % hashSize);
}
*/

template <class K, class V>
V HashMap<K,V>::getValue(K key)
{

}

template <class K, class V>
void HashMap<K,V>::setValue(K key, V value)
{
    unsigned long hash = this->hashFunction((string) key);
    if (this->hashNodes[hash] == NULL)
        this->hashNodes[hash] = new HashEntry<K,V>(key, value);
    else 
    {
        HashEntry<K,V>* nextNode = this->hashNodes[hash];
        while (nextNode.getNext() != NULL) nextNode = nextNode->getNext();
        nextNode->nextM = new HashEntry<K,V>(key, value);
    }
}

int main(int argc, char* argv[])
{
  HashEntry<string, int> paco = HashEntry<string, int>("paco", 2);
  HashMap<string, int> pepe = HashMap<string, int>(MAX_LENGTH);
  cout << "Key: " << paco.getKey() << "; Value: " << paco.getValue() << endl;

  pepe.setValue("pixas", 1010);
}
