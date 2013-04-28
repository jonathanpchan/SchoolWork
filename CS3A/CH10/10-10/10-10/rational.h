#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
    Rational();//default constructor
    Rational(int Num, int Denom);//constructor with terms, does not allow denom =0
    Rational(int Num);//construtor for ints, as they are also rational numbers


    void GetFraction();//outputs a Rational
    Rational Add(Rational b);//adds two rationals
    Rational Subtract(Rational b);//subtracts two rationals
    Rational Multiply(Rational b);//multiplies two rationals
    Rational Divide(Rational b);//divides two rationals
    Rational Negative();//makes rational negative
    bool LessThan(Rational b);//checks which rational is smaller
    bool Equals(Rational b);//checks if rationals are equal
    Rational Simplify();


private:
    int numerator;
    int denominator;


};

#endif // RATIONAL_H
