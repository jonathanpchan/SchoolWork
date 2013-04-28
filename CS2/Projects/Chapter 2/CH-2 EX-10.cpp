/*
Programmer:     Jonathan Chan
Project:        Chapter 2 Excercise 10
Class:          CS2
Due:            9/13/2011
Description:    This programs asks for ten whole numbers then calculates the sum of the positive numbers, the negative numbers
                and the total of all the numbers and then displays them.
*/
#include <iostream>

using namespace std;

int main()
{
   int intvalue;
   int total;
   int counter = 0;
   int positiveint = 0;
   int negativeint = 0;

   cout << "Please enter ten whole numbers. \n";
   while (counter < 10)
   {
       counter++;
       cout << "Value " << counter << endl;
       cin >> intvalue;
       if (intvalue > 0)
           positiveint = positiveint + intvalue;
       else
           negativeint = negativeint + intvalue;
   }
   total = positiveint + negativeint;
   cout << "The sum of the positive numbers is ";
   cout << positiveint << endl;
   cout << "The sum of the negative numbers is ";
   cout << negativeint << endl;
   cout << "The total of all the numbers is ";
   cout << total;
   return 0;
}
/* - SAMPLE OUTPUT
Please enter ten whole numbers.
Value 1
5
Value 2
77
Value 3
2
Value 4
-555
Value 5
2009
Value 6
223
Value 7
457
Value 8
-213
Value 9
-67
Value 10
2
The sum of the positive numbers is 2775
The sum of the negative numbers is -835
The total of all the numbers is 1940
Process returned 0 (0x0)   execution time : 17.941 s
Press any key to continue.
*/
