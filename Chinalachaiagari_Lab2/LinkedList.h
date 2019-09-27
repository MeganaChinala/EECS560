#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <string>

class LinkedList
{
private:
  Node* m_front;
  int m_contents;

public:
  LinkedList();
  bool isEmpty();
  int hashContent();
  Node* getFront();
  bool find(string inserter);
  bool remove(string entry);
  bool insert(string entry);
  void results();
  ~LinkedList();
};
#endif
