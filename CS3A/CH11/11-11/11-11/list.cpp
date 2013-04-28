#include "list.h"
#include <iostream>
using namespace std;

List::List()
{
    count = 0;
    MAX = 100;
    list = new double[MAX];
}
List::~List()
{
    delete [] list;
}
List::List(const List &copyThis)
{
    count = copyThis.count;
    MAX = copyThis.MAX;
    for(int i=0; i<count; i++)
    {
        list[i] = copyThis.list[i];
    }
}


/*---------------------------------------------------------------------------------------
 *Name - Show
 *Arguments - none
 *Return values - void function
 *Description - outputs the list
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void List::Show()
{
    for(int i=0; i<count; i++)
    {
        cout << list[i] << ", ";
    }
}

/*---------------------------------------------------------------------------------------
 *Name - GetCount
 *Arguments - none
 *Return values - count
 *Description - returns count
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
int List::GetCount()
{
    return count;
}

/*---------------------------------------------------------------------------------------
 *Name - GetItemAt
 *Arguments - int i
 *Return values - list at [i]
 *Description - gets an item from the list
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
double List::GetItemAt(int i)
{
    if(i>MAX)
        i=MAX;

    return list[i];
}

/*---------------------------------------------------------------------------------------
 *Name - set
 *Arguments - a double
 *Return values - void function
 *Description - puts an item into a list
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void List::Set(double Item)
{
    list[count] = Item;
    count++;
}
/*---------------------------------------------------------------------------------------
 *Name - GetLast
 *Arguments - none
 *Return values - last item on thelist
 *Description - returns the last item on the list
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
double List::GetLast()
{
    return list[count];
}

/*---------------------------------------------------------------------------------------
 *Name - Delete Last
 *Arguments - none
 *Return values - none
 *Description - sets the last item = 0 and decrements count
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void List::DeleteLast()
{
    list[count-1] = 0;
    count--;
}

/*---------------------------------------------------------------------------------------
 *Name - =
 *Arguments -  List
 *Return values - *this
 *Description - overload equal operator.
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
List& List::operator =(const List &copyThis)
{
    count = copyThis.count;
    MAX = copyThis.MAX;
    for(int i=0; i<count; i++)
    {
        list[i] = copyThis.list[i];
    }
    return *this;
}


