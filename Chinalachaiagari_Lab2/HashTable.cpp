#include <iostream>

#include "HashTable.h"

using namespace std;

HashTable::HashTable(int stringInside)
{
  m_stringsAdded = 0;
  int incrementer = stringInside + 1;
  while(!isPrime(incrementer))
  {
    incrementer ++;
  }
  m_numberInLL = incrementer;
  m_LL = new LinkedList[m_numberInLL];
}

int HashTable::hashFunction(string entry)
{
  int bucket = 0;
  int stringCount = lenLL(entry);
  for (int i = 0; i < stringCount; i++)
  {
    bucket = bucket + int(entry[i]);
  }
  return(bucket%m_numberInLL);
}

int HashTable::hashFunction(string entry, int addedEntry)
{
  int bucket = 0;
  int stringCount = lenLL(entry);
  for (int i = 0; i < stringCount; i++)
  {
    bucket = bucket + int(entry[i]);
  }
  return(bucket%addedEntry);
}

void HashTable::rehash()
{
  int hashB2 = (m_numberInLL * 2) + 1;
  while(!isPrime(hashB2))
  {
    hashB2++;
  }
  LinkedList* B2Table = new LinkedList[hashB2];
  string stringT = "";
  for (int i = 0; i < m_numberInLL; i++)
  {
    while (!m_LL[i].isEmpty())
    {
      stringT = m_LL[i].getFront() -> getEntry();
      B2Table[hashFunction(stringT, hashB2)].insert(stringT);
      m_LL[i].remove(stringT);
    }
  }
  delete[] m_LL;
  m_numberInLL = hashB2;
  m_LL = B2Table;
  cout << "hash table is rehashed\n";
  cout << endl;
}

int HashTable::find(string insertingEntry)
{
  int bucket = hashFunction(insertingEntry);
  if (m_LL[bucket].find(insertingEntry))
  {
    return(bucket);
  }
  else
  {
    return(-1);
  }
}

bool HashTable::insert(string entry)
{
  int bucket = hashFunction(entry);
  if (m_LL[bucket].insert(entry))
  {
    m_stringsAdded ++;
    if (m_stringsAdded > m_numberInLL)
    {
      rehash();
    }
    return(true);
  }
  else
  {
    return(false);
  }
}

bool HashTable::remove(string entry)
{
  int bucket = find(entry);
  if (bucket == -1)
  {
    return(false);
  }
  else
  {
    m_LL[bucket].remove(entry);
    m_stringsAdded--;
    return(true);
  }
}

int HashTable::lenLL(string entry)
{
  int bucket = 0;
  while (entry[bucket] != '\0')
  {
    bucket++;
  }
  return(bucket);
}

bool HashTable::isPrime(int checkM)
{
  for (int i = 2; i < checkM; i++)
  {
    if (checkM%i == 0)
    {
      return(false);
    }
  }
  return(true);
}

void HashTable::results()
{
  for (int i = 0; i < m_numberInLL; i++)
  {
    cout << i << ": ";
    m_LL[i].results();
  }
}

HashTable::~HashTable()
{
  delete[] m_LL;
}
