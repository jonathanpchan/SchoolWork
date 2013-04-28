#include "rational.h"
#include <iostream>

using namespace std;

Rational::Rational()
{
    numerator=0;
    denominator=1;
}

Rational::Rational(int Num, int Denom)
{
    numerator=Num;

    if(Denom!=0)
    {
        denominator=Denom;
    }
    else if(Denom==0)
    {
        denominator=1;
    }

}

Rational::Rational(int Num)
{
    numerator=Num;
    denominator = 1;

}


void Rational::GetFraction()
{
    cout << numerator << "/" << denominator << endl;
}

Rational Rational::Add(Rational b)
{
    Rational c;

    c.numerator = (numerator*b.denominator + b.numerator*denominator);
    c.denominator = (denominator * b.denominator);

    c.Simplify();

    return c;
}

Rational Rational::Subtract(Rational b)
{
    Rational c;

    c.numerator = (numerator*b.denominator - b.numerator*denominator);
    c.denominator = (denominator * b.denominator);

    c.Simplify();
    return c;

}

Rational Rational::Mutiply(Rational b)
{
    Rational c;

    c.numerator = numerator * b.numerator;
    c.denominator = denominator * b.denominator;

    c.Simplify();
    return c;
}

Rational Rational::Divide(Rational b)
{
    Rational c;

    c.numerator = numerator * b.denominator;
    c.denominator = b.numerator * denominator;

    c.Simplify();
    return c;

}

void Rational::Negative()
{
    numerator *= -1;
}

bool Rational::LessThan(Rational b)
{
    if((numerator*b.denominator) < (b.numerator * denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Rational::Equals(Rational b)
{
    if((numerator*b.denominator) == (b.numerator * denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Rational::Simplify()
{
    int smaller, divisor = 1;
    if(numerator<denominator)
        smaller=numerator;
    else
        smaller=denominator;

    //cout << "SMALLER = " << smaller << endl;

    for(int i=1; i<=smaller; i++)
    {
        if(numerator%i==0 && denominator%i ==0)
            divisor=i;
    }

    //cout << "DIVISIOR = " << divisor << endl;
    numerator = numerator/divisor;
    denominator = denominator/divisor;
}











ostream &operator <<(ostream &out, const Rational A)
{
    out<<A.numerator << "/" << A.denominator;
    return out;
}

Rational  operator +(Rational A, Rational B)
{
    Rational c;

    c.numerator = (A.numerator*B.denominator + B.numerator*A.denominator);
    c.denominator = (A.denominator * B.denominator);

    c.Simplify();
    return c;

}
Rational  operator -(Rational A, Rational B)
{
    Rational c;

    c.numerator = (A.numerator*B.denominator - B.numerator*A.denominator);
    c.denominator = (A.denominator * B.denominator);

    c.Simplify();
    return c;

}

Rational  operator *(Rational A, Rational B)
{
    Rational c;

    c.numerator = A.numerator * B.numerator;
    c.denominator = A.denominator * B.denominator;

    c.Simplify();
    return c;

}

Rational  operator /(Rational A, Rational B)
{
    Rational c;

    c.numerator = A.numerator * B.denominator;
    c.denominator = B.numerator * A.denominator;

    c.Simplify();
    return c;

}

bool  operator <(Rational A, Rational B)
{
    if((A.numerator*B.denominator) < (B.numerator * A.denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

bool  operator ==(Rational A, Rational B)
{
    if((A.numerator*B.denominator) == (B.numerator * A.denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
