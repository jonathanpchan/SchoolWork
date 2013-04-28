/*-----------------------------------------------------------------------------------------
Project: 10-5 Basic Counter
Author: Jonathan Chan
Description: Counts up and down will not go below 0
Notes: 2/6 pretty easy
-----------------------------------------------------------------------------------------*/

#include <iostream>
#include "countertype.h"
#include <cstdlib>

using namespace std;

int main()
{
    CounterType count;

    for(int i=0; i<1000; i++)
    {
        cout<< "counter = " << count.GetCounter() << endl;
        count.IncrementCount();
    }
    cout<< "counter = " << count.GetCounter() << endl;
    system("pause");

    for(int i=0; i<250; i++)
    {
        cout<< "counter = " << count.GetCounter() << endl;
        count.DecrementCount();
    }
    return 0;
}
