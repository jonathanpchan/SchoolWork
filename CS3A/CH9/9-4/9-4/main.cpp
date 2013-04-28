/*-----------------------------------------------------------------------------------------
Project: 9-4 Reverse String
Author: Jonathan Chan
Description: Takes a cstring into a char pointer and then reverses it
Notes: 1/30 was not too difficult.
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

char* Reverse(char* str);//reverses the pointer.

int main()
{

    char* str = new char[10];
    char* test = new char[100];

    cout << "enter string: ";
    cin.getline(test,100);

    cout << "test: " << test << endl;


    strcpy(str,test);
    cout<<"reversed: " << Reverse(str) << endl;


    delete[]str;
    delete[]test;

    return 0;
}


/*---------------------------------------------------------------------------------------
 *Name - Reverse
 *Arguments - char pointer
 *Return values - returns the same char pointer reversed
 *Description - reverses using a temp pointer that i increment until the end and the decrement it
 *Notes -1/30/13 - Not too hard, not sure what bugs may arise...
-----------------------------------------------------------------------------------------*/
char* Reverse(char* front)
{
    char* rear;
    char* reversed = new char[100];
    char* hold= reversed;

    rear = front;

    int size = strlen(front);

    while(*rear)
    {
        rear++;
    }
    rear--;

    int i=0;


    while(i<size)
    {
        *reversed++ = *rear--;//i am stupid;
        i++;
    }
    *reversed = '\0';
    strcpy(front, hold);
    return front;
}

