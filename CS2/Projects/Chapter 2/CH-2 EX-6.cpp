1/*
Programmer:     Jonathan Chan
Project:        Chapter 2 Excercise 6
Class:          CS2
Due:            9/13/2011
Description:    This program checks the legality of a meeting by first asking for the maxiumum room capacity and the number of
                attendees for the meeting to be held. If the number of attendees exceeds maximum room capacity, it displays
                that the meeting cannot be held due to fire regulations and tells you how many people need to be excluded
                before the meeting can be held. If the number of attendees is less than the maximum room capacity, it tells you
                that the meeting is legal and displays how many extra people can attend legally. The program then gives the
                option to repeat.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    char ans;
    do
    {
    system("COLOR F0");
    system("cls");

    int maxcapacity;
    int attendees;
    int extrapeople;
    int excludepeople;

    cout << "Meeting Legality Checker v.1.2 \n";
    cout << "Please enter the maximum room capicty of the room to be used ";
    cin >> maxcapacity;
    cout << "Please enter the number of attendees ";
    cin >> attendees;

    extrapeople = maxcapacity-attendees;
    excludepeople = attendees-maxcapacity;

    if (maxcapacity >= attendees)
    {
        cout <<"Congratulations, your meeting is legal to hold! \n";
        cout <<"You can have up to ";
        cout << extrapeople;
        cout << " extra people before fire regulations are violated. \n";
    }
    else
    {
        cout << "We're sorry, the meeting will exceed the maximum room capacity.\n";
        cout << "You may not hold this meeting due to fire regulations. \n";
        cout << "You must exclude at least ";
        cout << excludepeople;
        cout << " people before the meeting is legal to hold. \n";
    }

    cout << "Do you want to try again? Y/N \n";
    cin >> ans;
    } while (ans =='y' || ans == 'Y');

    return 0;
}
/* SAMPLE OUTPUT
Meeting Legality Checker v.1.2
Please enter the maximum room capicty of the room to be used 55
Please enter the number of attendees 65
We're sorry, the meeting will exceed the maximum room capacity.
You may not hold this meeting due to fire regulations.
You must exclude at least 10 people before the meeting is legal to hold.
Do you want to try again? Y/N
n

Process returned 0 (0x0)   execution time : 8.984 s
Press any key to continue.
*/
