#include "Executive.h"

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <fstream>
#include <iomanip>

using namespace std;

Executive::Executive(string inputFile)
{
  string data = "\0";
  ifstream inFile;
  int menuOption;
  int optionsInFile = 0;

  inFile.open(inputFile);
  if (inFile.is_open())
  {
    while(getline(inFile, data))
    {
      optionsInFile ++;
    }
  }
  else
  {
    cout << "File not opened" << endl << endl;
  }
  inFile.close();

  inFile.open(inputFile);
  if (inFile.is_open())
  {
    int ignore;
    string infoInput;

    int rating;
    string pricing;
    string naming;

    for (int i = 0; i < optionsInFile; i++)
    {
      inFile >> infoInput;
      ignore = infoInput.find(',');
      naming = infoInput.substr(0, ignore);
      inFile >> infoInput;
      ignore = infoInput.find(',');
      rating = stoi(infoInput.substr(0, ignore));
      inFile >> infoInput;
      ignore = infoInput.find(',');
      pricing = infoInput.substr(0, ignore);
      hashT.Add(naming, rating, pricing);
    }
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  inFile.close();

  optionList();

  cout << "What would you like to do: ";
  cin >> menuOption;

  if((cin.fail()) || (menuOption >= 7) || (menuOption <= 0)) //makes sure user does not enter incorrect input
  {
    cout << "Not a valid menu option. Try again\n";
    optionList();
  }

  while(menuOption != 7)
  {
    if(menuOption == 1)
    {
      string toInsert;
      string rest;
      string pricing;
      int rating;

      string def;

      int parameters = 0;

      istringstream strStre;

      cout << endl;
      cout << "Enter restaurant information (format: \"restaurantName, rating, price\")";
      cin >> rest;
      parameters ++;
      getline(cin, toInsert);
      strStre.str(toInsert);
      while (strStre >> def)
      {
        if (parameters == 1)
        {
          rating = stoi(def);
          while ((cin.fail()) || (rating > 5) || (rating < 1))
          {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ratings only from 1 (alright) to 5 (Best)\n";
            cin >> rating;
          }
          parameters ++;
        }
        else if (parameters == 2)
        {
          pricing = def;
          parameters ++;
        }
        else
        {
          parameters ++;
        }
      }
      if (parameters == 3)
      {
        hashT.Add(rest, rating, pricing);
      }
      else if((parameters == 1) || (parameters == 2))
      {
        cout << "Insert all components of restaurant information\n";
      }
      else
      {
        cout << "Check to see if only name, rating, and price added\n";
      }
    }

    if (menuOption == 2)
    {
      string toDelete;
      cout << "Which restaurant would you like to remove: ";
      cin >> toDelete;
      while (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again: "<< endl << endl;
        cout << "Which restaurant would you like to remove: ";
        cin >> toDelete;
      }
      hashT.Remove(toDelete);
      cout << endl;
    }

    if (menuOption == 3)
    {
      string nameF;
      cout << "Enter restaurant name to search: ";
      cin >> nameF;
      while (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again: "<< endl << endl;
        cout << "Which restaurant are we searching for: ";
        cin >> nameF;
      }
      hashT.findN(nameF);
      cout << endl;
    }

    if (menuOption == 4)
    {
      int rateF;
      cout << "Enter rating (between 1-5) to find all restaurants with that rating: ";
      cin >> rateF;
      while ((cin.fail()) || (rateF > 5) || (rateF < 1))
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Is the number 1-5\n";
        cout << "Enter rating again: ";
        cin >> rateF;
      }
      hashT.findR(rateF);
      cout << endl;
    }

    if (menuOption == 5)
    {
      string priceF;
      cout << "Enter price to find restaurants with similar pricing ($, $$, $$$)";
      cin >> priceF;
      while (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Check number of dollar signs\n";
        cout << "Try again and enter price: ";
        cin >> priceF;
      }
      hashT.findP(priceF);
      cout << endl;
    }

    if (menuOption == 6)
    {
      hashT.Print();
      cout << endl;
    }

    optionList();

    cout << "What would you like to do: ";
    cin >> menuOption;
    while((cin.fail()) || (menuOption <= 0) || (menuOption > 7))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Not a menu option";
      optionList();
      cout << "What would you like to do: ";
      cin >> menuOption;
    }
  }
}

void Executive::optionList()
{
  cout << endl;
  cout << " -------------------------------------------------------------------\n";
  cout << " -------------------------------------------------------------------\n";
  cout << "1: Insert\n";
  cout << "2: Delete\n";
  cout << "3: Find by Name\n";
  cout << "4: Find by Rating\n";
  cout << "5: Search by Price\n";
  cout << "6: Print\n";
  cout << "7: Exit \n";
  cout << " -------------------------------------------------------------------\n";
  cout << " -------------------------------------------------------------------\n";
  cout << endl;
}

Executive::~Executive()
{
}
