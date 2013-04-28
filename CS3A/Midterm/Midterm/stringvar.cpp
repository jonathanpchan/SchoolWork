#include "stringvar.h"
#include <string.h>


StringVar::StringVar()//default constructor
{
    cout << "stringvar default\n";
    word = new char[25];
    word[0] = '\0';
}

StringVar::StringVar(char* Word)//single argument constructor
{
    cout << "stingvar constructor\n";
    cin.get();
    word = new char[strlen(Word)+1];
    strcpy(word, Word);
    delete [] Word;

}

StringVar::StringVar(const StringVar &copyThis)//copy constructor
{
    cout << "string var copy\n";
    word = new char [strlen(copyThis.word)+1];
    strcpy(word, copyThis.word);
}

StringVar::~StringVar()//destructor
{
    delete [] word;
    cout << "bye\n";
    cin.get();
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

    cout << "<\n";
        cin.get();

    char* word1 = ToLower(A);
    char* word2 = ToLower(B);

    if(strcmp(word1,word2) < 0)
    {
        delete [] word1;
        delete [] word2;
        return 1;
    }
    else
    {
        delete word1;
        delete word2;
        return 0;
    }

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


        cout << "<=\n";
    cin.get();
    char* word1 = ToLower(A);
    char* word2 = ToLower(B);

    if(strcmp(word1,word2) <= 0)
    {
        delete [] word1;
        delete [] word2;
        return 1;
    }
    else
    {
        delete word1;
        delete word2;
        return 0;
    }

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

        cout << "==\n";
    cin.get();
    char* word1 = ToLower(A);
    char* word2 = ToLower(B);

    if(strcmp(word1,word2) == 0)
    {
        delete [] word1;
        delete [] word2;
        return 1;
    }
    else
    {
        delete word1;
        delete word2;
        return 0;
    }

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

    cout << ">\n";
    cin.get();
    char* word1 = ToLower(A);
    char* word2 = ToLower(B);

    if(strcmp(word1,word2) > 0)
    {
        delete [] word1;
        delete [] word2;
        return 1;
    }
    else
    {
        delete word1;
        delete word2;
        return 0;
    }

}

bool operator >=(const StringVar &A, const StringVar &B)
{
    cout << ">=\n";
        cin.get();

    char* word1 = ToLower(A);
    char* word2 = ToLower(B);

    if(strcmp(word1,word2) >= 0)
    {
        delete [] word1;
        delete [] word2;
        return 1;
    }
    else
    {
        delete word1;
        delete word2;
        return 0;
    }

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
    cout << "stringvar assignment\n";
        cin.get();
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
   cout << "cout strvar\n";
       cin.get();
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
    cout << "get word\n";
        cin.get();
    int count = 0;
    int nonChar=0;

    char word[25];
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
    cout << "ToLower\n";
        cin.get();
    char* lowercase;
    try    {
        lowercase = new char[strlen(A.word)+1];
    }
    catch (bad_alloc& ba){
        cout<<"found you!!!";
        cin.get();
    }
    catch(...){
        cout << "TO LOWER IS BROKEN!!!!" << endl;
    }
    int i;
    for(i=0; i<strlen(A.word); i++)
    {
        lowercase[i] = char(tolower(A.word[i]));
    }
    lowercase[i] = '\0';
    return lowercase;
}


void StringVar::explode()
{
    cout << "explode\n";
        cin.get();
    delete [] word;
}
