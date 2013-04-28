/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-6
Due Date        11/3/11
Class-          CS2
Description-    This program takes a measurement in feet and inches and converts it to meters and centimeters
*/
#include <iostream>
#include <cstdlib>

using namespace std;

const double meter_to_foot = .3048;//constant converter
void getting_input(double& feet, double& inches);//getting input
void conversion(double feet, double inches, double& meters, double& centimeters);//conversion
void show_output(double feet, double inches, double meters, double centimeters, char& repeat);//shows output

int main()
{
    double feet;
    double inches;
    double meters;
    double centimeters;
    char repeat;
    //variable declaration

    do
    {
        getting_input(feet, inches);//input function call
        conversion(feet, inches, meters, centimeters);//conversion function call
        show_output(feet, inches, meters, centimeters, repeat);//output function call
    }while (repeat == 'y' || repeat == 'Y');//loop

    return 0;
}
void getting_input(double& feet, double& inches)//getting input in feet and inches
{
    system ("cls");
    cout << "Please Enter a measurement in feet.\n";
    cin >> feet;
    cout << "Please Enter a measurement in inches.\n";
    cin >> inches;
}
void conversion(double feet, double inches, double& meters, double& centimeters)//convertering to meters and centimeters
{
    double inches_to_feet;
    double leftover_meters;
    double new_feet;
    inches_to_feet = (inches / 12);//converting inches to feet
    new_feet = (feet + inches_to_feet);//setting new feet value
    meters = (new_feet * meter_to_foot);//calculating meters
    leftover_meters = meters;
    while (leftover_meters >= 1)//calculating extra meters
    {
        leftover_meters = (leftover_meters - 1); //calculating extra meters
    }
    centimeters = (leftover_meters * 100);//calculating centimeters
    meters = meters - leftover_meters;
}
void show_output(double feet, double inches, double meters, double centimeters, char& repeat)
{
    cout << "If you have " << feet << " feet, and " << inches << " inches.\n";
    cout << "Then you have " << meters << " meters, and " << (int)centimeters << " centimeters.\n";//output of results
    cout << "If you want to repeat enter Y, else enter any key.\n";
    cin >> repeat;//input for loop
}
/*
Sample Output
Please Enter a measurement in feet.
12
Please Enter a measurement in inches.
4
If you have 12 feet, and 4 inches.
Then you have 3.7592 meters, and 375.92 centimeters.
If you want to repeat enter Y, else enter any key.
n

Process returned 0 (0x0)   execution time : 5.142 s
Press any key to continue.
*/



