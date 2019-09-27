#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
private:
    string m_entry;
    Node* m_nPtr;

public:
  Node(string entry);
  string getEntry();
  Node* getNext();
  void setNext(Node* next);
};
#endif
