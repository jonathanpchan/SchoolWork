#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "node.h"
#include <iostream>

using namespace std;

class polynomial
{
public:
    polynomial();//default constructor
    ~polynomial();//destructor
    polynomial(const polynomial& a);//copy constructor
    polynomial& operator =(const polynomial& a);//assignement operator


    node* Search(node* findThis);//searches for a given node
    node* Previous(node* findThis);//previous from given node


    void InsertAfter(node* insertThis, node* afterThis);//inserts after a given node
    void InsertBefore(node* insertThis, node* beforeThis);//inserts before a given node
    void InsertSorted(node* insertThis);//inserts into a sorted list
    void InsertHead(node* insertThis);//inserts a head
    void Append(node* insertThis);//appends a node
    void DestroyAllNodes();//destroys all the nodes
    friend polynomial operator +(const polynomial &p1, const polynomial &p2);//adds two polys
    friend polynomial operator -(const polynomial &p1, const polynomial &p2);//subtracts two polys
    friend polynomial operator *(const polynomial &p1, const polynomial &p2);//multiplies two polys


    friend ostream &operator <<(ostream& out, polynomial& A);//outputs the list




private:
    node* head;
    node* cursor;

};

#endif // POLYNOMIAL_H