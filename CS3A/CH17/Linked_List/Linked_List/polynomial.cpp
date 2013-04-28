#include "polynomial.h"
#include "linkedlist.h"
#include "iterator.h"

#include <iostream>
using namespace std;


polynomial& polynomial::operator +=(const Node<polyterm> &a)
{
    //cout << "+= " << a << endl;

    Iterator<polyterm> P = this->Search(a.Copy());

    if(P.GetNode() != NULL)
    {
        Node<polyterm>* oldTerm = this->Remove(P);
        //cout << "oldTerm " << *oldTerm << endl;
        Node<polyterm> newTerm = *oldTerm + a;
       //cout << "newTerm " << newTerm << endl;
        this->InsertSorted(newTerm.Copy());
        //cout << "newPoly = " << *this << endl;
    }
    else
    {
        this->InsertSorted(a.Copy());
    }
    return *this;
}

polynomial& operator +(const polynomial &p1, const polynomial &p2)
{
    polynomial* p3 = new polynomial;

    *p3 = p1;

    Iterator<polyterm> P = p2.Begin();

    while(P.GetNode() != NULL)
    {
       *p3+=*P.GetNode();
       P.Next();
    }
    return *p3;
}
polynomial& operator -(const polynomial &p1, const polynomial &p2)
{
    polynomial p3;
    p3 = -p2;

    return(p1+p3);


}


polynomial operator -(const polynomial &p1)
{
    polynomial negated;

    Iterator<polyterm> P = p1.Begin();

    while(P.GetNode() != NULL)
    {
        Node<polyterm> negTerm = -(*P.GetNode());
        negated.Append(negTerm.Copy());
        P.Next();
    }

    return negated;
}

polynomial operator *(const polynomial &p1, const polynomial &p2)
{
    polynomial p3;
    Iterator<polyterm> poly1, poly2;
    Node<polyterm> newTerm;


    poly1=p1.Begin();
    while(poly1.GetNode()!=NULL)
    {

        poly2 = p2.Begin();
        while(poly2.GetNode()!=NULL)
        {
            newTerm = *poly1.GetNode()* *poly2.GetNode();

            p3.InsertSorted(new Node<polyterm>(newTerm));


            poly2.Next();
        }
        poly1.Next();
    }
    return p3;




}

//polynomial operator *(const polynomial &p, const Node<polyterm> n)
//{
//    polynomial p3;




//}
ostream& operator <<(ostream& out,const polynomial& A)
{
    //cout << "AHEAD = " << *A.head;

    //node *walker = A.head;
    Iterator<polyterm> P = A.Begin();

    while(P.GetNext() != NULL)
    {

        if(P.GetNode()->GetData().Coef() == 0)
        {
            cout << "";
//            walker=walker->next;
            P.GetNext();
        }
        else
        {
            if(P.GetNext()->GetData().Coef() > 0)
            {
                out << P;
                cout << " + ";
                //walker = walker->next;
                P.Next();
            }
            else if(P.GetNext()->GetData().Coef()<0)
            {
                out << P;
                //walker = walker->next;
                P.Next();
            }
            else if(P.GetNext()->GetData().Coef()==0)
            {   out << P;
                out << " + ";
                //walker = walker->next;
                P.Next();
            }
        }

    }
    out << P;
    //P.Next();
    return out;
}








