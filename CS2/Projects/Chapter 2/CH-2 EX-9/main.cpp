/*
Programmer:     Jonathan Chan
Project:        Chapter 2 Excercise 9
Class:          CS2
Due:            9/13/2011
Description:    For a stereo costing $1000 and 1.5% interest a month. With a monthly funds of $50 calculates the time that it
                takes to pay off the stereo and the total amount of interest paid.

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double intrest_rate = .015;
    double intrest;
    double intrest_total = 0;
    double principal = 1000;
    double total;
    double funds = 50;
    int counter = 0;

    while (principal > 0)
    {
        counter++;
        intrest = principal * intrest_rate;
        intrest_total = intrest_total + intrest;
        total = funds - intrest;
        principal = principal - total;
    }
    cout << "You bought a $1,000 stereo system paying $50 a month.\n";
    cout << "It comes with a 1.5% interest rate per month. \n";
    cout << "It took " << counter;
    cout << " months to pay off the stereo system.\n";
    cout << "The total interest paid was $ ";
    cout << setprecision (5) << intrest_total;
    return 0;
}

/*
You bought a $1,000 stereo system paying $50 a month.
It comes with a 1.5% interest rate per month.
It took 24 months to pay off the stereo system.
The total interest paid was $ 197.83
Process returned 0 (0x0)   execution time : 0.046 s
Press any key to continue.
*/  ````````````````````````
