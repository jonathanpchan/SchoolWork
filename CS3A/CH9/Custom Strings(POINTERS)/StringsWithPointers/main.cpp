/*-----------------------------------------------------------------------------------------
Project: String Libraries With Pointers
Author: Jonathan Chan
Description: Different string functions rewritten better. NOW WITH POINTERS!
Notes: 1/28 changed to pointers, was not too difficult to do. pointer logic is different
            than array logic, not completely used to it yet. Learned new if statements...
-----------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int StrLen(char* array);//gets the length of the string

char* StrCpy(char* target);//copies the string from target array to destination array
char* Left(char* source, int length);//gets the left chars to the length
char* Right(char* source, int length);//gets the characters at the end of the string
char* SubStr(char* source, int start, int length);//gets something from the middle.
char* StrStr(char* source, char* find);//returns pointer to where find was found in source.

int InStr(char* source, char ch, int start=0, int end=-1);
int InStr(char* source, char* find, int start=0, int end=-1);

int main()
{
    char* test;
    char* hold;
    test = new char[100];
    hold = new char[100];

    hold = StrCpy("ABCD1234");
    cout << hold << endl;
    cout << "StrLen: " << StrLen(hold) << endl;

    test = Left(hold,4);
    cout << "Left 4 : " << test << endl;

    test = Right("ABCD1234",4);
    cout << "Right 4 : " << test << endl;

    test = SubStr("ABCD1234",2,4);
    cout << "SubStr Start @ 2 Copy 4 : " << test << endl;

    test = StrStr("ABCD1234", "CD");
    cout << "StrStr \"cd\"\n" << test << endl;

    return 0;
}

/*---------------------------------------------------------------------------------------
 *Name - StrLen
 *Arguments - char pointer
 *Return values - Returns the length of the string.
 *Description - uses a counter to add until it hits the null character and returns that value
 *Notes -1/28/13 - Not too hard, simply incrementing the pointer instead
-----------------------------------------------------------------------------------------*/
int StrLen(char* array)
{
    int i=0;
    while(*array)
    {
        array++;
        i++;
        //cout << "strlen calculating\n";
    }
    return(i);
}

/*---------------------------------------------------------------------------------------
 *Name - StrCpy
 *Arguments - char pointer
 *Return values - char pointer to the string
 *Description - Uses StrLen as a barrier for size... Copies from target into destination.
 *              Assigns the null char to make it a string.
 *Notes -1/28/13 - takes only 1 argument now, logic is pretty much the same.

-----------------------------------------------------------------------------------------*/
char* StrCpy(char* target)
{
    char* destination;
    destination = new char[100];

    int i;
    for(i=0; i<StrLen(target); i++)
    {
        destination[i] = target[i];
    }    

    destination[i] = '\0';

    return destination;
}

/*--------------------------------------------------------------------------------------
 *Name - Left
 *Arguments - char pointer, length
 *Return values - char pointer to the string
 *Description - up to the length gets the leftmost characters and places in results
 *Notes -1/28/13 - farily simple using new logic to copy the pointers into a new pointer
-----------------------------------------------------------------------------------------*/
char* Left(char* source, int length)
{
    char* result =  new char[100];
    char* holdThis;

    holdThis=result;

    int size = StrLen(source);//size of string
    int copyLength = length>size?size:length;//if length is longer than string copy to size, else copy to length
    int i=0;

    while(i<copyLength)
    {
        *result++ = *source++;
        i++;
    }
    *result='\0';

    return holdThis;
}

/*--------------------------------------------------------------------------------------
 *Name - Right
 *Arguments - source array, length
 *Return values - char pointer to the new string
 *Description - up to the length gets the right characters and places in results
 *
 *Notes -1/28/13 - farily simple, similar to Left, had a bit of issues with
                    understanding how to add to poineters, but okay now.
-----------------------------------------------------------------------------------------*/
char* Right(char* source, int length)
{
    char* result = new char[100];
    char* holdThis;
    holdThis=result;

    int i=0, start = (StrLen(source)-length), size=StrLen(source);
    int copyLength = length>size?size:length;

    source+=start;

    while(i<copyLength)
    {
        *result++ = *source++;
        i++;
    }
    *result='\0';

    return holdThis;
}

