#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "LinkedList.h"

#include <iostream>
#include <fstream>


using namespace std;

class Executive
{
private:
  LinkedList<int> intValues;
  public:

    Executive(string inputFile);
    ~Executive();

    void menu();
};
#endif
