/*-----------------------------------------------------------------------------------------
Project: 9-3 Airplane seating
Author: Jonathan Chan
Description: Manages a planes seating.
Notes: 2/3 was not too difficult.
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

void Print(char** rows, int numRows);//prints the pointer
int ColCheck(char col);//changes a,b,c,d to a numerical equivalent for column
char** Reserve(char** plane, int row, char col, int numRows);//reserves a seat, prints the plane.

int main()
{
    int numRows = 4;
    int row;
    char col;

    char** plane = new char*[numRows];
    char** rowWalker = plane;
    char* seats = new char[4];
    strcpy(seats, "ABCD");

    for(int i=0; i<numRows; i++)
    {
        *rowWalker = new char[4];
        strcpy(*rowWalker,seats);
        *rowWalker++;
    }

    char ans = 'n';
    bool full = 0;
    int capacity = 4*numRows;
    int seatsTaken = 0;

    Print(plane, numRows);
    do
    {
        cout << "Enter a Seat numer ex: 2C\n";
        cin >> row>>col;

        Reserve(plane, row, col, numRows);
        seatsTaken++;

        if(seatsTaken==capacity)
        {
            full=1;
            cout << "Plane is full\n";
        }
    }while(toupper(ans)=='Y' || !full);


    //Print(plane, numRows);

    delete[] plane;
    return 0;
}

/*---------------------------------------------------------------------------------------
 *Name - ColCheck
 *Arguments - a character
 *Return values - an integer
 *Description - if user inputs A returns 0; for easy input/navigation
 *Notes -2/3/13 - Not too hard similar to hex
-----------------------------------------------------------------------------------------*/
int ColCheck(char col)
{
    char* seatIndex = new char[4+1];
    strcpy(seatIndex, "ABCD");

    for(int i = 0; i<4; i++)
    {
        if(toupper(col) == *seatIndex++)
        {
            return i;
        }
    }
}

/*---------------------------------------------------------------------------------------
 *Name - Reserve
 *Arguments - char pointer pointer
 *Return values - returns the plane after a seat is reserved
 *Description - navigates to the proper spot, the sets 'x' to reserve it.
                if taken does nothing
 *Notes -2/3/13 not too many difficulties.
-----------------------------------------------------------------------------------------*/
char** Reserve(char** plane, int row, char col, int numRows)
{
    char** rowWalker = plane;
    char* seatWalker;

    int colNum = ColCheck(col);
    int rowNum = row-1;//if user enters 1 it's index 0 etc...

    for(int i=0; i<rowNum; i++)
    {
        rowWalker++;//move down rows;
    }
    seatWalker = *rowWalker;//set seatWalker = *rowWalker;

    for(int i=0; i<colNum; i++)
    {
        seatWalker++;//move down "cols"
    }


    if(*seatWalker == 'X')
    {
        cout << "Seat Taken. Try another seat\n";
        return NULL;
    }
    else
    {
        *seatWalker = 'X';
        Print(plane, numRows);
    }



    return plane;
}

/*---------------------------------------------------------------------------------------
 *Name - Print
 *Arguments - char pointer pointer, int num rows
 *Return values - returns nothing, output array.
 *Description - prints the plane to see it
 *Notes -2/3/13 - Not too hard
-----------------------------------------------------------------------------------------*/
void Print(char** rows, int numRows)
{
    system("cls");
    for(int i=0; i<numRows; i++)
    {
        cout<< "Row " << i+1 << ": " << *rows++ << endl;//print each character pointer;
    }
}
