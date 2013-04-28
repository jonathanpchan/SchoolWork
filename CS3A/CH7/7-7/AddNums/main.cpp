/**************************************
Project:7-7 Base Addition

Author: Jonathan Chan

Description:This program uses pointers to add numbers of any base

Notes: 1/13/2012 Did the whole project. Had trouble with reversing. Adding was okay had troubles finding a solution for nice formatting. Ended up filling arrays with 0s
       1/23/2012 Changed BaseToNum and NumToBase to return int/char respectively
       1/24/2012 Fixed other functions to work with the new returns, added a padding function.
**************************************/

#include <iostream>
#include <cstdlib>
#include <string.h>


using namespace std;

void AddBase(char base1[], char base2[], char solution[]);//adds the array.
void Reverse(char reversed[]); //reverses the array to allow easier math
int BaseToNum(char base);//converts the hex to integers for easier math;
char NumToBase(int num);//converts back  to hex for display.
void Print(char array[]);//prints the array
void PadArray(char base1[], char base2[]);//fills smaller array with '0's up to length of the larger array


int const MAX=10;
int const BASE=16;

int main()
{
    char baseNum1[MAX], baseNum2[MAX], baseSol[MAX+1];

    strcpy(baseNum1, "10101adadad010");
    strcpy(baseNum2, "1");

    cout << baseNum1<< "+" << baseNum2 << "=" << endl;

    Reverse(baseNum1);
    Reverse(baseNum2);
    PadArray(baseNum1, baseNum2);

    AddBase(baseNum1, baseNum2, baseSol);
    Reverse(baseSol);

    cout << baseSol << endl;

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
 *Return values - returns an int value based off the index of the array
 *Description - returns the numerical value of a certain base up to 16.
 *Notes - 1/13 Started without filling array with 0s, ended up doing it to get around adding differently
                sized arrays in HexAdd
          1/23 removed the fill, changes it to return based off the index of the array.
-----------------------------------------------------------------------------------------*/
int BaseToNum(char base)
{
    char BaseTable[16+1] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0'};

    for(int i=0; i<16; i++)
    {
        if(toupper(base)==BaseTable[i])
        {
            if(i>=BASE)
            {
                cout << "Error With Base\n";
                system("pause");
                exit(0);

            }
            return i;
        }
    }

}

/*---------------------------------------------------------------------------------------
 *Name - AddBase
 *Arguments - 3 int arrays
 *Return values - none, changes done in arrays.
 *Description - does the math for adding hex and assigns them to a solutions array.
 *Notes - 1/13 had issues at the beginning dealing with array size. Would be hard to add differently sized arrays
                made easy by setting arrays to the same size and filling them with 0s done in HexToNum.
          1/24 changed to fit new functions.
-----------------------------------------------------------------------------------------*/
void AddBase(char base1[], char base2[], char solution[])
{
    int i, num, carry = 1;
    bool sizeUp;
    for(i=0; i<strlen(base1); i++)
    {
        sizeUp=0;
        num = BaseToNum(base1[i])+BaseToNum(base2[i]);
        //cout << "num before carry(if carry at all): " << num << endl;

        solution[i] = NumToBase(num);
        while(num/BASE == 1)
        {
            solution[i] = NumToBase(num%BASE);
            //cout << "num modded: " << num%BASE << "=" << solution[i] << endl;
            i++;
            //cout << "carry\n";
            num = carry + BaseToNum(base1[i])+BaseToNum(base2[i]);
            //cout << "next num after carry: " << num << endl;
            solution[i] = NumToBase(num);
            sizeUp =1;
        }
    }

    if(sizeUp==0)
    {
        solution[i] = '\0';
    }
    else if(sizeUp == 1);
    {
        solution[i+1] = '\0';
    }
}
/*---------------------------------------------------------------------------------------
 *Name - NumToHex
 *Arguments - character array, int array
 *Return values - returns a character
 *Description - changes the num values back into hex values.
 *Notes - 1/13 simply the reverse of HexToNum
 *        1/23 changed it to change it back to char for an integer value.
 *
-----------------------------------------------------------------------------------------*/
char NumToBase(int num)
{
    if(num>=0 && num <=9)
    {
        return(num+48);//adds 48 to get the number
    }
    else
    {
        return(num+55);//adds 55 to get everything higher than 9
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

/*---------------------------------------------------------------------------------------
 *Name - PadArray
 *Arguments - character arrays
 *Return values - none, changes done in array
 *Description - adds 0s the the shorter length array.
 *Notes - 1/24 - not too bad since I changed HexToNum I needed to pad the array again.
-----------------------------------------------------------------------------------------*/
void PadArray(char base1[], char base2[])
{
    if(strlen(base1)>strlen(base2))
    {
        int i;
        for(i = strlen(base2); i<strlen(base1); i++)
        {
            base2[i] = '0';
        }
        base2[i] = '\0';
    }
    else if(strlen(base2)>strlen(base1))
    {
        int i;
        for(i = strlen(base1); i<strlen(base2); i++)
        {
            base1[i] = '0';
        }
        base1[i] = '\0';
    }
}







