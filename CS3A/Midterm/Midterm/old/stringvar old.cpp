#include "stringvar.h"
#include <string.h>


StringVar::StringVar()//default constructor
{
    word = new char[25];
    word[0] = '\0';
}

StringVar::StringVar(char* Word)//single argument constructor
{

    word = new char[strlen(Word)+1];
    strcpy(word, Word);

}

StringVar::StringVar(const StringVar &copyThis)//copy constructor
{

    word = new char [strlen(copyThis.word)+1];
    strcpy(word, copyThis.word);
}

StringVar::~StringVar()//destructor
{
    delete[] word;
}

/*---------------------------------------------------------------------------------------
 *Name - <
 *Arguments - StringVar A, B
 *Return values - if A.word is less than b.word returns 1
 *Description - returns bool
 *Notes -2/18/13 - not too hard, i want to make a function for tolwoer
----------------------------------------------------------------------------------------*/
bool operator <(const StringVar &A, const StringVar &B)
{
    if(strcmp(ToLower(A),ToLower(B)) < 0)
        return 1;
    else
        return 0;

}

/*---------------------------------------------------------------------------------------
 *Name - <=
 *Arguments - StringVar A, B
 *Return values - if A.word is less or equal than b.word returns 1
 *Description - returns bool
 *Notes -2/18/13 - not too hard, i want to make a function for tolwoer
----------------------------------------------------------------------------------------*/
bool operator <=(const StringVar &A, const StringVar &B)
{
    if(strcmp(ToLower(A),ToLower(B)) <= 0)
        return 1;
    else
        return 0;

}


/*---------------------------------------------------------------------------------------
 *Name - ==
 *Arguments - StringVar A, B
 *Return values - if words are equal returns 1
 *Description - returns bool
 *Notes -2/18/13 - not too hard, i want to make a function for tolwoer
----------------------------------------------------------------------------------------*/
bool operator ==(const StringVar &A, const StringVar &B)
{

//    for(int i = 0; i< strlen(A.word); i++)
//    {
//        A.word[i] = tolower(A.word[i]);
//    }
//    for(int i = 0; i< strlen(B.word); i++)
//    {
//        B.word[i] = tolower(B.word[i]);
//    }
    if(strcmp(ToLower(A),ToLower(B)) == 0)
        return 1;
    else
        return 0;

}
/*---------------------------------------------------------------------------------------
 *Name - >
 *Arguments - StringVar A, B
 *Return values - if A.word is greater than b.word returns 1
 *Description - returns bool
 *Notes -2/18/13 - not too hard, i want to make a function for tolwoer
----------------------------------------------------------------------------------------*/
bool operator >(const StringVar &A, const StringVar &B)
{
    if(strcmp(ToLower(A),ToLower(B)) > 0)
        return 1;
    else
        return 0;

}

bool operator >=(const StringVar &A, const StringVar &B)
{
    if(strcmp(ToLower(A),ToLower(B)) >= 0)
        return 1;
    else
        return 0;

}
/*---------------------------------------------------------------------------------------
 *Name - =
 *Arguments - StringVar copyThis
 *Return values - if A.word is less than b.word returns 1
 *Description - returns bool
 *Notes -2/18/13 - not too hard, i want to make a function for tolwoer
----------------------------------------------------------------------------------------*/
StringVar& StringVar::operator =(const StringVar &copyThis)
{
    word = new char [strlen(copyThis.word)+1];
    strcpy(word, copyThis.word);

    return *this;

}

/*---------------------------------------------------------------------------------------
 *Name - <<
 *Arguments - ostream out, stringvar A
 *Return values - out ostream
 *Description - outputs a char string
 *Notes -2/18/13 - not too hard
----------------------------------------------------------------------------------------*/
ostream &operator <<(ostream &out, const StringVar &A)
{
    out << A.word;

    return out;
}

/*---------------------------------------------------------------------------------------
 *Name - GetWord
 *Arguments - char* block, int start
 *Return values - returns a StingVar object with a word
 *Description - gets a word, then sets the next start place
 *Notes -2/18/13 - not too bad, had a bit of issues getting start position correctly.
----------------------------------------------------------------------------------------*/
StringVar StringVar::GetWord(char* block, int &start)
{
    int count = 0;
    int nonChar=0;

    char* word = new char [25];
    int i = start;
    while(isalpha(block[i]))
    {
        count++;
        i++;
    }
    while(!isalpha(block[i]) && i<strlen(block))
    {
        nonChar++;
        i++;
    }


    //cout << "Count : "  << count << endl;
    for(i = 0; i<count; i++)
    {
        word[i] = block[start+i];
        //cout << "Appending Letter\n";
    }
    word[i] = '\0';

    start = start+count+nonChar;
//    cout << "Start = " << start << endl;

    return StringVar(word);
}


/*---------------------------------------------------------------------------------------
 *Name - ToLower
 *Arguments - StringVar A
 *Return values - returns a charpointer lowercased from stringvar
 *Description - returns a charpointer lowercased from stringvar
 *Notes -2/18/13 - had trouble, thenmade it a friend and it worked out.
----------------------------------------------------------------------------------------*/
char* ToLower(const StringVar A)
{
    char* lowercase = new char[strlen(A.word)+1];

    int i;
    for(i=0; i<strlen(A.word); i++)
    {
        lowercase[i] = char(tolower(A.word[i]));
    }
    lowercase[i] = '\0';
    return lowercase;
}
