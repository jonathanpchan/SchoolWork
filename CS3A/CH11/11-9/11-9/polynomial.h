#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;

class polynomial
{
public:
    polynomial();
    polynomial(int terms, double* Coeffcients);
    polynomial(const polynomial &copyThis);
    ~polynomial();

    int GetNumTerms();

    void Show();

    friend ostream& operator <<(ostream &out, const polynomial &A);//outputs

    //ADDING FUNCTIONS
    friend polynomial operator +(const polynomial &A, const polynomial &B);//add two poly
    friend polynomial operator +(double num, const polynomial &A);//ad constant+poly
    friend polynomial operator +(const polynomial &A, double num);//add poly+constant

    //SUBTRACTION FUNCTIONS
    friend polynomial operator -(const polynomial &A, const polynomial &B);//subtract two poly
    friend polynomial operator -(double num, const polynomial &A);//subtract constant-poly
    friend polynomial operator -(const polynomial &A, double num);//subtract poly-constant

    //MULTIPLICATION fUNCTIONS
    friend polynomial operator *(const polynomial &A, const polynomial &B);//multiply two poly
    friend polynomial operator *(double num, const polynomial &A);//constant*poly
    friend polynomial operator *(const polynomial &A, double num);//poly*constant.
    polynomial &operator =(const polynomial &copyThis);//overload equal operator


private:
    double* coeffcients;
    int numTerms;
};

#endif // POLYNOMIAL_H

