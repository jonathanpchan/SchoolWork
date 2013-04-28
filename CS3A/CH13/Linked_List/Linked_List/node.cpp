#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;


Node::Node()
{
    data=0;
    next=NULL;
}

Node::Node(int num)
{
    data=num;
    next=NULL;
}

Node::Node(const Node& a)
{
    data = a.data;
    next = NULL;
}

Node::~Node()
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
Node& Node::operator =(const Node& a)
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
bool operator !=(const Node& a, const Node& b)
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
bool operator <(const Node& a, const Node& b)
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
bool operator <=(const Node& a, const Node& b)
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
ostream &operator <<(ostream& out, const Node& A)
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
bool operator ==(const Node &a, const Node &b)
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
bool operator >=(const Node &a, const Node &b)
{
    if(a.data >= b.data)
        return 1;
    else
        return 0;
}

