#ifndef POLYTERM_H
#define POLYTERM_H
#include <iostream>

using namespace std;

class polyterm
{
public:
    polyterm();
    polyterm(int Coefficient, int Exponent);
//    polterm(const polyterm& copyThis);
//    polyterm operator =(const polyterm& copyThis);
//    ~polyterm;
    polyterm(const polyterm& a);

    polyterm& operator =(const polyterm& a);

    friend bool operator >=(const polyterm& a, const polyterm& b);
    friend bool operator <=(const polyterm& a, const polyterm& b);
    friend bool operator >(const polyterm& a, const polyterm& b);
    friend bool operator <(const polyterm& a, const polyterm& b);
    friend bool operator ==(const polyterm &a, const polyterm &b);
    friend bool operator !=(const polyterm& a, const polyterm& b);
    friend polyterm operator +(const polyterm& a, const polyterm& b);
    friend polyterm operator -(const polyterm& a, const polyterm& b);
    friend polyterm operator -(const polyterm& a);
    friend polyterm operator *(const polyterm& a, const polyterm& b);
    int Coef();
    int Exp();


    friend ostream &operator <<(ostream& out, const polyterm& A);//output



private:
    int coef;
    int exponent;
};

#endif // POLYTERM_H
