#ifndef node_H
#define node_H
#include <iostream>

using namespace std;

class node
{
public:
    node();
    node(int Coef);
    node(int Coef, int Exp);
    node(const node &copyThis);
    ~node();
    node& operator =(const node& a);


    friend bool operator !=(const node& a, const node& b);// not equals
    friend bool operator ==(const node& a, const node& b);//equals
    friend bool operator <(const node& a, const node& b);//less than
    friend bool operator <=(const node& a, const node& b);//less than equal
    friend bool operator >=(const node& a, const node& b);//greater than equal
    friend ostream &operator <<(ostream& out, const node& A);//output


    node* next;
    int exponent;
    int coefficent;



};

#endif // node_H
