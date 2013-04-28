#include "stack.h"

template <class T>
stack<T>::stack()
{
}

template <class T>
void stack<T>::Pop()
{
    this->Remove();
}
template <class T>
void stack<T>::Push(Node<T>* insertThis)
{
    this->InsertHead(insertThis);
}
