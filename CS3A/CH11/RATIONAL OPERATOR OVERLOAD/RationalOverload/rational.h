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


    void GetFraction();
    Rational Add(Rational b);
    Rational Subtract(Rational b);
    Rational Mutiply(Rational b);
    Rational Divide(Rational b);
    void Negative();
    bool LessThan(Rational b);
    bool Equals(Rational b);
    void Simplify();




    friend ostream & operator <<(ostream &out, const Rational A);
    friend Rational  operator +(Rational A, Rational B);
    friend Rational  operator -(Rational A, Rational B);
    friend Rational  operator *(Rational A, Rational B);
    friend Rational  operator /(Rational A, Rational B);
    friend bool  operator <(Rational A, Rational B);
    friend bool  operator ==(Rational A, Rational B);



private:
    int numerator;
    int denominator;


};

#endif // RATIONAL_H
