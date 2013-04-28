/*-----------------------------------------------------------------------------------------
Project: 10-10 Rational Class
Author: Jonathan Chan
Description: Rational class to add/sub/mul/divide fractions.
Notes: 2/8 Not to hard used book formulas. not sure if there is a way to reduce.
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational fraction(1,2), fraction2(1,2);

    fraction.Add(fraction2).GetFraction();
    cout << endl;
    fraction.Subtract(fraction2).GetFraction();
    cout << endl;
    fraction.Multiply(fraction2).GetFraction();
    cout << endl;
    fraction.Divide(fraction2).GetFraction();
    cout << endl;



//    if(fraction.LessThan(fraction2))
//    {
//        cout << "LESSTHAN\n";
//    }
//    else
//    {
//        cout << "GREATERTHAN\n";
//    }



    return 0;
}
