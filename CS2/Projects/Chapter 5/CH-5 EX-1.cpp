/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-1
Due Date        10/27/11
Class-          CS2
Description-    This program in military/24 hour time and converts it to standard time usuing seperate functions to recieve input, calculate the changes and output the result.
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void time_input(int& hour, char& colon, int& minutes);//recieving input
void change_number(int& hour, char& colon, int& minutes, int& original_hour, char& day_night);//calculating the changes
void time_output(int& hour, char& colon, int& minutes, int& original_hour, char& day_night);//outputs the results

int main()
{
    int hour;
    int minutes;
    int original_hour;
    char colon;
    char day_night;
    char repeat;
    //variable declaration

    do
    {
        system ("cls");
        time_input(hour, colon, minutes);//input function call
        change_number(hour, colon, minutes, original_hour, day_night);//convert function call
        time_output(hour, colon, minutes, original_hour, day_night);// output function call
        cout << "Enter Y to repeat.\n";
        cin >> repeat;
    }while (repeat == 'y' || repeat == 'Y');//loop
    return 0;
}



void time_input(int& hour, char& colon, int& minutes)//taking inputs
{
    cout << "Please enter a time in 24:00 format that you want to convert.\n";
    cin >> hour >> colon >> minutes;//input on a single line
}
void change_number(int& hour, char& colon, int& minutes, int& original_hour, char& day_night)//converting the number
{
    original_hour = hour;//to save for later output
    if (hour > 12)//P.M. Times
    {
        hour = hour - 12;//to covert the time into the 12 hour version
        day_night = 'P';//setting p for PM
    }
    else if (hour == 12)//special case where hour = 12 is noon PM
    {
        day_night = 'P';//set to PM
    }
    else if (hour == 0)//special case where hour = 0 in 24:00 time
    {
        hour = 12;//set it to 12
        day_night = 'A';//set to AM
    }

}
void time_output(int& hour, char& colon, int& minutes, int& original_hour, char& day_night)//output numbers
{
    cout << "If it is " << original_hour << colon << setw(2) << setfill('0') << minutes << endl;
    if (original_hour >= 12)
    {
        cout << "Then the converted time is " << hour << colon << setw(2) << setfill('0') << minutes << " " <<  day_night << ".M.\n";//output adds 0 to minutes if minutes > 10 for PM
    }
    else
    {
        cout << "Then the converted time is " << hour << colon << setw(2) << setfill('0') << minutes << " " << day_night << ".M.\n";//output adds 0 to minutes if minutes > 10 for AM
    }
}

/*

SAMPLE OUTPUT

Please enter a time in 24:00 format that you want to convert.
12:45
If it is 12:45
Then the converted time is 12:45 P.M.
Enter Y to repeat.
n

Process returned 0 (0x0)   execution time : 4.935 s
Press any key to continue.

*/
