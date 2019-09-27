#include "Executive.h"
#include <iostream>
#include <string>

using namespace std;

Executive::Executive(HashTable* hashB)
{
  m_hashB = hashB;
}

void Executive::run()
{
  cout << endl << endl;
  int menuChoice = 0;
  string toRemove = "";
  string newString = "";
  string toFind = "";
  int bucketFound = -1;
  do
  {
    cout << "-----------------------------------------" << endl;
    cout << "Please choose one of the following commands:\n";
    cout << "1) Insert\n";
    cout << "2) Delete\n";
    cout << "3) Find\n";
    cout << "4) Print\n";
    cout << "5) Exit\n\n";
    cout << "Menu Option (number only please): ";
    cin >> menuChoice;
    if(menuChoice > 5 || menuChoice < 1)
    {
      cout << "please select a valid option\n";
    }
    if(menuChoice == 1)
    {
      cout << "Enter string to insert (no spaces and only lowercase) ";
      cin >> newString;
      if (m_hashB -> insert(newString))
      {
        cout << '\'' << newString << "\' is added to the hash table\n";
      }
      else
      {
        cout << "Can not insert " << newString << ", no spaces, only lowercase, maybe already in the table?.\n";
      }
    }
    else if (menuChoice == 2)
    {
      cout << "Enter an element to be removed: ";
      cin >> toRemove;
      if (m_hashB->remove(toRemove))
      {
        cout << '\'' << toRemove << "\' is remeoved from the hash table\n";
      }
      else
      {
        cout << "Can not delete" << toRemove << ", check to see if it is in the list\n";
      }
    }
    else if (menuChoice == 3)
    {
      cout << "Enter an element to be found: ";
      cin >> toFind;
      bucketFound = m_hashB->find(toFind);
      if (bucketFound != -1 )
      {
        cout << '\'' << toFind << "\' is found at location " << bucketFound << endl;
      }
      else
      {
        cout << '\'' << toFind << "\' is not found.\n";
      }
    }
    else if (menuChoice == 4)
    {
      m_hashB -> results();
    }
  }while(menuChoice != 5);
}
