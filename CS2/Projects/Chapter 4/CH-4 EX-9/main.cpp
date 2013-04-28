/*
Programmer-     Jonathan Chan
Assignment-     CH-4 EX-9
Due Date        10/18/11
Class-          CS2
Description-    This Program Takes a users input of weight, height, and age and uses three seperate functions to calculate the users waist size, hat size and jacket size,
                then gives these outputs calculated by functions back to the user
*/
#include <iostream>
#include <cstdlib>

using namespace std;

double hat(double weight, double height); //calculates hat size
double jacket(double height, double weight, double age);//calculates jacket size
double waist(double weight, double age);//calculates waist size

int main()
{
    char repeat;
    do //loop start
    {
        system ("cls");
        double height;
        double weight;
        double age;
        double hat_size;
        double jacket_size;
        double waist_size;
        //variable declaration

        cout << "Clothing Size Checker v0.3\n";
        cout << "Please enter your height in inches.\n";
        cin >> height; // height input
        cout << "Now please enter your weight in pounds.\n";
        cin >> weight; // weight input
        cout << "Finally enter your age in years.\n";
        cin >> age; // age input

        hat_size = hat(weight, height);//hat size function call

        jacket_size = jacket(height, weight, age);//jacket size function call

        waist_size = waist(weight, age);//waist size function call

        cout << "If you are " << age << " years old, weigh " << weight << " pounds, and you are " << height << " inches tall.\n";
        cout << "Then your hat size should be " << hat_size << ".\n"; //output of hat size function
        cout << "your Jacket Size (Chest in inches) is " << jacket_size << ".\n";//output of jacket size function
        cout << "and your Waist Size (Waist in inches) is " << waist_size << ".\n";//output of waist size function

        cout << "If you wish to try again, enter Y, other wise enter any key.\n";
        cin >> repeat;
    }while (repeat == 'y' || repeat == 'Y');//loops when users enter y
    return 0;
}
double hat(double weight, double height)// hat size function, calculations given by boook
{
    double size_of_hat;// variable declaration
    size_of_hat = ((weight/height)*2.9);//calculating size

    return (size_of_hat);
}
double jacket(double height, double weight, double age)//jacket size function with adjustments given by book
{
    double size_of_jacket;
    double jacket_adjustment;
    int jacket_change;//variable declaration

    size_of_jacket = ((height*weight)/288);//initial calculation before adjustment

    if (age > 30)
    {
        jacket_change = ((age-30)/10);//using int to force round down because of 10-year gaps to avoid errors in calculations
    }
    else
    {
        jacket_change = 0;
    }

    jacket_adjustment = (double(jacket_change)/8);//calculating the adjustment
    size_of_jacket = size_of_jacket + jacket_adjustment;//calculating total jacket size

    return (size_of_jacket);
}
double waist(double weight, double age)//waist size function with adjustments given by book
{
    double size_of_waist;
    double waist_adjustment;
    int waist_change;//variable declaration

    size_of_waist = (weight/5.7);

    if (age > 28)
    {
        waist_change = ((age-28)/2);//using int to force round down because of 2-year gaps avoiding, errors in calculations
    }
    else
    {
        waist_change = 0;
    }

    waist_adjustment = (double (waist_change)/10);//calculating adjustment for waist size
    size_of_waist = size_of_waist + waist_adjustment;//calculating total waist size.

    return(size_of_waist);
}

/*

SAMPLE OUTPUT

Clothing Size Checker v0.3
Please enter your height in inches.
72
Now please enter your weight in pounds.
150
Finally enter your age in years.
60
If you weight 150 pounds, are 60 years old, and you stand 72 inches tall.
Then your hat size should be 6.04167.
your Jacket Size (Chest in inches) is 37.875.
and your Waist Size (Waist in inches) is 27.9158.
If you wish to try again, enter Y, other wise enter any key.
n

Process returned 0 (0x0)   execution time : 16.045 s
Press any key to continue.
*/


