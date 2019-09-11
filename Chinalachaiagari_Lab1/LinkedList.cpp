template<class T>
LinkedList<T>::LinkedList()
{
  m_head = nullptr;
  m_tail = nullptr;
  entries = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
  while (isEmpty() == false)
  {
    Node<T>* deleter = m_head;
    for (int i = 0; i < entries; i++)
    {
      deleter = deleter -> getNext();
    }
    delete deleter;
    entries = entries - 1;
  }
}

template<class T>
void LinkedList<T>::insert(int posNew, const T& eNew)
{
  if ((posNew >= 1) && (posNew <= entries + 1))
  {
    if (posNew == 1)
    {
      Node<T>* insertion = new Node<T>(eNew);
      insertion -> setNext(m_head);
      insertion -> setPrevious(m_head);
      m_head = insertion;
      m_tail = insertion;
    }
    else
    {
      Node<T>* insertion = new Node<T>(eNew);
      Node<T>* backNode = m_head;
      for (int i=1; i < posNew - 1; i++)
      {
        backNode = backNode -> getNext();
      }
      insertion -> setNext(backNode -> getNext());
      backNode -> setNext(insertion);
    }
    while (m_tail -> getNext() != nullptr)
    {
      m_tail = m_tail -> getNext();
    }
    entries = entries + 1;
  }
}

template<class T>
void LinkedList<T>::remove(int pos)
{
  if((pos >= 1) && (pos <= entries))
  {
    Node<T>* removal = nullptr;
    if (pos == 1)
    {
      removal = m_head;
      m_head = m_head -> getNext();
    }
    else
    {
      Node<T>* backNode = m_head;
      for (int i = 1; i < pos - 1; i++)
      {
        backNode = backNode -> getNext();
      }
      removal = backNode -> getNext();
      backNode -> setNext(removal -> getNext());
    }
    removal -> setNext(nullptr);
    delete removal;
    entries = entries - 1;
  }
}

template<class T>
void LinkedList<T>::clear()
{
  while (isEmpty() == false)
  {
    remove(1);
  }
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
  if (entries == 0)
  {
    return (true);
  }
  else
  {
    return (false);
  }
}

template<class T>
void LinkedList<T>::setEntry(int pos, const T& eNew)
{
  if (isEmpty()==false)
  {
    Node<T>* setter = m_head;
    for (int i = 1; i < pos; i++)
    {
      setter = setter -> getNext();
    }
    setter -> setEntry(eNew);
  }
}

template<class T>
int LinkedList<T>::getLength() const
{
  return(entries);
}

template<class T>
T LinkedList<T>::getEntry(int pos) const
  {
    Node<T>* getter = m_head;
    for (int i = 1; i < pos; i++)
    {
      getter = getter -> getNext();
    }
    return (getter -> getItem());
}

template<class T>
int LinkedList<T>::Smallest()
{
  int lValue = getEntry(1);
  if (isEmpty())
  {
    cout << "Nothing here\n";
  }
  else
  {
    for (int i = 1; i <= getLength(); i++)
    {
      if(getEntry(i) < lValue)
      {
        lValue = getEntry(i);
      }
    }
  }
  return(lValue);
}

template<class T>
int LinkedList<T>::Largest()
{
  int gvalue = getEntry(1);
  if (isEmpty())
  {
    cout << "Nothing here\n";
  }
  else
  {
    for (int i = 1; i <= getLength(); i++)
    {
      if(getEntry(i) > gvalue)
      {
        gvalue = getEntry(i);
      }
    }
  }
  return(gvalue);
}

template<class T>
int LinkedList<T>::Average()
{
  int average = 0;
  int total = 0;
  for (int i = 1; i <= getLength(); i++)
  {
    total = total + getEntry(i);
  }
  average = total / getLength();
  return(average);
}

template<class T>
void LinkedList<T>::Delete(int deletion)
{
  int removal = deletion;
  bool numIsThere = false;
  for (int i = 1; i <= getLength(); i++)
  {
    if (getEntry(i) == removal)
    {
      numIsThere = true;
      remove(i);
      cout << "Deleted.\n";
      break;
    }
  }
  if (!numIsThere)
  {
    cout << "Not found.\n";
  }
  cout <<endl;
}

template<class T>
void LinkedList<T>::flop(int node1, int node2)
{
  int n1 = node1;
  int n2 = node2;
  int n1Entry = getEntry(n1);
  int n2Entry = getEntry(n2);
  remove(n2);
  remove(n1);
  insert(n1, n2Entry);
  insert(n2, n1Entry);
}

template<class T>
void LinkedList<T>::Print()
{
  if (isEmpty())
  {
    cout << "Nothing here\n";
  }
  else
  {
    cout << "List: ";
    for (int i=1; i<=(getLength()); i++)
    {
      cout << getEntry(i) << ' ';
    }
    cout << endl;
  }
}
