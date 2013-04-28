#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "linkedlist.h"
#include "polyterm.h"

class polynomial:public LinkedList<polyterm>
{
public:

    //emplate <class T>
    polynomial& operator +=(const Node<polyterm> &a);

    friend polynomial& operator +(const polynomial &p1, const polynomial &p2);//adds two polys


    friend polynomial& operator -(const polynomial &p1, const polynomial &p2);//subtracts two polys
    friend polynomial operator -(const polynomial &p1); //negates a polynomial;
    friend polynomial operator *(const polynomial &p1, const polynomial &p2);//adds two polys

    friend polynomial operator *(const polynomial, const Node<polyterm> &p);//adds two polys







    friend ostream& operator <<(ostream& out,const polynomial& A);
};

#endif // POLYNOMIAL_H
