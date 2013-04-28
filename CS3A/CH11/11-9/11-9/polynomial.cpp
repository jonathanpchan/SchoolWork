#include "polynomial.h"
#include <iostream>

using namespace std;

polynomial::polynomial()
{
    coeffcients = new double[1];
    coeffcients[0] = 1;
}
polynomial::polynomial(int Terms, double* Coefficents)
{
    coeffcients = new double[Terms];
    for(int i=0; i<Terms; i++)
    {
        coeffcients[i] = Coefficents[i];
    }
    numTerms=Terms;
}

polynomial::polynomial(const polynomial &copyThis)
{
    numTerms = copyThis.numTerms;
    coeffcients = new double[numTerms];
    for(int i=0; i<numTerms; i++)
    {
        coeffcients[i] = copyThis.coeffcients[i];
    }
}

polynomial::~polynomial()
{
    delete[] coeffcients;
}

/*---------------------------------------------------------------------------------------
 *Name - GetNumTerms
 *Arguments - none
 *Return values - returns num terms
 *Description - returns numterms
 *Notes -2/18/13 - easy
----------------------------------------------------------------------------------------*/
int polynomial::GetNumTerms()
{
    return numTerms;
}

/*---------------------------------------------------------------------------------------
 *Name - Show
 *Arguments - none
 *Return values - void
 *Description - outputs polynomials
 *Notes -2/18/13 - easy
----------------------------------------------------------------------------------------*/
void polynomial::Show()
{
    for(int i=numTerms-1; i>0; i--)
    {
        cout << coeffcients[i] << "x^" << i;
        cout << " + ";
    }
    cout << coeffcients[0];
}
/*---------------------------------------------------------------------------------------
 *Name - <<
 *Arguments - ostream, polynomial
 *Return values - returns out
 *Description - outputs polynomials
 *Notes -2/18/13 - easy
----------------------------------------------------------------------------------------*/
ostream& operator <<(ostream &out, const polynomial &A)
{
    for(int i=A.numTerms-1; i>0; i--)
    {
        out << A.coeffcients[i] << "x^" << i;
        out << " + ";
    }
    out << A.coeffcients[0];

    return out;
}

/*---------------------------------------------------------------------------------------
 *Name - +
 *Arguments - two polynomials
 *Return values - returns a polynomial c
 *Description - adds two polynomials
 *Notes -2/18/13 - weird to deal with number of terms, but okay in the lnong run
----------------------------------------------------------------------------------------*/
polynomial operator +(const polynomial &A, const polynomial &B)
{
    polynomial C;
    int bigger;//terms of the polynomial with the lesser amount

    if(A.numTerms> B.numTerms)
    {
        bigger=A.numTerms;
    }
    else
    {
        bigger=B.numTerms;
    }


    C.numTerms = bigger;
    C.coeffcients = new double[bigger];

    if(A.numTerms > B.numTerms)
    {
        for(int i=0; i<B.numTerms;i++)
        {
            C.coeffcients[i] = A.coeffcients[i] + B.coeffcients[i];//this will always be done???
        }
        for(int j=B.numTerms; j<C.numTerms; j++)
        {
            C.coeffcients[j] = A.coeffcients[j];
        }
    }
    else
    {
        for(int i=0; i<A.numTerms;i++)
        {
            C.coeffcients[i] = A.coeffcients[i] + B.coeffcients[i];//this will always be done???
        }
        for(int j=A.numTerms; j<C.numTerms; j++)
        {
            C.coeffcients[j] = B.coeffcients[j];
        }

    }
    return C;

}

/*---------------------------------------------------------------------------------------
 *Name - +
 *Arguments - polynomial and a number
 *Return values - returns a polynomial c
 *Description - adds number+poly
 *Notes -2/18/13 - pretty easy
-----------------------------------------------------------------------------------------*/
polynomial operator +(double num, const polynomial &A)
{
    A.coeffcients[0] = A.coeffcients[0]+num;

    return A;
}

/*---------------------------------------------------------------------------------------
 *Name - +
 *Arguments - polynomial and a number
 *Return values - returns a polynomial c
 *Description - adds poly+number
 *Notes -2/18/13 - pretty easy
-----------------------------------------------------------------------------------------*/
polynomial operator +(const polynomial &A, double num)
{
    A.coeffcients[0] = A.coeffcients[0]+num;
    return A;
}

