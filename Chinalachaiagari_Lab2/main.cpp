#include <iostream>
#include <fstream>

#include "Executive.h"
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 2 || argc > 2)
  {
    cout << "Check number of parameters\n";
  }
  fstream openTxt;
  openTxt.open(argv[1]);
  string entry;
  int strings = 0;
  if(openTxt.is_open())
  {
    while (openTxt >> entry)
    {
      strings++;
    }
    openTxt.close();
    openTxt.open(argv[1]);
    HashTable* hashB = new HashTable(strings);
    while (openTxt >> entry)
    {
      hashB -> insert(entry);
    }
    openTxt.close();
    cout << endl << "Data has been transferred\n\n";
    Executive runOptions(hashB);
    runOptions.run();
  }
  else
  {
    cout << "file not opened" << endl;
  }
  return(0);
}
