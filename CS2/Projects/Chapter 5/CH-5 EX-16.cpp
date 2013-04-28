/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-16
Due Date        11/10/11
Class-          CS2
Description-    This program takes in a date from a user and outputs the day of the week that day was based on calcultaions given by the book
*/
#include <iostream>
#include <string>
using namespace std;

void get_input(string& month, int& date, char& comma, int& year);//gets input
bool is_leap_year(int year, int& leap_year);//checks for leap year
void get_century_value(int year, int& century_value);//gets century value
void get_year_value(int year, int& year_value);//gets year value
void change_to_upper(string month, string& upper_month);//changes month to uppercase for verification
void get_month_value(string upper_month, int& month_value, int year, int leap_year);//gets month value
void calculate(int date, int month_value, int year_value, int century_value, int& day_value, int year, string month);//calculates the date
int main()
{
    string month;
    string upper_month;
    int date;
    int year;
    int leap_year;
    int century_value;
    int year_value;
    int month_value;
    int day_value;
    char comma;
    //variable declration

    get_input(month, date, comma, year);//function call for input from user
    get_century_value(year, century_value);
    get_year_value(year, year_value);
    change_to_upper(month, upper_month);
    get_month_value(upper_month, month_value, year, leap_year);
    calculate(date, month_value, year_value, century_value, day_value, year, month);

    return 0;
}
void get_input(string& month, int& date, char& comma, int& year)//takes input fromt he user
{
    cout << "Please enter a date in month-day-year format ex. November 11, 2011\n";
    cin >> month >> date >> comma >> year;
}
bool is_leap_year(int year, int& leap_year)//checks if the year is a leap year for later use
{
    if (((year % 400) == 0) || (((year % 4) == 0) && ((year % 100) != 0)))
    {
        return(true);
    }
    else
    {
        return(false);
    }
}
void get_century_value(int year, int& century_value)//gets the century value
{
    century_value = (year / 100);
    century_value = (century_value % 4);
    century_value = (3 - century_value);
    century_value = (century_value * 2);
}
void get_year_value(int year, int& year_value)//gets the yeare value
{
    while (year >= 100)
    {
        year = year - 100;
    }
    year_value = (year / 4);
    year_value =  year_value + year;
}
void change_to_upper(string month, string& upper_month)//changes the month string to uppercase for easy verification
{
    upper_month = month;
    for (int i=0; i < upper_month.length(); i++)
    {
        upper_month[i] = toupper(upper_month[i]);
    }
}
void get_month_value(string upper_month, int& month_value, int year, int leap_year)//gets month value
{
    if (is_leap_year(year, leap_year))
    {
        if(upper_month == "JANUARY")
        {
            month_value = 6;
        }
        else
        {
            month_value = 2;
        }
    }
    else
    {
        if((upper_month == "JANUARY") || (upper_month == "OCTOBER"))
        {
            month_value = 0;
        }
        else if ((upper_month == "FEBRUARY") || (upper_month == "MARCH") || (upper_month == "NOVEMBER"))
        {
            month_value = 3;
        }
        else if ((upper_month == "APRIL") || (upper_month == "JULY"))
        {
            month_value = 6;
        }
        else if (upper_month == "MAY")
        {
            month_value = 1;
        }
        else if (upper_month == "JUNE")
        {
            month_value = 4;
        }
        else if (upper_month == "AUGUST")
        {
            month_value = 2;
        }
        else
        {
            month_value = 5;
        }
    }
}
void calculate(int date, int month_value, int year_value, int century_value, int& day_value, int year, string month)//calculates the day of the week
{

    day_value = ((date + month_value + year_value + century_value) % 7);

    if (day_value == 0)
    {
        cout << month << " " << date << ", " << year << " is a Sunday";
    }
    else if (day_value == 1)
    {
        cout << month << " " << date << ", " << year << " is a Monday";
    }
    else if (day_value == 2)
    {
        cout << month << " " << date << ", " << year << " is a Teusday";
    }
    else if (day_value == 3)
    {
        cout << month << " " << date << ", " << year << " is a Wednesday";
    }
    else if (day_value == 4)
    {
        cout << month << " " << date << ", " << year << " is a Thursday";
    }
    else if (day_value == 5)
    {
        cout << month << " " << date << ", " << year << " is a Friday";
    }
    else
    {
        cout << month << " " << date << ", " << year << " is a Saturday";
    }
}
/*
Sample Output
Please enter a date in month-day-year format ex. November 11, 2011
November 11, 2011
November 11, 2011 is a Friday
Process returned 0 (0x0)   execution time : 4.105 s
Press any key to continue.
*/
