#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include <ctime>

class queue
{
public:
    queue();//default constructor
    queue(const queue &copyThis);//copy constructor
    ~queue();//destructor

    node* Dequeue();//remove from stack

    void Append(node *insertThis);//appends to the list
    void InsertHead(node *insertThis);//inserts a head

    bool Empty();//checks if list is empty

    long Time();//gets the time
    int getTicket();//gets ticket number
    long getTime();//returns the time the customer came in
    long AverageTime(long waitTime);//average time a customer must wait.


private:
    node* head;
    node* rear;
    node* cursor;
    long* average;
};
#endif // QUEUE_H
