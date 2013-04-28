#ifndef RPN_H
#define RPN_H
#include "node.h"

class rpn
{
public:
    rpn();//default constructor
    rpn(const rpn& copyThis);//copy constructor
    ~rpn();//destructor
    rpn& operator =(const rpn& a);//assignement operator

    void Push(node* pushThis);//insert head
    node* Pop();//remove head;
    bool Empty();//bool empthy

    void calculate(char operation);//calculates the stack
    void Append(node *insertThis);//apppends

private:
    node* head;
    node* cursor;

};

#endif // RPN_H
