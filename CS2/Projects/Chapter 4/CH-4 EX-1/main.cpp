/*
Programmer-     Jonathan Chan
Assignment-     CH-4 EX-1
Due Date        10/4/11
Class-          CS2
Description-    This program takes input of miles traveled and the liters used to travel that amount, using a function it
                converts liters to gallons and then outputs
*/
#include <iostream>
#include <cstdlib>

using namespace std;

double mpg (double miles_traveled, double liters_used);
//Takes miles traveled and liters used and computes mpg

int main()
{

    char repeat;
    do
    {
        double miles_traveled;
        double liters_used;
        double miles_per_gallon;
        //Variable declaration

        system ("cls");
        cout << "Miles Per Liter to Miles Per Gallon Converter v1.0\n";
        cout << "Please input the amount of miles that your car traveled.\n" << "Then input how many liters of gasoline it took.\n";

        cin >> miles_traveled >> liters_used; // recieved input for variables

        miles_per_gallon = mpg(miles_traveled, liters_used);//Function Call

        cout << "If you traveled " << miles_traveled << " with " << liters_used << " litres of gas.\n";
        cout << "Then your vehicle gets around " << miles_per_gallon << " miles per gallon.\n";
        cout << "If you wish to try again, enter Y, other wise enter any key.\n";

        cin >> repeat;

    }while (repeat == 'y' || repeat == 'Y');//Loop

    return 0;
}

double mpg (double miles_traveled, double liters_used)//Function header
{
    double liter = 0.264179;
    double gallons_used;
    gallons_used = liters_used *liter;//Converts liters to gallons
    return (miles_traveled / gallons_used);//returns Miles per gallon by taking miles traveled/the amount of gallons used
}
