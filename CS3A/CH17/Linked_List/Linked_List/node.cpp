#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
Node<T>::Node()
{
    next=NULL;
    prev=NULL;
}

template<class T>
Node<T>::Node(T Data)
{
    data=Data;
    next=NULL;
    prev=NULL;
}

template<class T>
Node<T>::Node(const Node& a)
{
    data = a.data;
    next = NULL;
    prev=NULL;
}

template<class T>
Node<T>::~Node()
{
    if(next!=NULL)
        delete next;
    next = NULL;
}

/*******************
  Name: =
  Arguments: a node
  Returns node
  Description: assignment operator
  Notes: not too bad
  *******************/
template<class T>
Node<T>& Node<T>::operator =(const Node<T>& a)
{
    data = a.data;
    next = NULL;
    prev = NULL;

    return *this;
}



/*******************
  Name: !=
  Arguments: a node
  Returns node
  Description: not equals
  Notes: not too bad
  *******************/
template<class T>
bool operator !=(const Node<T>& a, const Node<T>& b)
{
    if(a.data != b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: <
  Arguments: a node
  Returns node
  Description: less than
  Notes: not too bad
  *******************/
template<class T>
bool operator <(const Node<T>& a, const Node<T>& b)
{
    if(a.data < b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: <=
  Arguments: a node
  Returns node
  Description: less than/equals
  Notes: not too bad
  *******************/
template<class T>
bool operator <=(const Node<T>& a, const Node<T>& b)
{
    if(a.data <= b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: <<
  Arguments: a node
  Returns ostream
  Description: outputs a node
  Notes: not too bad
  *******************/
template<class T>
ostream &operator <<(ostream& out, const Node<T>& A)
{
    out << A.data;
    return out;
}

/*******************
  Name: ==
  Arguments: a node
  Returns node
  Description: equivalent check
  Notes: not too bad
  *******************/
template<class T>
bool operator ==(const Node<T> &a, const Node<T> &b)
{
    if(a.data == b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: >=
  Arguments: a node
  Returns node
  Description: greaterthan/equal
  Notes: not too bad
  *******************/
template<class T>
bool operator >=(const Node<T> &a, const Node<T> &b)
{
    if(a.data >= b.data)
        return 1;
    else
        return 0;
}

template <class T>
Node<T> *Node<T>::Copy() const
{
    Node<T>* temp = new Node<T>(*this);
    return temp;

}

template <class T>
T Node<T>::GetData()
{
    return data;
}

template <class T>
Node<T> operator +(const Node<T> &a, const Node<T> &b)
{
    Node<T> N;

    if(a.data == b.data)
    {
        N.data = a.data + b.data;
    }
    return N;

}

template <class T>
Node<T> operator -(const Node<T> &a, const Node<T> &b)
{
    Node<T> N;

    if(a.data == b.data)
    {
        N.data = a.data - b.data;
    }
    return N;

}

template <class T>
Node<T> operator *(const Node<T> &a, const Node<T> &b)
{
    Node<T> N;

    if(a.data == b.data)
    {
        N.data = a.data * b.data;
    }
    return N;

}

template <class T>
Node<T> operator -(const Node<T> &a)
{
    Node<T> N;

    N.data = a.data;

    return -N.data;

}
