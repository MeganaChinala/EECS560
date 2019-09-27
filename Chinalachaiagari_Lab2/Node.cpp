#include "Node.h"
#include <string>

using namespace std;

Node::Node(string entry)
{
    m_entry = entry;
}

void Node::setNext(Node* next)
{
    m_nPtr = next;
}

Node* Node::getNext()
{
    return m_nPtr;
}

string Node::getEntry()
{
    return m_entry;
}
