#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;


class Rational
{
public:
    Rational();
    Rational(int Num, int Denom);
    Rational(int Num);



    void GetFraction();//gets fraction
    Rational Simplify();//simplifies

    friend ostream& operator <<(ostream &out, const Rational &A);//outputs
    friend istream& operator >>(istream &ins, Rational &A);//input
    friend Rational operator +(const Rational &A, const Rational &B);//adds rationals
    friend Rational operator -(const Rational &A, const Rational &B);//subtracts rationals
    friend Rational operator *(const Rational &A, const Rational &B);//multiplies rationals
    friend Rational operator /(const Rational &A, const Rational &B);//divides rationals
    friend bool operator <(const Rational &A, const Rational &B);//bool less than
    friend bool operator <=(const Rational &A, const Rational &B);//bool less than or equals
    friend bool operator >(const Rational &A, const Rational &B);//bool greater than
    friend bool operator >=(const Rational &A, const Rational &B);//bool greater than or equals
    friend bool operator ==(const Rational &A, const Rational &B);//bool equals




private:
    int numerator;
    int denominator;


};

#endif // RATIONAL_H
