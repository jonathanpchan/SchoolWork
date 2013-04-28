#include "queue.h"

template <class T>
queue<T>::queue()
{
}

template <class T>
Node<T>* queue<T>::Dequeue()
{
    return(LinkedList<T>::Remove());
}

template <class T>
void queue<T>::Enqueue(Node<T>* insertThis)
{
    LinkedList<T>::Append(insertThis);
}
