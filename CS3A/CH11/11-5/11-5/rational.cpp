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

/*---------------------------------------------------------------------------------------
 *Name - GetFraction
 *Arguments - numeator/denominator
 *Return values - none used to output.
 *Description - outputs a fraction
 *Notes -2/8/13 - fairly easy
-----------------------------------------------------------------------------------------*/
void Rational::GetFraction()
{
    cout << numerator << "/" << denominator << endl;
}


/*---------------------------------------------------------------------------------------
 *Name - Simplify
 *Arguments - numeator/denominator
 *Return values - a simplified rational
 *Description - finds the greatest divisor, then divides and returns the simplified rational
 *Notes -2/13/13 - had a bit of trouble figuring out the divisor, other than that easy.
-----------------------------------------------------------------------------------------*/
Rational Rational::Simplify()
{
    Rational simplified;
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
    simplified.numerator = numerator/divisor;
    simplified.denominator = denominator/divisor;

    return simplified;
}

/*---------------------------------------------------------------------------------------
 *Name - <<
 *Arguments - rational a
 *Return values - returns ostream
 *Description - outputs fraction
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
ostream& operator <<(ostream &out, const Rational &A)
{
    out << A.numerator << "/" << A.denominator;
    return out;
}

/*---------------------------------------------------------------------------------------
 *Name - >>
 *Arguments - rational a
 *Return values - returns istream
 *Description - inputs fraction
 *Notes -2/13/13 - fairly easy.
-----------------------------------------------------------------------------------------*/
istream& operator >>(istream &in, Rational &A)
{
    char slash;
    in >> A.numerator >> slash >> A.denominator;
    return in;
}


/*---------------------------------------------------------------------------------------
 *Name - +
 *Arguments - two rationals
 *Return values - returns a Rational c
 *Description - adds the fractions
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational operator +(const Rational &A, const Rational &B)
{
    Rational c;

    c.numerator = (A.numerator*B.denominator + B.numerator*A.denominator);
    c.denominator = (A.denominator * B.denominator);

    c.Simplify();
    return c;

}
/*---------------------------------------------------------------------------------------
 *Name - "-"
 *Arguments - two rationals
 *Return values - returns a Rational c
 *Description - subtracts the fractions
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational operator -(const Rational &A, const Rational &B)
{
    Rational c;

    c.numerator = (A.numerator*B.denominator - B.numerator*A.denominator);
    c.denominator = (A.denominator * B.denominator);

    c.Simplify();
    return c;

}

/*---------------------------------------------------------------------------------------
 *Name - "*"
 *Arguments - two rationals
 *Return values - returns a Rational c
 *Description - multiplies the fractions
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational operator *(const Rational &A, const Rational &B)
{
    Rational c;

    c.numerator = A.numerator * B.numerator;
    c.denominator = A.denominator * B.denominator;

    c.Simplify();
    return c;

}

/*---------------------------------------------------------------------------------------
 *Name - "/"
 *Arguments - two rationals
 *Return values - returns a Rational c
 *Description - divides the fractions
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational operator /(const Rational &A, const Rational &B)
{
    Rational c;

    c.numerator = A.numerator * B.denominator;
    c.denominator = B.numerator * A.denominator;

    c.Simplify();
    return c;

}

/*---------------------------------------------------------------------------------------
 *Name - <
 *Arguments - two rationals
 *Return values - boolean for whichever is lesser
 *Description - compares which fraction is bigger or smaller.
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
bool operator <(const Rational &A, const Rational &B)
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

/*---------------------------------------------------------------------------------------
 *Name - <=
 *Arguments - two rationals
 *Return values - boolean for whichever is lesser or equal
 *Description - compares which fraction is bigger or smaller.
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
bool operator <=(const Rational &A, const Rational &B)
{
    if((A.numerator*B.denominator) <= (B.numerator * A.denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

/*---------------------------------------------------------------------------------------
 *Name - >
 *Arguments - two rationals
 *Return values - boolean for whichever is greater
 *Description - compares which fraction is bigger or smaller.
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
bool operator >(const Rational &A, const Rational &B)
{

    if((A.numerator*B.denominator) > (B.numerator * A.denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

/*---------------------------------------------------------------------------------------
 *Name - >=
 *Arguments - two rationals
 *Return values - boolean for whichever is greater or equal
 *Description - compares which fraction is bigger or smaller.
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
bool operator >=(const Rational &A, const Rational &B)
{

    if((A.numerator*B.denominator) >= (B.numerator * A.denominator))
    {
        return 1;
    }
    else
    {
        return 0;
    }


}

/*---------------------------------------------------------------------------------------
 *Name - Equals
 *Arguments - two rationals
 *Return values - true if they are equal
 *Description - compares if fractions are equal
 *Notes -2/13/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
bool operator ==(const Rational &A, const Rational &B)
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
