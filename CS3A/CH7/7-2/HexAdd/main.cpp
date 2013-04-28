/**************************************
Project:Hexadecimal Addition

Author: Jonathan Chan

Description:This program uses arrays to add hex

Notes: 1/13/2012 Did the whole project. Had trouble with reversing. Adding was okay had troubles finding a solution for nice formatting. Ended up filling arrays with 0s
**************************************/

#include <iostream>
#include <cstdlib>
#include <string.h>


using namespace std;



void AddHex(int numbers1[], int numbers2[], int solution[]);//adds integers after they have been converted from hex and flipped in the array.
void Reverse(char reversed[]); //reverses the array to allow easier math
void HexToNum(char hex[], int numbers[]);//converts the hex to integers for easier math;
void NumToHex(char hex[], int numbers[]);//converts back  to hex for display.
void Print(char array[]);//prints the array
//void Print(int array[]);


int const MAX=10;

int main()
{
    char hexdec1[MAX], hexdec2[MAX], hexSol[MAX+1];
    int nums1[MAX], nums2[MAX], numSol[MAX];

    strcpy(hexdec1, "abc123");
    strcpy(hexdec2, "123abc");

    cout << "               abc123\n";
    cout << "+              123abc\n";
    cout << "=____________________\n";

    Reverse(hexdec1);
    Reverse(hexdec2);



    HexToNum(hexdec1, nums1);
    HexToNum(hexdec2, nums2);

    AddHex(nums1, nums2, numSol);

    NumToHex(hexSol, numSol);

    Reverse(hexSol);

    Print(hexSol);






    return 0;

}




/*---------------------------------------------------------------------------------------
 *Name - Reverse
 *Arguments - character array
 *Return values - none, changes made in arrays
 *Description - function to reverse a character array ex 12345 -> 54321.
                Includes error check for overflow
 *Notes - 1/13 had reversing because of null char, as it is copied along with the original
                did some thinkind to get around it.
-----------------------------------------------------------------------------------------*/
void Reverse(char reversed[])
{
    int i=0, j=0, length=0;
    int k=0, l=0;

    while(reversed[i]!='\0')
    {
        length++;
        i++;
    }
    char temp[length];
    while(reversed[j]!='\0')
    {
        temp[length-1-j] = reversed[j];
        j++;
    }
    temp[length] = '\0';
    strcpy(reversed, temp);
    if(length>MAX)
    {
            cout << "Overflow...\n";
            system("PAUSE");
            exit(0);
    }
}





/*---------------------------------------------------------------------------------------
 *Name - HexToNum
 *Arguments - character array, number array
 *Return values - none, done through arrays.
 *Description - simply changes hex values into their number values. so a->10 b->11 1->1
                checks for any input error. Fills the rest of the array with 0s
 *Notes - 1/13 Started without filling array with 0s, ended up doing it to get around adding differently
                sized arrays in HexAdd
-----------------------------------------------------------------------------------------*/
void HexToNum(char hex[], int numbers[])
{
    int i=0;
    while(hex[i] != '\0')
    {
        if(hex[i] == '0')
        {
            numbers[i]=0;
        }
        else if(hex[i] == '1')
        {
            numbers[i]=1;
        }
        else if(hex[i] == '2')
        {
            numbers[i]=2;
        }
        else if(hex[i] == '3')
        {
            numbers[i]=3;
        }
        else if(hex[i] == '4')
        {
            numbers[i]=4;
        }
        else if(hex[i] == '5')
        {
            numbers[i]=5;
        }
        else if(hex[i] == '6')
        {
            numbers[i]=6;
        }
        else if(hex[i] == '7')
        {
            numbers[i]=8;
        }
        else if(hex[i] == '8')
        {
            numbers[i]=8;
        }
        else if(hex[i] == '9')
        {
            numbers[i]=9;
        }
        else if(toupper(hex[i]) == 'A')
        {
            numbers[i]=10;
        }
        else if(toupper(hex[i]) == 'B')
        {
            numbers[i]=11;
        }
        else if(toupper(hex[i]) == 'C')
        {
            numbers[i]=12;
        }
        else if(toupper(hex[i]) == 'D')
        {
            numbers[i]=13;
        }
        else if(toupper(hex[i]) == 'E')
        {
            numbers[i]=14;
        }
        else if(toupper(hex[i]) == 'F')
        {
            numbers[i]=15;
        }
        else
        {
            cout << "Error in input\n";
            system("PAUSE");
            exit(0);
        }
        i++;

    }
    for(int j=i; j<MAX; j++)
    {
        numbers[j]=0;
    }

}



