#ifndef node_H
#define node_H
#include <iostream>

using namespace std;

class node
{
public:
    node();//default constructor
    node(char ch);//one argument constructor
    node(const node& a);//copy constructor
    ~node();//destructor
    node& operator =(const node& a);//assignment operator
//    friend bool operator !=(const node& a, const node& b);// not equals
//    friend bool operator ==(const node& a, const node& b);//equals
//    friend bool operator <(const node& a, const node& b);//less than
//    friend bool operator <=(const node& a, const node& b);//less than equal
//    friend bool operator >=(const node& a, const node& b);//greater than equal
    friend ostream &operator <<(ostream& out, const node& A);//output
//    node* next() {return next;}
//    void next(node* n)

    node* north;
    node* south;
    node* east;
    node* west;
    char room;
};

#endif // node_H

