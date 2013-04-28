/*
Programmer:     Jonathan Chan
Project:        Chapter 1 Exercise 5
Class:          CS2
Due:            9/6/2011
Description:    Takes two different integers the user submits then calculates their product and sum and displays them for the user.
*/
#include <iostream>

using namespace std;

int main()
{
    int integer1, integer2, integersum, integerproduct;

    cout << "Press return after entering an integer.\n";
    cout << "Please enter your first interger.\n";
    cin >> integer1;
    cout << "Please enter your second integer.\n";
    cin >> integer2;

    integersum=integer1+integer2;
    integerproduct=integer1*integer2;

    cout << "If you have ";
    cout << integer1;
    cout << " and ";
    cout << integer2;
    cout << "\n";
    cout << "Their sum is ";
    cout << integersum;
    cout <<"\n";
    cout << "And their product is ";
    cout << integerproduct;
    return 0;
}
