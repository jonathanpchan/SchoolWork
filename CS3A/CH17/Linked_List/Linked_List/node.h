#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

template <class T>
class LinkedList;
template <class T>
class Iterator;

template <class T>
class Node
{
    friend class LinkedList<T>;
    friend class Iterator<T>;
public:
    Node();//default constructor
    Node(T Data);//one argument constructor
    Node(const Node<T>& a);//copy constructor
    ~Node();//destructor

    Node<T>& operator =(const Node<T>& a);//assignment operator
    template <class U>
    friend bool operator !=(const Node<U>& a, const Node<U>& b);// not equals
    template <class U>
    friend bool operator ==(const Node<U>& a, const Node<U>& b);//equals
    template <class U>
    friend bool operator <(const Node<U>& a, const Node<U>& b);//less than
    template <class U>
    friend bool operator <=(const Node<U>& a, const Node<U>& b);//less than equal
    template <class U>
    friend bool operator >=(const Node<U>& a, const Node<U>& b);//greater than equal
    template <class U>
    friend ostream &operator <<(ostream& out, const Node<U>& A);//output


    template<class U>
    friend Node<U> operator +(const Node<U> &a, const Node<U> &b); //adds 2 polyTerms
    template<class U>
    friend Node<U> operator -(const Node<U> &a, const Node<U> &b); //subtracts 2 polyTerms
    template<class U>
    friend Node<U> operator *(const Node<U> &a, const Node<U> &b); //multiplies 2 polyTerms
    template<class U>
    friend Node<U> operator -(const Node<U> &a); //negates a polyTerm

    Node<T>* Copy() const;
    T GetData();

private:
    Node<T>* next;
    Node<T>* prev;
    T data;

};
#endif // NODE_H
