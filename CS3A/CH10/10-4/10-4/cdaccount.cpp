#include "cdaccount.h"

cdaccount::cdaccount()//default constructor
{
    balanceDollars = 0;
    balanceCents = 0;
    interestRate=0;
    term=0;
}

cdaccount::cdaccount(int BalanceDollars, int BalanceCents, double InterestRate, int Term)//contstructor with terms
{
    balanceDollars = BalanceDollars;
    balanceCents = BalanceCents;
    interestRate = InterestRate/100.0;
    term = Term;
}

/*---------------------------------------------------------------------------------------
 *Name - SetData
 *Arguments - ints BalanceDollars, BalanceCents, term, double InterestRate
 *Return values - none, function to get data
 *Description - sets data based on users input
 *Notes -2/6/13 - fairly easy. not much different than the constructor
-----------------------------------------------------------------------------------------*/
void cdaccount::SetData(int BalanceDollars, int BalanceCents, double InterestRate, int Term)
{
    balanceDollars = BalanceDollars;
    balanceCents = BalanceCents;
    interestRate = InterestRate/100.0;
    term = Term;
}

/*---------------------------------------------------------------------------------------
 *Name - GetBalance
 *Arguments - balance dollars and balance cents
 *Return values - returns the balance
 *Description - returns balance for couting
 *Notes -2/6/13 - pretty easy.
-----------------------------------------------------------------------------------------*/
double cdaccount::GetBalance()
{
    return (balanceDollars+(balanceCents/100.0));
}

/*---------------------------------------------------------------------------------------
 *Name - GetRate
 *Arguments - InterestRate
 *Return values - returns the interest rate
 *Description - returns rate for couting
 *Notes -2/6/13 - fairly easy
-----------------------------------------------------------------------------------------*/
double cdaccount::GetRate()
{
    return interestRate;
}

/*---------------------------------------------------------------------------------------
 *Name - GetTerm
 *Arguments - term
 *Return values - returns the term
 *Description - returns term for couting
 *Notes -2/6/13 - farily easy.
-----------------------------------------------------------------------------------------*/
int cdaccount::GetTerm()
{
    return term;
}

/*---------------------------------------------------------------------------------------
 *Name - GetMaturity
 *Arguments - balance dollars, balance cents, interestRate, term
 *Return values - returns the new balance
 *Description - returns the new balance after calculations
 *Notes -2/6/13 - pretty easy.
-----------------------------------------------------------------------------------------*/
double cdaccount::GetMaturity()
{
    double interest;

    interest = (balanceDollars + (balanceCents/100.0)) * interestRate * (term/12.0);

    return ((balanceDollars + (balanceCents/100.0))+ interest);
 }

