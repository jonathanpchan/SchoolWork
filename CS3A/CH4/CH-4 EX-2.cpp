/*-----------------------------------------------------------------------------------------
Project: 4-2 Compare Car MPG
Author: Jonathan Chan
Description: Get liters used, and number of miles traveled. Convert it to mpg.
            Compare two values and output the better mileage.
-----------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

double const LITERSTOGALLONS = .264179;
void GetInput(double& liters, double& miles);//gets input for the program.
double CalculateMpg(double liters, double miles);//calculates MPG based in the information given, and const LITERSTOGALLONS
void CompareMpg(double car1, double car2);//outputs mpg for each car and outputs which car has better mileage



int main()
{
    double litersUsed, milesTraveled, firstCar, secondCar;

    getinput(litersUsed, milesTraveled);
    firstCar=CalculateMpg(litersUsed, milesTraveled);
    getinput(litersUsed, milesTraveled);
    secondCar=CalculateMpg(litersUsed, milesTraveled);
    compareMpg(firstCar, secondCar);

    return 0;
}
/*---------------------------------------------------------------------------------------
 *Name - GetInput
 *Arguments - liters, miles call by reference
 *Return values - none, changes done through call by reference
 *Description - simple function to get input from the user
 *Notes -
-----------------------------------------------------------------------------------------*/
void GetInput(double& liters, double& miles)
{
}

/*-----------------------------------------------------------------------------------------
 *Name - CalculateMPG
 *Arguments - liters and miles, uses constant LITERSTOGALLONS
 *Return values - returns a double value of Miles per gallon based on the constant Liters to gallons and
 *MilesTraveled and liters used provided by the user
 *Description - a function to convert liters used and miles traveled to miles per gallon.
 *Notes -
 -----------------------------------------------------------------------------------------*/
double CalculateMpg(double liters, double miles)
{
}

/*-----------------------------------------------------------------------------------------
 *Name - CompareMpg
 *Arguments - car1 and car 2
 *Return values - none, output function
 *Description - A function that outputs the mpg of both cars. compares the miles per gallon of the cars
 *and outputs which car has the better mileage
 *Notes -
 -----------------------------------------------------------------------------------------*/
void CompareMpg(double car1, double car2)
{
}
