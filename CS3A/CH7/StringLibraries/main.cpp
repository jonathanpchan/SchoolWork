/*-----------------------------------------------------------------------------------------
Project: String Libraries
Author: Jonathan Chan
Description: Different string functions rewritten better.
Notes: 1/14 StrLen, StrCpy, StrCat all simple.
       1/16 InStr w/ ch not too bad troubles with InStr w/ str
       1/27 InStr fixed very silly bug. InStrAny/InStrNotAny not too difficulty
            Verify Email was not too bad when using the functions written.

-----------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int StrLen(char array[]);//gets the length of the string
void StrCpy(char destination[],char target[]);//copies the string from target array to destination array
void StrCat(char destination[],char concat[]);//adds the concat array to the destination array.
//void StrStr(char source[], char compare[], char destination[]);//Finds a string in a string and outputs the string and what follows in another array.

int InStr(char source[], char ch, int start=0, int end=-1);//finds a char in a str
int InStr(char source[], char find[], int start=0, int end=-1);// finds a str in a str
int InStrAny(char source[], char any[], int start=0, int end =-1);//finds the first thing in array 1 also in array 2
int InStrNotAny(char source[], char any[],int start=0, int end=-1);//finds the first instance of something that is in array 1 that is not in array 2

void Left(char source[], int length, char result[]);//gets the left chars to the length
void Right(char source[], int length, char result[]);//gets the characters at the end of the string
void SubStr(char source[], int start, int length, char result[]);//gets something from the middle.

bool VerifyEmail(char email[]);//verifys an email.
int main()
{
    char email[100];




    StrCpy(email, "joe.b@com");

    cout << "email: " << email<<endl;\

    if(!VerifyEmail(email))
    {
        cout << "Invalid Email\n";
    }
    else
    {
        cout << "Valid Email\n";
    }

    return 0;
}

/*---------------------------------------------------------------------------------------
 *Name - StrLen
 *Arguments - char array
 *Return values - Returns the length of the string.
 *Description - uses a counter to add until it hits the null character and returns that value
 *Notes -1/14/13 - Pretty simple, not sure if anything else is needed from this function..
-----------------------------------------------------------------------------------------*/
int StrLen(char array[])
{
    int i=0;
    while(array[i] != '\0')
    {
        i++;
        //cout << "strlen calculating\n";
    }
    return(i);
}

/*---------------------------------------------------------------------------------------
 *Name - StrCpy
 *Arguments - destination array and target array
 *Return values - none, changes done through arrays
 *Description - Uses StrLen as a barrier for size... Copies from target into destination.
 *              Assigns the null char to make it a string.
 *Notes -1/14/13 - Simple so far.. not sure if size of arrays will be an issue right now.
-----------------------------------------------------------------------------------------*/
void StrCpy(char destination[],char target[])
{
    for(int i=0; i<StrLen(target); i++)
    {
        destination[i] = target[i];
    }

    destination[StrLen(target)] = '\0';
}

/*--------------------------------------------------------------------------------------
 *Name - StrCat
 *Arguments - destination array and concat array
 *Return values - none, changes done through arrays
 *Description - Uses StrLen to know when to add, and adds both the StrLengths to determine
 *              the position  for the null char
 *Notes -1/14/13 - can StrCpy be used? not sure, str copy starts from 0 so im thinknig no;
-----------------------------------------------------------------------------------------*/
void StrCat(char destination[],char concat[])
{
    int totalLength= StrLen(destination)+StrLen(concat), startLength = StrLen(destination);
//    cout << "destination length: " << StrLen(destination) << endl;
//    cout << "concat length: " << StrLen(concat) << endl;


      for(int i = 0; i<StrLen(concat); i++)
    {
        destination[startLength+i]=concat[i];
    }
    destination[totalLength]='\0';

//    cout << "total length:" <<totalLength<< endl;
}

/*--------------------------------------------------------------------------------------
 *Name - InStr
 *Arguments - source array, character, start end
 *Return values - returns the position of the char in the array
 *Description - finds a character in a source string, and returns the position it is in in the array, otherwise returns -1
 *
 *Notes -1/16/13 - not too hard, had some issues finding out how to implement end.
-----------------------------------------------------------------------------------------*/
int InStr(char source[], char ch, int start, int end)
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
int InStr(char source[], char find[], int start, int end)
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

/*--------------------------------------------------------------------------------------
 *Name - InStrAny
 *Arguments - source array, find array, star,t end
 *Return values - returns the position of the first character in array 1 that is also found in array 2
 *Description - finds a char in a source string, minimzes to find the first instace.
 *
 *Notes - 1/27 bit of trouble to start but was not too bad in the end.
 *
-----------------------------------------------------------------------------------------*/
int InStrAny(char source[], char any[],int start, int end)
{
    int startPos=start, found=StrLen(source)+1;//maximizes using the strlen

    for(int i=0; i<StrLen(any); i++)
    {
        if(InStr(source, any[i], start, end) < found && InStr(source, any[i], start, end) != -1)
        {
            found=InStr(source, any[i], start, end);
        }
    }
    if(found==StrLen(source)+1)
    {
        return -1;
    }
    return found;
}

