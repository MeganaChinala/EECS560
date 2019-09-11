template<class T>
Node<T>::Node()
{
  m_next = nullptr;
  m_prev = nullptr;
  m_entry = 0;
}

template <class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>::Node(const T entry)
{
  m_entry = entry;
  m_next = nullptr;
  m_prev = nullptr;
}

template<class T>
Node<T>::Node(const T entry, Node<T>* nPtr, Node<T>* pPtr)
{
  m_entry = entry;
  m_next = nPtr;
  m_prev = pPtr;
}

template <class T>
Node<T> *Node<T>::getPrevious() const
{
    return (m_prev);
}

template <class T>
Node<T> *Node<T>::getNext() const
{
    return (m_next);
}

template <class T>
T Node<T>::getItem() const
{
    return (m_entry);
}

template <class T>
void Node<T>::setPrevious(Node<T> *pPtr)
{
    m_prev = pPtr;
}

template<class T>
void Node<T>::setNext(Node<T>* nPtr)
{
  m_next = nPtr;
}

template <class T>
void Node<T>::setEntry(const T &entry)
{
    m_entry = entry;
}

