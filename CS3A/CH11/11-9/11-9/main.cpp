/*-----------------------------------------------------------------------------------------
Project: 11-9 Polynomial Class
Author: Jonathan Chan
Description: Polynomial class with different functions for them
Notes: 2/18 not entirely too difficult. Input is tricky. theres a silly way around it, but it seems
frivolous to put in. poly*poly was the hardest
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    int Terms = 4;
    double * Coeffcients = new double[Terms];
    Coeffcients[0] = 1;
    Coeffcients[1] = 5;
    Coeffcients[2] = 2;
    Coeffcients[3] = 2;

    polynomial poly(4,Coeffcients);

    int Terms2=6;
    double * Coeffcients2 = new double[Terms2];
    Coeffcients2[0] = 11;
    Coeffcients2[1] = 33;
    Coeffcients2[2] = 0;
    Coeffcients2[3] = 56;
    Coeffcients2[4] = 0;
    Coeffcients2[5] = 4;

    polynomial poly2(Terms2,Coeffcients2);

    cout << "poly - " << poly << endl;
    cout << "poly2 - " << poly2 << endl;

    cout << "poly*poly2 = " << poly*poly2 << endl;
    cout << "poly-1 = " << poly-1 << endl;
    cout << "poly+1 = " << poly+1 << endl;
    cout << "poly*2 = " << poly*2 << endl;


    return 0;
}
/*****************************************************************************
poly - 2x^3 + 2x^2 + 5x^1 + 1
poly2 - 4x^5 + 0x^4 + 56x^3 + 0x^2 + 33x^1 + 11
poly*poly2 = 8x^8 + 8x^7 + 132x^6 + 116x^5 + 346x^4 + 144x^3 + 187x^2 + 88x^1 + 11
poly-1 = 2x^3 + 2x^2 + 5x^1 + 0
poly+1 = 2x^3 + 2x^2 + 5x^1 + 1
poly*2 = 4x^3 + 4x^2 + 10x^1 + 2
Press <RETURN> to close this window...
***********************************************************************************/

