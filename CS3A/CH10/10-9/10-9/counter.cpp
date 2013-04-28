#include "counter.h"
#include <iostream>

using namespace std;

Counter::Counter()//default constructor
{
    counter = 0;
    max=9999;
}

Counter::Counter(int Max)//constructor to set max if needed.
{
    max = Max;
    counter = 0;
}

/*---------------------------------------------------------------------------------------
 *Name - Reset
 *Arguments - int counter
 *Return values - returns counter
 *Description - reset counter to 0;
 *Notes -2/6/13 - simple reset to 0;
-----------------------------------------------------------------------------------------*/
int Counter::Reset()
{
    counter = 0;
    return counter;

}

/*---------------------------------------------------------------------------------------
 *Name - Incr1
 *Arguments - int counter
 *Return values - counter
 *Description - counts up 1 if counter + 1 < max
 *Notes -2/6/13 - simple incrementing
-----------------------------------------------------------------------------------------*/
int Counter::Incr1()
{
    counter++;

    return counter;
}

/*---------------------------------------------------------------------------------------
 *Name - Incr10
 *Arguments - int counter
 *Return values - counter
 *Description - counts up 10 if counter + 10 < max
 *Notes -2/6/13 - simple incrementing
-----------------------------------------------------------------------------------------*/
int Counter::Incr10()
{

    counter+=10;

    return counter;
}

/*---------------------------------------------------------------------------------------
 *Name - Incr100
 *Arguments - int counter
 *Return values - counter
 *Description - counts up 100 if count + 100 < max
 *Notes -2/6/13 - simple incrementing
-----------------------------------------------------------------------------------------*/
int Counter::Incr100()
{

    counter+=100;

    return counter;
}

/*---------------------------------------------------------------------------------------
 *Name - Incr1000
 *Arguments - int counter
 *Return values - counter
 *Description - counts up 1000 if count + 1000 < max
 *Notes -2/6/13 - simple incrementing
-----------------------------------------------------------------------------------------*/
int Counter::Incr1000()
{


    counter+=1000;

    return counter;

}

/*---------------------------------------------------------------------------------------
 *Name - GetCount
 *Arguments - int counter
 *Return values - counter
 *Description - returns the counter
 *Notes -2/6/13 - simple return
-----------------------------------------------------------------------------------------*/
int Counter::GetCount()
{
    return counter;
}

/*---------------------------------------------------------------------------------------
 *Name - GetMax
 *Arguments - int counter
 *Return values - counter
 *Description - returns the max
 *Notes -2/6/13 - simple return
-----------------------------------------------------------------------------------------*/
int Counter::GetMax()
{
    return max;
}