/*---------------------------------------------------------------------------------------
 *Name - "-"
 *Arguments - two polynomials
 *Return values - returns a polynomial c
 *Description - subtracts two polynomials
 *Notes -2/18/13 - weird to deal with number of terms, but okay in the lnong run similar to add
----------------------------------------------------------------------------------------*/
polynomial operator -(const polynomial &A, const polynomial &B)
{
    polynomial C;
    int bigger;//terms of the polynomial with the lesser amount

    if(A.numTerms> B.numTerms)
    {
        bigger=A.numTerms;
    }
    else
    {
        bigger=B.numTerms;
    }


    C.numTerms = bigger;
    C.coeffcients = new double[bigger];

    if(A.numTerms > B.numTerms)
    {
        for(int i=0; i<B.numTerms;i++)
        {
            C.coeffcients[i] = A.coeffcients[i] - B.coeffcients[i];//this will always be done???
        }
        for(int j=B.numTerms; j<C.numTerms; j++)
        {
            C.coeffcients[j] = A.coeffcients[j];
        }
    }
    else
    {
        for(int i=0; i<A.numTerms;i++)
        {
            C.coeffcients[i] = A.coeffcients[i] - B.coeffcients[i];//this will always be done???
        }
        for(int j=A.numTerms; j<C.numTerms; j++)
        {
            C.coeffcients[j] = B.coeffcients[j]*-1;
        }

    }
    return C;
}

/*---------------------------------------------------------------------------------------
 *Name - "-"
 *Arguments - polynomial and a number
 *Return values - returns a polynomial c
 *Description - subtracts number-poly
 *Notes -2/18/13 - pretty easy
-----------------------------------------------------------------------------------------*/
polynomial operator -(double num, const polynomial &A)
{
    for(int i=1; i<A.numTerms; i++)
    {
        A.coeffcients[i] = A.coeffcients[i] * -1.0;
    }
    A.coeffcients[0] = num - A.coeffcients[0];
    return A;
}

/*---------------------------------------------------------------------------------------
 *Name - "-"
 *Arguments - polynomial and a number
 *Return values - returns a polynomial c
 *Description - subtracts poly-number
 *Notes -2/18/13 - pretty easy
-----------------------------------------------------------------------------------------*/
polynomial operator -(const polynomial &A, double num)
{
    A.coeffcients[0] = A.coeffcients[0] - num;
    return A;
}

/*---------------------------------------------------------------------------------------
 *Name - *
 *Arguments - two polynomials
 *Return values - returns a polynomial c
 *Description - multiplies two polynomials
 *Notes -2/18/13 - challenging, had to draw everything out to get it like this
-----------------------------------------------------------------------------------------*/
polynomial operator *(const polynomial &A, const polynomial &B)
{
    polynomial C;
    C.coeffcients =  new double [A.numTerms+B.numTerms-1];


    C.numTerms = (A.numTerms+B.numTerms-1);
    for(int i=0; i<C.numTerms; i++)
    {
        C.coeffcients[i]=0;
    }


    for(int i = 0; i<A.numTerms; i++)
    {
        for(int j=0; j<B.numTerms; j++)
        {
            C.coeffcients[i+j] = C.coeffcients[i+j] + (A.coeffcients[i] * B.coeffcients[j]);
        }

    }
    return C;
}

/*---------------------------------------------------------------------------------------
 *Name - +
 *Arguments - polynomial and a number
 *Return values - returns a polynomial c
 *Description - adds poly+number
 *Notes -2/18/13 - pretty easy
-----------------------------------------------------------------------------------------*/
polynomial operator *(double num, const polynomial &A)
{
    for(int i=0; i<A.numTerms; i++)
    {
        A.coeffcients[i] = A.coeffcients[i] * num;
    }
    return A;
}

/*---------------------------------------------------------------------------------------
 *Name - *
 *Arguments - polynomial and a number
 *Return values - returns a polynomial c
 *Description - multiplies poly*number
 *Notes -2/18/13 - pretty easy
-----------------------------------------------------------------------------------------*/
polynomial operator *(const polynomial &A, double num)
{
    for(int i=0; i<A.numTerms; i++)
    {
        A.coeffcients[i] = A.coeffcients[i] * num;
    }
    return A;

}

/*---------------------------------------------------------------------------------------
 *Name - =
 *Arguments - polynomial
 *Return values - *this
 *Description - overwrite equal operator
 *Notes -2/18/13 - pretty easy just like copy constructor
-----------------------------------------------------------------------------------------*/
polynomial& polynomial::operator =(const polynomial &copyThis)
{
    numTerms = copyThis.numTerms;
    coeffcients = new double[numTerms];
    for(int i=0; i<numTerms; i++)
    {
        coeffcients[i] = copyThis.coeffcients[i];
    }

    return *this;
}
