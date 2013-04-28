#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include <ctime>

class queue
{
public:
    queue();
    queue(const queue &copyThis);
    ~queue();

    node* Search(node *findThis);
    node* Remove(node *removeThis);
    node* Previous(node *findThis);
    node* Dequeue();

    void Append(node *insertThis);
    void InsertHead(node *insertThis);

    bool Empty();

    long Time();
    int getTicket();
    long getTime();



private:
    node* head;
    node* rear;
    node* cursor;
};
#endif // QUEUE_H
