/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-9
Due Date        11/3/11
Class-          CS2
Description-    This program takes a measurement in pounds and ounces and converts it to kilograms and grams.
*/
#include <iostream>
#include <cstdlib>

using namespace std;
const double pounds_to_kilograms = 2.2046;
void getting_input(double& pounds, double& ounces);//getting input
void conversion(double pounds, double ounces, double& kilograms, double& grams);//conversion
void show_output(double pounds, double ounces, double kilograms, double grams, char& repeat);//shows output

int main()
{
    double pounds;
    double ounces;
    double kilograms;
    double grams;
    char repeat;
    //variable declaration

    do
    {
        getting_input(pounds, ounces);//input function call
        conversion(pounds, ounces, kilograms, grams);//conversion function call
        show_output(pounds, ounces, kilograms, grams, repeat);//output function call
    }while (repeat == 'y' || repeat == 'Y');//loop

    return 0;
}
void getting_input(double& pounds, double& ounces)//getting input in pounds and ounces
{
    system ("cls");
    cout << "Please Enter a measurement in Pounds.\n";
    cin >> pounds;
    cout << "Please Enter a measurement in Ounces.\n";
    cin >> ounces;
}
void conversion(double pounds, double ounces, double& kilograms, double& grams)//convertering to kilograms and grams
{
    double ounces_to_pounds;
    double new_pounds;
    double leftover_kilograms;


    ounces_to_pounds = (ounces / 16);//converting ounces to pounds
    new_pounds = (pounds + ounces_to_pounds);//setting new pounds value
    kilograms = (new_pounds / pounds_to_kilograms);//calculating kilograms
    leftover_kilograms = kilograms;

    while (leftover_kilograms >= 1)
    {
        leftover_kilograms = (leftover_kilograms - 1);
    }

    grams = (leftover_kilograms * 1000);//calculating centimeters
    kilograms = kilograms - leftover_kilograms;

}
void show_output(double pounds, double ounces, double kilograms, double grams, char& repeat)
{
    cout << "If you have " << pounds << " Pounds, and " << ounces << " Ounces.\n";
    cout << "Then you have " << kilograms << " Kilograms, and " << (int)grams << " grams.\n";//output of results
    cout << "If you want to repeat enter Y, else enter any key.\n";
    cin >> repeat;//input for loop
}
/*
Sample Output
Please Enter a measurement in Pounds.
100
Please Enter a measurement in Ounces.
5
If you have 100 Pounds, and 5 Ounces.
Then you have 45.5015 Kilograms, and 45501.5 grams.
If you want to repeat enter Y, else enter any key.
*/


