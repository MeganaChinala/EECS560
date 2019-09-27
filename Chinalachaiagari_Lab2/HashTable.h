#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "LinkedList.h"

class HashTable
{
private:
  int m_numberInLL;
  int m_stringsAdded;
  LinkedList* m_LL;

public:
  HashTable(int stringInside);
  int hashFunction(string entry);
  int hashFunction(string entry, int addedEntry);
  void rehash();
  int find(string insertingEntry);
  bool insert(string entry);
  bool remove(string entry);
  int lenLL(string entry);
  bool isPrime(int checkM);
  void results();
  ~HashTable();
};
#endif
