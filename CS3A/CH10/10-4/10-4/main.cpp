/*-----------------------------------------------------------------------------------------
Project: 10-4 Account Balance Maturity
Author: Jonathan Chan
Description: Calculates maturity on a bank account
Notes: 2/6 Not too hard, most of code, alot of the code is from the book.
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include "cdaccount.h"

using namespace std;

int main()
{

    cdaccount account(50000, 1, 10, 3);

    //account.SetData(50000, 99, 10, 3);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "account balance : " << account.GetBalance() << endl;
    cout << "account rate : " << account.GetRate() << endl;
    cout << "account term : " << account.GetTerm() << endl;
    cout << "account maturity : " << account.GetMaturity()<<endl;
    
    return 0;
}
