#include "Hash.h"

#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

Hash::Hash()
{
  qHash = new Restaurant[31];
  dHash = new Restaurant[31];

  for (int i=0; i < tableLength; i++)
  {
    qHash[i].getName()="\0";
    dHash[i].getName()="\0";
  }
}

void Hash::Print()
{
  cout << "Quadratic Probing: " << endl;
  for(int i = 0; i < tableLength; i++)
  {
    if (qHash[i].getRate() == 0)
    {
      cout << i << ": \n";
    }
    else
    {
      cout << i << ": "
      << qHash[i].getName()
      << " " << qHash[i].getRate()
      << " " << qHash[i].getPrice() << endl;
    }
  }
  cout << endl << endl;

  cout << "Double Hashing" << endl;
  for(int i = 0; i < tableLength; i++)
  {
    if (dHash[i].getRate() == 0)
    {
      cout << i << ": \n";
    }
    else
    {
      cout << i << ": "
      << dHash[i].getName()
      << " " << dHash[i].getRate()
      << " " << dHash[i].getPrice() << endl;
    }
  }
}

bool Hash::entryInQHash(string alreadyThere)
{
  bool entryInQHash = false;
  for(int i = 0; i < tableLength; i++)
  {
    if (qHash[i].getName() == alreadyThere)
    {
      entryInQHash = true;
      break;
    }
  }
  return(entryInQHash);
}

bool Hash::entryInDHash(string alreadyThere)
{
  bool entryInDHash = false;
  for(int i = 0; i < tableLength; i++)
  {
    if (dHash[i].getName() == alreadyThere)
    {
      entryInDHash = true;
      break;
    }
  }
  return(entryInDHash);
}

void Hash::findP(string givenP)
{
  string dataD[31];
  int bucketD = 0;

  string dataQ[31];
  int bucketQ = 0;

  for(int i = 0; i < tableLength; i++)
  {
    if (qHash[i].getPrice() == givenP)
    {
      dataQ[bucketQ] = qHash[i].getName();
      bucketQ ++;
    }
    if (dHash[i].getPrice() == givenP)
    {
      dataD[bucketD] = dHash[i].getName();
      bucketD ++;
    }
  }
  if (bucketQ > 0)
  {
    cout << "Quadratic Probing: ";
    for(int i = 0; i < tableLength; i++)
    {
      cout << dataQ[i] << ' ';
    }
    cout << endl;
  }
  else
  {
    cout << givenP << "is not in the Quadratic Probed\n";
  }

  if (bucketD > 0)
  {
    cout << "Double Hashing: ";
    for(int i = 0; i < tableLength; i++)
    {
      cout << dataD[i] << ' ';
    }
    cout << endl;
  }
  else
  {
    cout << givenP << "is not in the Double Hashed\n";
  }
}

void Hash::findN(string givenN)
{
  int bucketD;
  bool entryInDHash = false;

  int bucketQ;
  bool entryInQHash = false;

  for(int i = 0; i < 31; i++)
  {
    if(qHash[i].getName() == givenN)
    {
      entryInQHash = true;
      bucketQ = i;
      break;
    }
  }
  for (int i = 0; i < 31; i++)
  {
    if(dHash[i].getName() == givenN)
    {
      entryInDHash = true;
      bucketD = i;
      break;
    }
  }

  //locations being printed
  if(entryInQHash)
  {
    cout << endl << givenN << " found at location " << bucketQ << " in Quad Table\n";
  }
  else
  {
    cout << endl << givenN << " not found in Quad Table\n";
  }

  if(entryInDHash)
  {
    cout << endl << givenN << " found at location " << bucketD << " in Double Hash Table\n";
  }
  else
  {
    cout << endl << givenN << " not found in Double Hash Table\n";
  }
  cout << endl;
}

void Hash::findR(int givenR)
{
  string dataD[31];
  int bucketD = 0;

  string dataQ[31];
  int bucketQ = 0;

  for(int i = 0; i < 31; i++)
  {
    if (qHash[i].getRate() == givenR)
    {
      dataQ[bucketQ] = qHash[i].getName();
      bucketQ ++;
    }
    if (dHash[i].getRate() == givenR)
    {
      dataD[bucketD] = dHash[i].getName();
      bucketD ++;
    }
  }
  //quadratic probing
  if (bucketQ > 0)
  {
    cout << "Quadratic Probing: ";
    for (int i = 0; i < tableLength; i++)
    {
      cout << dataQ[i] << ' ';
    }
    cout << endl;
  }
  else
  {
    cout << endl << givenR << " not found in Quad Table\n";
  }

  //double hashing
  if (bucketD > 0)
  {
    cout << "Double Hashing: ";
    for (int i = 0; i < tableLength; i++)
    {
      cout << dataD[i] << ' ';
    }
    cout << endl;
  }
  else
  {
    cout << endl << givenR << " not found in Double Hash Table\n";
  }
}

