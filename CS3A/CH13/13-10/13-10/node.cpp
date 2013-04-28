#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;


node::node()
{
    data=0;
    next=NULL;
}

node::node(int num)
{
    data=num;
    next=NULL;
}

node::node(const node& a)
{
    data = a.data;
    next = NULL;
}

node::~node()
{
    if(next!=NULL)
        delete next;
    next = NULL;
}

/*******************
  Name: =
  Arguments: a node
  Returns node
  Description: assignment operator
  Notes: not too bad
  *******************/
node& node::operator =(const node& a)
{
    data = a.data;
    next = NULL;

    return *this;
}

/*******************
  Name: !=
  Arguments: a node
  Returns node
  Description: not equals
  Notes: not too bad
  *******************/
bool operator !=(const node& a, const node& b)
{
    if(a.data != b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: <
  Arguments: a node
  Returns node
  Description: less than
  Notes: not too bad
  *******************/
bool operator <(const node& a, const node& b)
{
    if(a.data < b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: <=
  Arguments: a node
  Returns node
  Description: less than/equals
  Notes: not too bad
  *******************/
bool operator <=(const node& a, const node& b)
{
    if(a.data <= b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: <<
  Arguments: a node
  Returns ostream
  Description: outputs a node
  Notes: not too bad
  *******************/
ostream &operator <<(ostream& out, const node& A)
{
    out << A.data;
    return out;
}

/*******************
  Name: ==
  Arguments: a node
  Returns node
  Description: equivalent check
  Notes: not too bad
  *******************/
bool operator ==(const node &a, const node &b)
{
    if(a.data == b.data)
        return 1;
    else
        return 0;
}

/*******************
  Name: >=
  Arguments: a node
  Returns node
  Description: greaterthan/equal
  Notes: not too bad
  *******************/
bool operator >=(const node &a, const node &b)
{
    if(a.data >= b.data)
        return 1;
    else
        return 0;
}

node operator +(const node &a, const node &b)
{
    return(node(a.data+b.data));
}

node operator -(const node &a, const node &b)
{
    return(node(a.data-b.data));
}

node operator *(const node &a, const node &b)
{
    return(node(a.data*b.data));
}

node operator /(const node &a, const node &b)
{
    return(node(a.data/b.data));
}