/*--------------------------------------------------------------------------------------
 *Name - InStrNotAny
 *Arguments - source array, find array, star,t end
 *Return values - returns the position of the first character in array 2 that is not found in array 1
 *Description - finds the first instance of a character that is in array 2 and is not found in the source array.
 *
 *Notes - 1/27 pretty easy. *
-----------------------------------------------------------------------------------------*/
int InStrNotAny(char source[], char any[],int start, int end)
{

    for(int i=0; i<StrLen(source); i++)
    {
        if(InStr(any, source[i], start, end) == -1)
        {
            //cout <<"didnt find any[" <<i<<"] " << any[i] << endl;
            return i;
        }
    }
    return -1;//if everything is found.

}

/*--------------------------------------------------------------------------------------
 *Name - Left
 *Arguments - source array, length, result array
 *Return values - changes done in arrays
 *Description - up to the length gets the leftmost characters and places in results
 *
 *Notes -1/22/13 - farily simple
-----------------------------------------------------------------------------------------*/
void Left(char source[], int length, char result[])
{
    int i;
    for(i=0; i<length; i++)
    {
        result[i] = source[i];
    }
    result[i] = '\0';

}

/*--------------------------------------------------------------------------------------
 *Name - Right
 *Arguments - source array, length, result array
 *Return values - changes done in arrays
 *Description - up to the length gets the right characters and places in results
 *
 *Notes -1/22/13 - farily simple
-----------------------------------------------------------------------------------------*/
void Right(char source[], int length, char result[])
{

    int i, start = (StrLen(source)-length);

    for(i=0; i<length; i++)
    {
        result[i]=source[start+i];
    }
    result[i]='\0';
}

/*--------------------------------------------------------------------------------------
 *Name - SubStr
 *Arguments - source array, length, start point result array
 *Return values - changes done in arrays
 *Description - from the specified start point, goes to length and copies that into a new array
 *
 *Notes -1/22/13 - farily simple
-----------------------------------------------------------------------------------------*/
void SubStr(char source[], int start, int length, char result[])
{
    int i;

    for(i=0; i<length; i++)
    {
        result[i]=source[start+i];
    }
    result[i] = '\0';
}


/*--------------------------------------------------------------------------------------
 *Name - Verify Email
 *Arguments - single character array
 *Return values - boolean return
 *Description - checks emails, splits it into multiple parts, checks different parts for validity.
 *              if everything works email is valid.
 *Notes -1/28/13 - not too hard to use the seperate functions to split username/domain/topdomain
 *                 found bug in InStrAny which I fixed during testing this.
-----------------------------------------------------------------------------------------*/
bool VerifyEmail(char email[])
{
    char username[100];
    char domain[100];
    char topDomain[100];
    char validChars[100];
    char validTopDomains[4][3+1];

    StrCpy(validChars, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&'*+-/=?^_`{|}~.)");
    StrCpy(validTopDomains[0], "com");
    StrCpy(validTopDomains[1], "net");
    StrCpy(validTopDomains[2], "org");
    StrCpy(validTopDomains[3], "edu");



    bool invalid = 0, valid = 1;

    int atPos=0, dotPos =0, domainLength=0, topDomainLength=0, check=0;

    atPos = InStr(email, '@');//finds at position
    dotPos = InStr(email, '.', atPos);//finds any '.' starting from the @ position.
    domainLength = dotPos-atPos-1;
    topDomainLength = StrLen(email)-dotPos-1;

//    cout << "@pos: " << atPos << endl;
//    cout << ".pos: " << dotPos << endl;

    Left(email, atPos, username);
    cout << "username: " << username << endl;

    SubStr(email,atPos+1, domainLength, domain);
    cout << "domain: " << domain << endl;

    Right(email, topDomainLength, topDomain);
    for(int i=0; i<topDomainLength; i++)
    {
        topDomain[i] = tolower(topDomain[i]);
    }
    cout << "topDomain: " << topDomain << endl;

    //checks
    if(StrLen(username)<1 || StrLen(domain)<1 || StrLen(topDomain)<1)//check length of username, domain, and topDomain.
    {
        return invalid;
    }

    if(InStrNotAny(username, validChars)!=-1)//if not -1 something was not found, therefore invalid(domain)
    {
        cout << "Bad Username\n";
        return invalid;
    }
    if(InStrNotAny(domain,validChars)!= -1)//if not -1 something was not found, therefore invalid(domain)
    {
        cout << "Bad Domain\n";
        return invalid;
    }


    //topdomain check
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(topDomain[j] == validTopDomains[i][j])
            {
                if(check==StrLen(topDomain))
                {
                    return valid;
                }
                check++;
            }
        }

    }
    return invalid;
}


