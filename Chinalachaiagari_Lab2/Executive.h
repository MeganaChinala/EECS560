#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "HashTable.h"

class Executive
{
private:
    HashTable* m_hashB;
public:
  Executive(HashTable* hashB);
  void run();
};
#endif
