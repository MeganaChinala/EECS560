#include "Executive.h"

#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

Executive::~Executive()
{
  intValues.clear();
}

void Executive::menu()
{
  cout << endl;
  cout << "Welcome, choose your task:\n\n";
  cout << "1. Insert\n";
  cout << "2. Delete\n";
  cout << "3. Find smallest number\n";
  cout << "4. Find largest number\n";
  cout << "5. Average of numbers\n";
  cout << "6. Merge2Lists\n";
  cout << "7. Print\n";
  cout << "8. ReverseList\n";
  cout << "9. Exit\n";
}

Executive::Executive(string inputFile)
{
  int valuesFromFile;
  int menuOption;
  ifstream inFile;
  inFile.open(inputFile);
  if(inFile.is_open())
  {
    int takenIn = 1;
    while(true)
    {
      if(inFile.eof())
      {
        break;
      }
      inFile >> valuesFromFile;
      intValues.insert(takenIn, valuesFromFile);
      takenIn++;
    }
  }
  else
  {
    cout << "File error";
  }
  menu();
  cin >> menuOption;
  while (menuOption > 9 || menuOption < 1 || cin.fail())
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Not a Menu Choice\n" << '\n';
    menu();
    cin >> menuOption;
  }
  do
  {
    if (menuOption == 1)
    {
      int listAdd;
      int pos=intValues.getLength();
      cout << "Enter element to be inserted in list: ";
      cin >> listAdd;
      cout << '\n';
      intValues.insert(pos,listAdd);
    }
    else if(menuOption == 2)
    {
      int listRemove;
      cout << "Enter number to be deleted: ";
      cin >> listRemove;
      while (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Possibly not in list\n";
        cout << "Enter number to be deleted: ";
        cin >> listRemove;
      }
      intValues.Delete(listRemove);
    }
    else if(menuOption == 3)
    {
      if (intValues.isEmpty())
      {
        cout << "Nothing here\n";
      }
      else
      {
        cout << "Smallest Number: " << intValues.Smallest() << endl;
      }
    }
    else if(menuOption == 4)
    {
      if (intValues.isEmpty())
      {
        cout << "Nothing here\n";
      }
      else
      {
        cout << "Largest Number: " << intValues.Largest() << endl;
      }
    }
    else if (menuOption == 5)
    {
      if (intValues.isEmpty())
      {
        cout << "Nothing here\n";
      }
      else
      {
        cout << "Average: " << intValues.Average() << endl;
      }
    }
    else if(menuOption == 6)
    {
      string newList=" ";
      int issueWithOne;
      int newValue;
      istringstream iss;
      cout << "Enter new list to be merged: \n";
      cin >> issueWithOne;
      getline(cin, newList);
      iss.str(newList);
      intValues.insert(1,issueWithOne);
      while (iss >> newValue)
      {
        intValues.insert(1, newValue);
      }
      for (int i = 1; i <= intValues.getLength() - 1; i++)
      {
        for (int j = 1; j <= intValues.getLength() - i - 1; j++)
        {
          if (intValues.getEntry(j) > intValues.getEntry(j + 1))
          {
            intValues.flop(j,(j + 1));
          }
        }
      }
      cout << "Merged List: ";
      for (int i = 1; i <= intValues.getLength(); i++)
      {
        cout  << intValues.getEntry(i) << ' ';
      }
    }
    else if(menuOption == 7)
    {
      cout << endl;
      intValues.Print();
    }
    if(menuOption == 8)
    {
      LinkedList<int> reversal;
      for (int i = 1; i <= intValues.getLength(); i++)
      {
        reversal.insert(1, intValues.getEntry(i));
      }
      intValues.clear();
      for(int i = 1; i <= reversal.getLength(); i++)
      {
        intValues.insert(i,reversal.getEntry(i));
      }
      reversal.clear();
      cout << endl;
      cout << "List: ";
      for (int i = 1; i <= intValues.getLength(); i++)
      {
        cout  << intValues.getEntry(i) << ' ';
      }
    }
    cout  << '\n';
    menu();
    cin >> menuOption;
  }while (menuOption != 9);
}
