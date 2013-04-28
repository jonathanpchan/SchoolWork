#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlist.h"

template <class T>
class queue:public LinkedList<T>
{
public:
    queue();
    Node<T>* Dequeue();
    void Enqueue(Node<T>* insertThis);
};

#endif // QUEUE_H
