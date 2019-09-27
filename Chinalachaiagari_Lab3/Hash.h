#ifndef HASH_H
#define HASH_H

#include "Restaurant.h"

using namespace std;

class Hash
{
private:
  int tableLength = 31;
  int Rvalue = 29;
  Restaurant* qHash;
  Restaurant* dHash;

  public:
    Hash();
    void Print();
    bool entryInQHash(string alreadyThere);
    bool entryInDHash(string alreadyThere);
    void findP(string givenP);
    void findN(string givenN);
    void findR(int givenR);
    void Remove(string removal);
    void Add(string n, int r, string p);
    int doubleHashPlus(string asciiValues);
    int doubleHashing(string asciiValues);
    ~Hash();
};
#endif
