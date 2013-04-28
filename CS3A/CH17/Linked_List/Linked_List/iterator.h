#ifndef ITERATOR_H
#define ITERATOR_H
#include "node.h"
#include "linkedlist.h"

template<class T>
class LinkedList;

template<class T>
class Node;

template<class T>
class Iterator
{

public:
    friend class LinkedList<T>;
    friend class Node<T>;
    Iterator();
//    Iterator(const Iterator& copyThis);
//    Iterator<T>& operator =(const Iterator<T>& a);
//    ~Iterator();
    Iterator(Node<T>* n, const LinkedList<T>* l);

    Node<T>* GetNode() const;
    Node<T>* GetNext() const;
    Node<T>* GetPrev();
    Node<T>* GetFirst();
    Node<T>* GetRear();


    void Next();
    void Prev();
//    bool GoNext();
      bool GoPrev();
//    bool GoFirst();
//    bool GoLast();

    template <class U>
    friend ostream &operator <<(ostream& out, const Iterator<U>& a);//output
private:
    Node<T>* ptr;
    const LinkedList<T>* list;
};

#endif // ITERATOR_H
