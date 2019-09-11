#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <string>

#include "Node.h"
#include "ListInterface.h"

using namespace std;

template <class T>
class LinkedList : public ListInterface<T>
{
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    int entries;

public:
    LinkedList();
    ~LinkedList();

    void insert(int posNew, const T &eNew);
    void remove(int pos);
    void clear();

    bool isEmpty() const;
    void setEntry(int pos, const T &eNew);
    int getLength() const;
    T getEntry(int pos) const;

    int Smallest();
    int Largest();
    int Average();
    void Delete(int deletion);

    void flop(int node1, int node2);
    void Print();
};

#include "LinkedList.cpp"
#endif