void Hash::Remove(string removal)
{
  bool dGone = false;
  bool qGone = false;

  for(int i = 0; i < 31; i++)
  {
    if(qHash[i].getName() == removal)
    {
      //set to deleted standard as per constructor
      qHash[i].setName("\0");
      qHash[i].setRate(0);
      qHash[i].setPrice("\0");

      qGone = true;

      cout << removal << " is now deleted from Quad Table\n";
    }

    if(dHash[i].getName() == removal)
    {
      //set to deleted standard as per constructor
      dHash[i].setName("\0");
      dHash[i].setRate(0);
      dHash[i].setPrice("\0");

      dGone = true;

      cout << removal << " is now deleted from Double Hash\n";
    }
  }
  if (!dGone)
  {
    cout << removal << " not deleted from Double hash\n";
  }

  if (!qGone)
  {
    cout << removal << " not deleted from Quad Table\n";
  }
}

void Hash::Add(string n, int r, string p)
{
  Restaurant adding;
  adding.setName(n);
  adding.setRate(r);
  adding.setPrice(p);

  int bucketD = doubleHashing(n);
  bool addedD = false;

  int bucketQ = doubleHashing(n);
  bool addedQ = false;

//inserting in quad hash table
  if(!entryInQHash(n))
  {
    for(int i = 0; i < 31; i++)
    {
      if (i < bucketQ)
      {
        continue;
      }
      else if ((qHash[i].getName() == "\0") && (i == bucketQ))
      {
        qHash[i] = adding;
        addedQ = true;
        cout << n << " inserted in bucket " << i << " in Quad hash\n";
        break;
      }
      else
      {
       for(int j = 0; j < 31; j++)
        {
          bucketQ = (doubleHashing(n) + (j * j)) % 31;
          if (qHash[bucketQ].getName() == "\0")
          {
            qHash[bucketQ] = adding;
            addedQ = true;
            cout << n << " inserted in bucket " << bucketQ << " in Quad Hash \n";
            break;
          }
          else
          {
            continue;
          }
        }
        break;
      }
    }
  }
  else
  {
    cout << "Cannot be entered (already exists)\n";
  }

//inserting in double hash
  if(!entryInDHash(n))
  {
    for(int i = 0; i < 31; i++)
    {
      if(i < bucketD)
      {
        continue;
      }
      else if((dHash[i].getName() == "\0") && (i == bucketD))
      {
        dHash[i] = adding;
        addedD = true;
        cout << n << " inserted in bucket " << i << " in double hash table\n";
        break;
      }
      else
      {
        for(int j = 0; j < 31; j++)
        {
          bucketD = (doubleHashing(n) + (j * doubleHashPlus(n))) % 31;
          if (dHash[bucketD].getName() == "\0")
          {
            dHash[bucketD] = adding;
            addedD = true;
            cout << n << " inserted in bucket " << bucketD << " in double hash table\n";
            break;
          }
          else
          {
            continue;
          }
        }
        break;
      }
    }
  }
  else
  {
    cout << "Cannont be entered (already exists).\n";
  }

  if (!addedD)
  {
    cout << n << ": Double hashing insertion failed\n";
  }

  if (!addedQ)
  {
    cout << n << ": Quad Probing insertion failed\n";
  }
}

int Hash::doubleHashPlus(string asciiValues)
{
  int bucketC = 0;
  string component = asciiValues;
  int wordSum = 0;

  while(component[bucketC] != '\0')
  {
    bucketC ++;
  }
  for (int i = 0; i<bucketC; i++)
  {
    wordSum += component[i];
  }
  int index = Rvalue - (wordSum % 29);
  return(index);
}

int Hash::doubleHashing(string asciiValues)
{
  int bucketC = 0;
  string component = asciiValues;
  int wordSum = 0;

  while(component[bucketC] != '\0')
  {
    bucketC ++;
  }
  for (int i = 0; i < bucketC; i++)
  {
    wordSum += component[i];
  }
  int index = wordSum % 31;
  return(index);
}

Hash::~Hash()
{
  delete [] qHash;
  delete [] dHash;
}
