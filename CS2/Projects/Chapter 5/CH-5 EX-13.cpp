/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-13
Due Date        11/10/11
Class-          CS2
Description-    This Program takes in 3 lengths for a triangle and checks them if they are real triangle, if it is real the program calculates area and perimeter and displays it to the user, else it gives the user an error.
*/
#include <iostream>
#include <cmath>

using namespace std;
void get_lengths(double& side1, double& side2, double& side3);//getting the lengths
void triangle_check(double side1, double side2, double side3, char& correct_triangle);//checks to see if the triangle is real
void calculate(double side1, double side2, double side3, double& area, double& perimeter);//calculates the area and perimeter
void show_output(double side1, double side2, double side3, double area, double perimeter);//outputs the values
int main()
{
    double side_a;
    double side_b;
    double side_c;
    double perimeter;
    double area;
    char correct_triangle;//variable declaration

    get_lengths(side_a, side_b, side_c);//function call to obtain lengths
    triangle_check(side_a, side_b, side_c, correct_triangle);//function call to check the triangle
    if(correct_triangle == 't')
    {
        calculate(side_a, side_b, side_c, area, perimeter);//function call to calculate the area and perimeter
        show_output(side_a, side_b, side_c, area, perimeter);//function call to show output
    }
    else
    {
        cout << "The sum of the length any two sides must exceed the length of the third.\n";
        cout << "Trinagle does not exist please try again.\n";//output when triangle lengths is false
    }
    return 0;
}
void get_lengths(double& side1, double& side2, double& side3)//obtaining triangle lengths
{
    cout << "Please enter the length of the first side of a triangle.\n";
    cin >> side1;
    cout << "Please enter the length of the second side of the triangle.\n";
    cin >> side2;
    cout << "Please enter the length of the third side of the triangle.\n";
    cin >> side3;
}
void triangle_check(double side1, double side2, double side3, char& correct_triangle)//checks to see if triangle is real
{
    if (((side1 + side2) <= side3) || ((side1 + side3) <= side2) || ((side2 + side3) <= side1))
    {
        correct_triangle = 'f';
    }
    else
    {
        correct_triangle = 't';
    }
}
void calculate(double side1, double side2, double side3, double& area, double& perimeter)//calculates perimeter and area using formula given by book
{
    double semiperimeter;
    semiperimeter = ((side1 + side2 + side3)/2.0);
    area = sqrt(semiperimeter * (semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3));
    perimeter = (side1 + side2 + side3);
}
void show_output(double side1, double side2, double side3, double area, double perimeter)//shows the area and perimeter tot he user/
{
    cout << "If you had a triangle with lengths " << side1 << ", " << side2 << " and " << side3 << ".\n";
    cout << "Then your triangle has an area of " << area << " square units.\n";
    cout << "And your triangle has a perimeter of " << perimeter << " units";
}
/*Sample output
Please enter the length of the first side of a triangle.
12
Please enter the length of the second side of the triangle.
12
Please enter the length of the third side of the triangle.
a
The sum of the length any two sides must exceed the length of the third.
Trinagle does not exist please try again.

Process returned 0 (0x0)   execution time : 2.020 s
Press any key to continue.
*/
