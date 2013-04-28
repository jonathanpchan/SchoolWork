#ifndef STRINGVAR_H
#define STRINGVAR_H

#include <iostream>

using namespace std;


class StringVar
{
public:
    StringVar();//default constructor
    StringVar(char* Word);//one argument constructor
    StringVar(const StringVar &copyThis);//copy constructor
    ~StringVar();//destructor

    friend bool operator <(const StringVar &A, const StringVar &B);//less than
    friend bool operator <=(const StringVar &A, const StringVar &B);//less than or equal

    friend bool operator ==(const StringVar &A, const StringVar &B);//equivalent
    friend bool operator >(const StringVar &A, const StringVar &B);//greater than
    friend bool operator >=(const StringVar &A, const StringVar &B);//greater than

    friend ostream &operator <<(ostream &out, const StringVar &A);//outputs
    StringVar &operator =(const StringVar &copyThis);//overload equal operator
    StringVar GetWord(char* block, int &start);//gets a word

    friend char* ToLower(StringVar A);//turns a string var to lower

    void explode();


private:
    char* word;

};

#endif // STRINGVAR_H
