#ifndef QUEUE_H
#define QUEUE_H
class Queue:public LinkedList
{
public:
    EnQ(Node* n);
    Node* DeQ();
};

#endif // QUEUE_H
