/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-2
Due Date        10/27/11
Class-          CS2
Description-    This program recieves a time the allows a user to input an amount of hours/minutes to wait then outputs the time after the wait. allows users to add more time as well
*/
#include <iostream>
#include <iomanip>

using namespace std;

void time_input(int& hour, char& colon, int& minutes, int& wait_hours, int& wait_minutes);//recieving original time input
void wait_input (int& wait_hours, int& wait_minutes);//recieve wait time input
void add_time(int& hour, int& minutes, int& wait_hours, int& wait_minutes,int& new_hour, int& new_minutes);//coverts the time
void new_time(int& hour, int& minutes, int wait_hours, int wait_minutes, int new_hour, int new_minutes, char colon);//outputs the time


int main()
{
    int hour;
    int minutes;
    int wait_hours;
    int wait_minutes;
    int new_hour;
    int new_minutes;
    char colon;
    char repeat;
    //variable declaration

    time_input(hour, colon, minutes, wait_hours, wait_minutes);//original time input call
    do
    {
        wait_input(wait_hours, wait_minutes);//wait input call
        add_time(hour, minutes, wait_hours, wait_minutes, new_hour, new_minutes);//time converter call
        new_time(hour, minutes, wait_hours, wait_minutes, new_hour, new_minutes, colon);//output call
        cout << "Enter Y to add more time.\n";
        cin >> repeat;
    }while (repeat == 'y' || repeat == 'Y');//loop to add more time

}
void time_input(int& hour, char& colon, int& minutes, int& wait_hours, int& wait_minutes)//recieving input for original time
{
    cout << "Please enter a time in 24:00 format.\n";
    cin >> hour >> colon >> minutes;
}
void wait_input (int& wait_hours, int& wait_minutes)//recieves input for wait hours/minutes
{
    cout << "Please enter an amount of hours to wait.\n";
    cin >> wait_hours;
    cout << "Now please enter an additional amount of minutes to wait.\n";
    cin >> wait_minutes;
}
void add_time(int& hour, int& minutes, int& wait_hours, int& wait_minutes,int& new_hour, int& new_minutes)//adds the wait hour/minute to current hour/minute to come up witht he new hour/minute with calculations for when min>60 and hours >24
{
    new_hour = hour + wait_hours;
    new_minutes = minutes + wait_minutes;

    if (new_minutes >= 60)
    {
        new_hour = (new_hour + (new_minutes/60));
        new_minutes = new_minutes - 60;
    }
    if (new_hour >= 24)
    {
        new_hour = new_hour%24;
    }
}
void new_time(int& hour, int& minutes, int wait_hours, int wait_minutes, int new_hour, int new_minutes, char colon)//outputs new time sets hours for adding more time
{
    cout << "If you started at " << hour << colon << setw(2) << setfill('0') << minutes << endl;
    cout << "And you waited " << wait_hours << " hours and " << wait_minutes << " minutes.\n";
    cout << "Then your new time is " << new_hour << colon << setw(2) << setfill('0') << new_minutes << endl;
    hour = new_hour;
    minutes = new_minutes;
}
/*
Sample Output

Please enter a time in 24:00 format.
12:35
Please enter an amount of hours to wait.
1
Now please enter an additional amount of minutes to wait.
45
If you started at 12:35
And you waited 1 hours and 45 minutes.
Then your new time is 14:20
Enter Y to add more time.
y
Please enter an amount of hours to wait.
2
Now please enter an additional amount of minutes to wait.
20
If you started at 14:20
And you waited 2 hours and 20 minutes.
Then your new time is 16:40
Enter Y to add more time.
n

Process returned 0 (0x0)   execution time : 25.134 s
Press any key to continue.
*/
