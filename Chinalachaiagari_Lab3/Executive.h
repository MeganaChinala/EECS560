#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Hash.h"
#include "Restaurant.h"

#include <iostream>
#include <fstream>

using namespace std;

class Executive
{
private:
  Hash hashT;

  public:
    Executive(string inputFile);
    void optionList();
    ~Executive();
};
#endif