/*---------------------------------------------------------------------------------------
 *Name - AddHex
 *Arguments - 3 int arrays
 *Return values - none, changes done in arrays.
 *Description - does the math for adding hex and assigns them to a solutions array.
 *Notes - 1/13 had issues at the beginning dealing with array size. Would be hard to add differently sized arrays
                made easy by setting arrays to the same size and filling them with 0s done in HexToNum.
-----------------------------------------------------------------------------------------*/
void AddHex(int numbers1[], int numbers2[], int solution[])
{
    for(int i=0; i<MAX; i++)
    {
        solution[i] = 0;
    }
    for(int j=0; j<MAX; j++)
    {
        solution[j] = numbers1[j]+numbers2[j];

        while(solution[j] >= 16)
        {

            solution[j] -=16;
            j++;
            solution[j] = 1  + numbers1[j]+numbers2[j];

        }

    }
}




/*---------------------------------------------------------------------------------------
 *Name - NumToHex
 *Arguments - character array, int array
 *Return values - none changes done in the arrays.
 *Description - changes the num values back into hex values.
 *Notes - 1/13 simply the reverse of HexToNum
-----------------------------------------------------------------------------------------*/
void NumToHex(char hexSolution[], int numSolution[])
{
    for(int i=0; i< MAX+1; i++)
    {
        if(numSolution[i] == 0)
        {
            hexSolution[i] = '0';
        }
        else if(numSolution[i] == 1)
        {
            hexSolution[i] = '1';
        }
        else if(numSolution[i] == 2)
        {
            hexSolution[i] = '2';
        }
        else if(numSolution[i] == 3)
        {
            hexSolution[i] = '3';
        }
        else if(numSolution[i] == 4)
        {
            hexSolution[i] = '4';
        }
        else if(numSolution[i] == 5)
        {
            hexSolution[i] = '5';
        }
        else if(numSolution[i] == 6)
        {
            hexSolution[i] = '6';
        }
        else if(numSolution[i] == 7)
        {
            hexSolution[i] = '7';
        }
        else if(numSolution[i] == 8)
        {
            hexSolution[i] = '8';
        }
        else if(numSolution[i] == 9)
        {
            hexSolution[i] = '9';
        }
        else if(numSolution[i] == 10)
        {
            hexSolution[i] = 'A';
        }
        else if(numSolution[i] == 11)
        {
            hexSolution[i] = 'B';
        }
        else if(numSolution[i] == 12)
        {
            hexSolution[i] = 'C';
        }
        else if(numSolution[i] == 13)
        {
            hexSolution[i] = 'D';
        }
        else if(numSolution[i] == 14)
        {
            hexSolution[i] = 'E';
        }
        else if(numSolution[i] == 15)
        {
            hexSolution[i] = 'F';
        }
        hexSolution[MAX] = '\0';
    }


}






/*---------------------------------------------------------------------------------------
 *Name - Print
 *Arguments - character array
 *Return values - none, output array
 *Description - prints the array that has been added.
 *Notes - 1/13 none, simple print array.
-----------------------------------------------------------------------------------------*/

void Print(char array[])
{
    int i=0;
    while(array[i]!= '\0')
    {
        cout << array[i];
        i++;
    }
}
//void Print(int array[])
//{
//    for(int i= 0; i<MAX; i++)
//    {
//        cout << array[i] << ", ";
//    }
//}

/*******************************************************
AADADA
+   FF
=_____
0000AADBD9
Process returned 0 (0x0)   execution time : 0.011 s
Press any key to continue.



AADADZ
+   FF
=_____
Error in input
Press any key to continue . . .

Process returned 0 (0x0)   execution time : 4.253 s
Press any key to continue.



FFFFFFFFFFFFFFFFFFFFF
+                  FF
=____________________
Overflow...
Press any key to continue . . .

Process returned 0 (0x0)   execution time : 3.791 s
Press any key to continue.


*******************************************************/
