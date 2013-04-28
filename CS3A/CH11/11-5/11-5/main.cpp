/*-----------------------------------------------------------------------------------------
Project: 11-5 Rational Class
Author: Jonathan Chan
Description: Rational class to add/sub/mul/divide fractions.
Notes: 2/13 Not to hard used book formulas. copied most the code from 10-10;

-----------------------------------------------------------------------------------------*/
#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational fraction(50,40), fraction2(123,467), fraction3(6,9);

    cout << fraction  << " + " << fraction2 << "=" << fraction+fraction2 << endl;
    cout << fraction  << " - " << fraction2 << "=" << fraction-fraction2 << endl;
    cout << fraction  << " * " << fraction2 << "=" <<fraction*fraction2 << endl;
    cout << fraction  << " / " << fraction2 << "=" <<fraction/fraction2 << endl;




    return 0;
}

/*********************************
50/40 + 123/467=28270/18680
50/40 - 123/467=18430/18680
50/40 * 123/467=6150/18680
50/40 / 123/467=23350/4920
Press <RETURN> to close this window...
***********************************/
