/*
Programmer:     Jonathan Chan
Project:        Chapter 1 Exercise 2
Class:          CS2
Due:            9/6/2011
Description:    Based on Exercise 1 which Asks for number of pea pods and a number of peas per pod then mutiplies them to tell you how many peas you would have total. Exercise two asks to add the words "Hello" to the beginning, and "Good-bye" to the end.
*/
#include <iostream>

using namespace std;

int main()
{
    int number_of_pods, peas_per_pod, total_peas;

    cout << "Hello\n";
    cout << "Press return after entering a number.\n";
    cout << "Enter the number of pods:\n";
    cin >> number_of_pods;
    cout << "Enter the number of peas in a pod:\n";
    cin >> peas_per_pod;

    total_peas = number_of_pods*peas_per_pod;

    cout << "If you have ";
    cout << number_of_pods;
    cout << " pea pods\n";
    cout << "and ";
    cout << peas_per_pod;
    cout << " peas in each pod, then \n";
    cout << "you have ";
    cout << total_peas;
    cout << " peas in all the pods.\n";
    cout << "Good-bye\n";
    return 0;
}
