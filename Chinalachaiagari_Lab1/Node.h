#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template <class T>
class Node
{

private:
    Node<T>* m_next;
    Node<T>* m_prev;
    T m_entry;

public:
    Node();
    ~Node();

    Node(const T entry);
    Node(const T entry, Node<T>* nPtr, Node<T>* pPtr);

    Node<T>* getPrevious() const; 
    Node<T>* getNext() const;
    T getItem() const;
    
    void setPrevious(Node<T>* pPtr); 
    void setNext(Node<T>* nPtr);
    void setEntry(const T &entry);
};
#include "Node.cpp"
#endif
