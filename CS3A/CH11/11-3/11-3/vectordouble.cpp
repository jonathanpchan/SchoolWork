#include "vectordouble.h"
#include <iostream>
using namespace std;


VectorDouble::VectorDouble()
{
    maxCount=50;
    count = 0;
    doubleArray = new double[maxCount];
}
VectorDouble::VectorDouble(int Count)//number of elements in the intial dynamic array
{
    maxCount=maxCount;
    count = Count;
    doubleArray = new double[maxCount];
}
VectorDouble::VectorDouble(const VectorDouble &copyThis)//copy constructor
{
    maxCount=copyThis.maxCount;
    count = copyThis.count;
    doubleArray = new double[maxCount];
    for(int i=0; i< count; i++)
    {
        doubleArray[i] = copyThis.doubleArray[i];
    }
}

VectorDouble::~VectorDouble()
{
    delete[] doubleArray;
    //cout << "KABOOOM\n";

}


/*---------------------------------------------------------------------------------------
 *Name - set
 *Arguments - a double
 *Return values - void function
 *Description - doubles max size, if count == max count
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void VectorDouble::Set(double num)
{
    if(count==maxCount)
    {
        double* bigger;
        bigger = new double[maxCount*2];

        for(int i = 0; i<count; i++)
        {
            bigger[i] = doubleArray[i];
            //cout << "rewriting\n";
        }

        bigger[count] = num;
        count++;

        doubleArray = bigger;
        maxCount = maxCount*2;

        //cout << "EXPANDED\n";

    }
    else
    {
        doubleArray[count] = num;
        count++;
    }
}

/*---------------------------------------------------------------------------------------
 *Name - GetMax
 *Arguments - none
 *Return values - int max count
 *Description - gets maxcount/capacity
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
int VectorDouble::GetMax()
{
   return maxCount;
}

/*---------------------------------------------------------------------------------------
 *Name - GetCount
 *Arguments - none
 *Return values - int count
 *Description - gets count/size
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
int VectorDouble::GetCount()
{
   return count;
}

/*---------------------------------------------------------------------------------------
 *Name - show
 *Arguments - none
 *Return values - none
 *Description - prints the vectordouble
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void VectorDouble::Show()
{
    int i;
    for(i=0; i<count-1; i++)
    {
        cout << doubleArray[i] << ",";
    }
    cout << doubleArray[i];
}

/*---------------------------------------------------------------------------------------
 *Name - Value
 *Arguments - int i
 *Return values - returns the value at i
 *Description - returns the value at i
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
int VectorDouble::ValueAt(int i)
{
    return doubleArray[i];
}

/*---------------------------------------------------------------------------------------
 *Name - ChangeValueAt
 *Arguments - int num, int i
 *Return values - none
 *Description - changes a number in the vector position i
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void VectorDouble::ChangeValueAt(int num, int i)
{
    if(i>=maxCount)
    {
        i=maxCount;
    }


    doubleArray[i] = num;


}


/*---------------------------------------------------------------------------------------
 *Name - Resize
 *Arguments - int size
 *Return values - none
 *Description - changes the max size based on user input;
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
void VectorDouble::Resize(int size)
{
    if(size <= count)
    {
        size = count;
    }

    double* temp;
    temp = new double[size];
    for(int i = 0; i<count; i++)
    {
        temp[i] = doubleArray[i];
    }
    doubleArray = temp;
    maxCount = size;
}

/*---------------------------------------------------------------------------------------
 *Name - ==
 *Arguments - two VectorDoubles
 *Return values - none
 *Description - checks if two vector doubles are equal to each other.
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
bool operator ==(const VectorDouble &A, const VectorDouble &B)
{
    if(A.count != B.count)
    {
        return 0;
    }
    for(int i=0; i<A.count; i++)
    {
        if(A.doubleArray[i] != B.doubleArray[i])
        {
            return 0;
        }
    }
    return 1;
}
/*---------------------------------------------------------------------------------------
 *Name - =
 *Arguments - VectorDouble
 *Return values - *this
 *Description - overload = operator
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
VectorDouble& VectorDouble::operator =(const VectorDouble &copyThis)
{
    maxCount=copyThis.maxCount;
    count = copyThis.count;
    doubleArray = new double[maxCount];
    for(int i=0; i< count; i++)
    {
        doubleArray[i] = copyThis.doubleArray[i];
    }
    return *this;
}
