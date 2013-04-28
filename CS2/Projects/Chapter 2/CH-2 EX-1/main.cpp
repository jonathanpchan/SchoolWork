/*
Programmer:     Jonathan Chan
Project:        Chapter 2 Excercise 1
Class:          CS2
Due:            9/13/2011
Description:    This Program firsts displays the number of ounces in a metric ton. It then asks for the number of ounces is in
                a box of cereal. Using that number it tells you how many metric tons the box of cereal is and the number of
                boxes you would need to have 1 metric ton worth of cereal. The program then gives the option to repeat.
*/
#include <iostream>

using namespace std;

int main()
{
    char ans;
    do
    {
    system("cls");

    double cerealoz;
    double boxes;
    double cerealtons;
    double metricton = 35273.92;

    cout << "A metric ton is 35,273.92 ounces.\n";
    cout << "Please enter the weight of a package of cereal in ouces.\n";
    cin >> cerealoz;

    cerealtons = cerealoz/metricton;
    boxes = metricton/cerealoz;

    cout << "The cereal box is approximately ";
    cout << cerealtons;
    cout << " metric tons.\n";
    cout << "You would need ";
    cout << boxes;
    cout << " boxes of cereal to have 1 metric ton worth of cereal.\n";
    cout << "Do you want to try again? Y/N \n";
    cin >> ans;
    } while (ans =='y' || ans == 'Y');
    return 0;
}
/* SAMPLE OUTPUT
A metric ton is 35,273.92 ounces.
Please enter the weight of a package of cereal in ouces.
5555
The cereal box is approximately 0.157482 metric tons.
You would need 6.34994 boxes of cereal to have 1 metric ton worth of cereal.
Do you want to try again? Y/N
n

Process returned 0 (0x0)   execution time : 2.328 s
Press any key to continue.
*/