/*--------------------------------------------------------------------------------------
 *Name - SubStr
 *Arguments - char pointer, start point, length
 *Return values - changes done in arrays
 *Description - from the specified start point, goes to length and copies that into a new array
 *
 *Notes -1/28/13 - farily simple very similar to Right, only changing start position.
-----------------------------------------------------------------------------------------*/
char* SubStr(char* source, int start, int length)
{
    char* result = new char[100];
    char* holdThis;
    holdThis=result;

    int i=0, size=StrLen(source);
    int copyLength = length>size?size:length;

    if(start>size)
        start=0;//if starting position is greater than the size start from the beginning.

    source+=start;

    while(i<copyLength)
    {
        *result++ = *source++;
        i++;
    }
    *result='\0';
    return holdThis;
}

/*--------------------------------------------------------------------------------------
 *Name - StrStr
 *Arguments - two char pointers.
 *Return values - returns the location of where the second pointer was found in the first pointer
 *Description - if the second pointer can be found in the first pointer, returns the position
                where it starts, other wise returns null
 *Notes -1/28/13 - Started by copying to new array, fixed so it just returns the location
                   of where it was found.
-----------------------------------------------------------------------------------------*/
char* StrStr(char* source, char* find)
{
//    int startPos=InStr(source, find);


//    if(startPos!=-1)
//    {
//        source = source+startPos;
//        return source;
//    }
//    else
//    {
//        return (NULL);
//    }
   return InStr(source, find)!=-1?source+InStr(source, find):(NULL);//one line return, if it finds something, its != -1 so returns position, otherwise NULL.
}

/*--------------------------------------------------------------------------------------
 *Name - InStr
 *Arguments - source array, character, start end
 *Return values - returns the position of the char in the array
 *Description - finds a character in a source string, and returns the position it is in in the array, otherwise returns -1
 *
 *Notes -1/16/13 - not too hard, had some issues finding out how to implement end.
-----------------------------------------------------------------------------------------*/
int InStr(char* source, char ch, int start, int end)
{
    if(start >= StrLen(source))
        return -1;

    if(end==-1 || end > StrLen(source))
    {
        end=StrLen(source);
    }

    for(int i = start; i<end; i++)
    {
        if(ch==source[i])
        {
            return(i);
        }
    }

    return(-1);
}

/*--------------------------------------------------------------------------------------
 *Name - InStr
 *Arguments - source array, find array, start end
 *Return values - if string is found, returns the index of the first character of that string in the source array.
 *Description - finds a string in a source string, and returns the position it is in in the array, otherwise returns -1
 *
 *Notes -1/16/13 - troubles getting it to work completly. if source=aabc and find =abc returns 0;
 *       1/27/13 - stupid bug found, incremented too early caused issues. check++ was before the if.
 *                 added the start and end compatability.
-----------------------------------------------------------------------------------------*/
int InStr(char* source, char* find, int start, int end)
{
    //cout << "end" << end << endl;
    if(end==-1)
    {
        end=StrLen(source);
    }
    int startPos=start, check=0;
    for(int i=0; i<end; i++)
    {
        // << "Loop #: " << i << endl;
        if(InStr(source, find[0], startPos, end) != -1)//if something is found
        {
            startPos=i;//set a temporary start position
            check++;//set a check that if it is not equal to the length of find[]

            //cout << "startPosition: " << startPos << endl;
            //cout << "check =  " << check << endl;

            for(int j=0; j<StrLen(find); j++)//something maybe an issue here if there are more characters than the length of the second string before the string to be found it breaks
            {
                if(source[startPos+j]==find[j])
                {
                    if(check==StrLen(find))
                    {
                        //cout << "FOUND THE FULL STRING\n";
                        return (startPos);
                    }
                    check++;
                    //cout << "CHECK = " << check << endl;
                }
            }
            check=0;
            startPos++;
            //cout << "startPos" << startPos << endl;
            //cout << "Reset Check: " << check << endl;
        }
    }
    return (-1);
}
