/*
Programmer-     Jonathan Chan
Assignment-     CH-4 EX-6
Due Date        10/4/11
Class-          CS2
Description-    This program takes an intial balance, intrest rate and months to pay off, and calculates the exact amount of intrest to be paid
                after the months.
*/
#include <iostream>
#include <cstdlib>

using namespace std;
double intrest_due(double balance, double intrest_rate, double months);
//calculates intrest due with compound intrest

int main()
{
    char repeat;
    do
    {
        system ("cls");
        double balance;
        double intrest_rate;
        double months;
        double payment;
        //variable declaration

        cout << "Payment checker v3.2\n";
        cout << "Please enter your initial balance.\n";
        cin >> balance;
        cout << "Now enter your monthly interest rate in percentage ex - 5.2\n";
        cin >> intrest_rate;
        cout << "Now enter the number of months which interest must be paid.\n";
        cin >> months;
        //getting input for the variables

        payment = intrest_due(balance, intrest_rate, months);//function call

        cout << "If your initial balance was $" << balance <<endl;
        cout << "And your intrest rate is " << intrest_rate << "%\n";
        cout << "Being paid over " << months << " months.\n";
        cout << "Then the intrest due is $" << payment << endl;
        //output of calculations

        cout << "If you wish to try again, enter Y, other wise enter any key.\n";
        cin >> repeat;
    }while (repeat == 'y' || repeat == 'Y');//Loop
    return 0;
}
double intrest_due(double balance, double intrest_rate, double months)//function start
{
    double rate;
    double initial_cost;
    rate = ((intrest_rate/100)+1);
    initial_cost = balance;
    //extra variables to help with calculation

    while (months > 0)
    {
        months = months - 1;
        balance = balance*rate;
    }
    return (balance - initial_cost);
}
