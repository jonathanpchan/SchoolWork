#ifndef TEXT_H
#define TEXT_H

#include <ctime>


#include "stringvar.h"
class Text
{
public:
    Text();//default constructor
    Text(int num);//one item constructor
    Text(const Text &copyThis);//copy constructor

    ~Text();//destructor
    friend ostream& operator <<(ostream &out, const Text &A);//output
    //friend Text operator +=(const StringVar &B);
    StringVar &operator =(const StringVar &copyThis);//overload equal operator

    void Append(StringVar A);//appends to a text file
    void Reallocate();//increases size
    void ShiftDown(int index);//shifts it down
    int Search(StringVar A);//searches through the text file
    void ReadFile(char* fileName);//reads through the file and tokenizes

private:
    StringVar* words;
    int* frequency;
    int uniqueCount;
    int max;
};

#endif // TEXT_H
