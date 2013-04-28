#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"

template <class T>
class stack:public LinkedList<T>
{
public:
    stack();
    void Pop();
    void Push(Node<T>* insertThis);
};

#endif // STACK_H
