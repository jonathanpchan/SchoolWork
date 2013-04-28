#ifndef CDACCOUNT_H
#define CDACCOUNT_H

class cdaccount
{
public:
    cdaccount();//default constructor
    cdaccount(int BalanceDollars, int BalanceCents, double InterestRate, int Term);//constructor with paramaters

    void SetData(int BalanceDollars, int BalanceCents, double InterestRate, int Term);//used to set data

    double GetBalance();//gets the balance
    double GetRate();//gets the rate
    int GetTerm();//gets the term

    double GetMaturity();//gets the maturity

private:

    int balanceDollars;
    int balanceCents;
    double interestRate;
    int term;

};

#endif // CDACCOUNT_H
