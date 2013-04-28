#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;


node::node()//default constructor
{
    room='z';
    north=NULL;
    south = NULL;
    east = NULL;
    west = NULL;
}

node::node(char ch)//one argument
{
    room=ch;
    north=NULL;
    south = NULL;
    east = NULL;
    west = NULL;
}

node::node(const node& a)//copy constructor
{
    room = a.room;
    north=NULL;
    south = NULL;
    east = NULL;
    west = NULL;
}

node::~node()//destructor
{
    if(north !=NULL && south != NULL && east != NULL && west != NULL )
    {
        delete north;
        delete south;
        delete east;
        delete west;
    }
    north=NULL;
    south = NULL;
    east = NULL;
    west = NULL;
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
    room = a.room;
    north=NULL;
    south = NULL;
    east = NULL;
    west = NULL;

    return *this;
}
/*******************
  Name: <<
  Arguments: a node, ostream
  Returns ostream
  Description: outputs a node;
  Notes: not too bad
  *******************/
ostream &operator <<(ostream& out, const node& A)
{
    out << A.room;
    return out;
}



