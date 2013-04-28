/*-----------------------------------------------------------------------------------------
Project: 11-11 List Class
Author: Jonathan Chan
Description: List Class for anything
Notes: 2/13 very easy, almost the same as 11-3.

-----------------------------------------------------------------------------------------*/
#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List l;
    for(int i=0; i<50; i++)
    {
        l.Set(i);
    }
    l.Show();
    cout << endl;

}


/******************************************************
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42
, 43, 44, 45, 46, 47, 48, 49,
Press <RETURN> to close this window...
******************************************************/