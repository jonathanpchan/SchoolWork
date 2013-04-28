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
 *Name - Add
 *Arguments - numeator/denominator for two Rationals
 *Return values - returns a Rational c
 *Description - adds the fractions
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational Rational::Add(Rational b)
{
    Rational c;

    c.numerator = (numerator*b.denominator + b.numerator*denominator);
    c.denominator = (denominator * b.denominator);

    return c.Simplify();
}

/*---------------------------------------------------------------------------------------
 *Name - Subtract
 *Arguments - numeator/denominator for two Rationals
 *Return values - returns a Rational c
 *Description - subtracts the fractions
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational Rational::Subtract(Rational b)
{
    Rational c;

    c.numerator = (numerator*b.denominator - b.numerator*denominator);
    c.denominator = (denominator * b.denominator);

    return c.Simplify();

}

/*---------------------------------------------------------------------------------------
 *Name - Multiply
 *Arguments - numeator/denominator for two Rationals
 *Return values - returns a Rational c
 *Description - multiplies the fractions
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational Rational::Multiply(Rational b)
{
    Rational c;

    c.numerator = numerator * b.numerator;
    c.denominator = denominator * b.denominator;

    return c.Simplify();
}

/*---------------------------------------------------------------------------------------
 *Name - Divide
 *Arguments - numeator/denominator for two Rationals
 *Return values - returns a Rational c
 *Description - divides the fractions
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational Rational::Divide(Rational b)
{
    Rational c;

    c.numerator = numerator * b.denominator;
    c.denominator = b.numerator * denominator;

    return c.Simplify();

}

/*---------------------------------------------------------------------------------------
 *Name -Negative
 *Arguments - numeator
 *Return values - none, changes done to variables
 *Description - makes numerator negative
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
Rational Rational::Negative()
{
    Rational neg;
    neg.numerator = numerator*-1;
    neg.denominator = denominator;
    return(neg);
}

/*---------------------------------------------------------------------------------------
 *Name - LessThan
 *Arguments - numeator/denominator for two Rationals
 *Return values - boolean if calling is less than argument
 *Description - compares which fraction is bigger or smaller.
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------
 *Name - Equals
 *Arguments - numeator/denominator for two Rationals
 *Return values - boolean if calling is equal to the argument
 *Description - compares if fractions are equal
 *Notes -2/8/13 - fairly easy used book formula
-----------------------------------------------------------------------------------------*/
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

/*---------------------------------------------------------------------------------------
 *Name - Simplify
 *Arguments - numeator/denominator
 *Return values - a simplified rational
 *Description - finds the greatest divisor, then divides and returns the simplified rational
 *Notes -2/8/13 - had a bit of trouble figuring out the divisor, other than that easy.
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
