#include <iostream>
#include <string>
#include <sstream>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
  m_contents = 0;
  m_front = nullptr;
}

bool LinkedList::isEmpty()
{
  if(m_contents == 0)
  {
    return(true);
  }
  else
  {
    return (false);
  }
}

int LinkedList::hashContent()
{
  return(m_contents);
}

Node* LinkedList::getFront()
{
  return(m_front);
}

bool LinkedList::find(string inserter)
{
  Node* check = m_front;
  for(int i = 0; i < m_contents; i++)
  {
    if(check -> getEntry() == inserter)
    {
      return(true);
    }
    else
    {
      check = check -> getNext();
    }
  }
  return(false);
}

bool LinkedList::remove(string entry)
{
  Node* front = m_front;
  Node* back = nullptr;
  int size = 0;
  for(int i = 0; i < m_contents; i++)
  {
    if(front -> getEntry() == entry)
    {
      if(size == 0)
      {
        m_front = m_front -> getNext();
      }
      else if(size == 1)
      {
        m_front = nullptr;
      }
      else
      {
        back -> setNext(front -> getNext());
      }
      delete front;
      m_contents--;
      return(true);
    }
    size++;
    back = front;
    front = front -> getNext();
  }
  return(false);
}

bool LinkedList::insert(string entry)
{
  Node* check = m_front;
  for(int i = 0; i < m_contents; i++)
  {
    if(check -> getEntry() == entry)
    {
      return(false);
    }
    else
    {
      check = check -> getNext();
    }
  }
  Node* setting = new Node(entry);
  if(isEmpty() == false)
  {
    setting -> setNext(m_front);
  }
  m_front = setting;
  m_contents++;
  return(true);
}

void LinkedList::results()
{
  if(isEmpty() == true)
  {
    cout << endl << endl;
    return;
  }
  Node* newFront = m_front;
  for(int i = 0; i < m_contents; i++)
  {
    cout << " <--- " << newFront -> getEntry();
    newFront = newFront -> getNext();
  }
  cout << endl << endl;
}

LinkedList::~LinkedList()
{
  Node* front = m_front;
  Node* newF = nullptr;
  while (m_contents != 0)
  {
    newF = front->getNext();
    delete front;
    m_contents --;
    front = newF;
  }
}
