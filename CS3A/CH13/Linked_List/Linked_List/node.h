#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node
{
public:
    Node();//default constructor
    Node(int num);//one argument constructor
    Node(const Node& a);//copy constructor
    ~Node();//destructor
    Node& operator =(const Node& a);//assignment operator
    friend bool operator !=(const Node& a, const Node& b);// not equals
    friend bool operator ==(const Node& a, const Node& b);//equals
    friend bool operator <(const Node& a, const Node& b);//less than
    friend bool operator <=(const Node& a, const Node& b);//less than equal
    friend bool operator >=(const Node& a, const Node& b);//greater than equal
    friend ostream &operator <<(ostream& out, const Node& A);//output

//    Node* next() {return next;}
//    void next(Node* n)

    Node* next;
    int data;
};

#endif // NODE_H

