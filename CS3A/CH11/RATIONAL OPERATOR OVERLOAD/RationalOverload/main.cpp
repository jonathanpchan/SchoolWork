#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational fraction(50,40), fraction2(123,467), fraction3(6,9);

    cout << fraction+fraction2 << endl;
    cout << fraction-fraction2 << endl;
    cout << fraction*fraction2 << endl;
    cout << fraction/fraction2 << endl;

//    fraction3.Simplify();
//    cout << fraction3 << endl;

//    fraction.Simplify();
//    cout<<fraction << endl;




//    if(fraction<fraction2)
//    {
//        cout << "LESSTHAN\n";
//    }
//    else
//    {
//        cout << "GREATERTHAN\n";
//    }
//    if(fraction==fraction2)
//    {
//        cout << "EQIVALENT\n";
//    }
//    else
//    {
//        cout << "NOTEQUIVALENT\n";
//    }

    return 0;
}
