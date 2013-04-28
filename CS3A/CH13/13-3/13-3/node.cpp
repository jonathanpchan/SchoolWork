#include "node.h"
#include <cstdlib>

node::node()
{
    coefficent=0;
    exponent=0;
    next = NULL;
}

node::node(int Coef)
{
    coefficent=Coef;
    exponent=0;
    next=NULL;
}

node::node(int Coef, int Exp)
{
    coefficent = Coef;
    exponent = Exp;
    next = NULL;
}

node::node(const node &copyThis)
{
    exponent = copyThis.exponent;
    coefficent = copyThis.coefficent;
    next = NULL;
}

node::~node()
{
    if(next!=NULL)
        delete next;
    next = NULL;
}

node &node::operator =(const node &copyThis)
{
    exponent = copyThis.exponent;
    coefficent = copyThis.coefficent;
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
    if(a.exponent != b.exponent)
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
    if(a.exponent < b.exponent)
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
    if(a.exponent <= b.exponent)
        return 1;
    else
        return 0;
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
    if(a.exponent == b.exponent)
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
    if(a.exponent >= b.exponent)
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


ostream &operator <<(ostream& out, const node& a)
{
//    out << a.coefficenticent<<"x^"<<a.exponent;

   if(a.coefficent==1 && (a.exponent!=0 || a.exponent!=1))
       out<<"x^"<<a.exponent;
   else if(a.coefficent==-1 && (a.exponent!=0 && a.exponent!=1))
       out <<"-x(hi)^"<<a.exponent;
   else if(a.coefficent==-1 && a.exponent==1)
       out <<"-x";
   else if(a.exponent==1)
       out <<a.coefficent<<"x";
   else if(a.exponent==0)
       out<<a.coefficent;
   else
       out<<a.coefficent<<"x^"<<a.exponent;

   return out;
}
