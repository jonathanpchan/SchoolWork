#include "countertype.h"

CounterType::CounterType()//default constructor
{
    counter = 0;
}

CounterType::CounterType(int num)//constructor with terms.
{
    if(num<=0)
        num=0;  //dont let it go negative
    counter = num;
}

/*---------------------------------------------------------------------------------------
 *Name - IncrementCount
 *Arguments - int counter
 *Return values - none, can return int though
 *Description - counts up 1 at a time
 *Notes -2/6/13 - just incrementing
-----------------------------------------------------------------------------------------*/
void CounterType::IncrementCount()
{
    counter++;
}

/*---------------------------------------------------------------------------------------
 *Name - DecrementCount
 *Arguments - counter
 *Return values - none, can return counter
 *Description - counts down, will not count below 0
 *Notes -2/6/13 - just decrementing, prvent going under 0
-----------------------------------------------------------------------------------------*/
void CounterType::DecrementCount()
{
    if(counter>0)
    {
        counter--;
    }
    else if (counter<=0)
    {
        counter=0;
    }
    //else cout cant go negative.
}

/*---------------------------------------------------------------------------------------
 *Name - GetCounter
 *Arguments - counter
 *Return values - counter
 *Description - returns the counter
 *Notes -2/6/13 - easy, just returning the counter for output
-----------------------------------------------------------------------------------------*/
int CounterType::GetCounter()
{
    return counter;
}
