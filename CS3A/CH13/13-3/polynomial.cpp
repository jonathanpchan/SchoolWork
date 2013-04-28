#include "polynomial.h"
#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;

polynomial::polynomial()
{
    head=NULL;
    cursor = NULL;
}
polynomial::~polynomial()
{
    delete head;
}

polynomial::polynomial(const polynomial& a)
{
    try
    {
        node* walker = a.head;

        DestroyAllNodes();
        while(walker!=NULL)
        {
            node* newNode = new node(*walker);
            Append(newNode);
            walker = walker->next;
        }
        cursor = head;

    }
    catch(std::bad_alloc&)
    {
        cout<<"Failed to allocate memory."<<endl;
    }
}
polynomial& polynomial::operator =(const polynomial &a)
{
    try
    {
        node* walker = a.head;

        if(a.head == NULL)
        {
            DestroyAllNodes();
            return *this;
        }
        if(a.head == head)
            return *this;
        else
        {
            DestroyAllNodes();
            while(walker!=NULL)
            {
                node* newNode = new node(*walker);
                Append(newNode);
                walker = walker->next;
            }
            cursor = head;
        }

        return *this;
    }
    catch(std::bad_alloc&)
    {
        cout<<"Failed to allocate memory."<<endl;
        exit(1);
    }
}


/*******************
  Name: +
  Arguments: two polynomials
  Returns: a polynomial
  Description: adds two polynomials
  Notes: not too bad
  *******************/
polynomial operator +(const polynomial &p1, const polynomial &p2)
{
    polynomial p3;
    node* walker1 = p1.head, *walker2 = p2.head, *newTerm;

    while(walker1 != NULL && walker2 != NULL)
    {
        if(walker1->exponent>walker2->exponent)
        {
            newTerm = new node(walker1->coefficent, walker1->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker1 = walker1->next;
        }
        else if(walker1->exponent < walker2->exponent)
        {
            newTerm = new node(walker2->coefficent, walker2->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker2 = walker2->next;
        }
        else if(walker1->exponent == walker2->exponent)
        {
            newTerm = new node(walker1->coefficent+walker2->coefficent, walker1->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker1 = walker1->next;
            walker2 = walker2->next;
        }
        while(!walker1 && walker2 != NULL)
        {
            newTerm = new node(walker2->coefficent, walker2->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker2 = walker2->next;
        }
        while(!walker2 && walker1 != NULL)
        {
            newTerm = new node(walker1->coefficent, walker1->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker1 = walker1->next;
        }

    }
    return p3;
}

/*******************
  Name: -
  Arguments: two polynomials
  Returns: a polynomial
  Description: subtracts two polynomials
  Notes: not too bad
  *******************/
polynomial operator -(const polynomial &p1, const polynomial &p2)
{
    polynomial p3;
    node* walker1 = p1.head, *walker2 = p2.head, *newTerm;

    while(walker1 != NULL && walker2 != NULL)
    {
        if(walker1->exponent>walker2->exponent)
        {
            newTerm = new node(walker1->coefficent, walker1->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker1 = walker1->next;
        }
        else if(walker1->exponent < walker2->exponent)
        {
            newTerm = new node(walker2->coefficent*-1, walker2->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker2 = walker2->next;
        }
        else if(walker1->exponent == walker2->exponent)
        {
            newTerm = new node(walker1->coefficent+walker2->coefficent*-1, walker1->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker1 = walker1->next;
            walker2 = walker2->next;
        }
        while(!walker1 && walker2 != NULL)
        {
            newTerm = new node(walker2->coefficent*-1, walker2->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker2 = walker2->next;
        }
        while(!walker2 && walker1 != NULL)
        {
            newTerm = new node(walker1->coefficent, walker1->exponent);

            if(p3.head==NULL)//if no head
                p3.InsertHead(newTerm);
            else
                p3.Append(newTerm);

            walker1 = walker1->next;
        }

    }
    return p3;

}

/*******************
  Name: +
  Arguments: two polynomials
  Returns: a polynomial
  Description: adds two polynomials
  Notes: dealing with like terms was somewhat of an issue.
  *******************/
polynomial operator *(const polynomial &p1, const polynomial &p2)
{
    polynomial p3;
    node* walker1 = p1.head, *walker2 = p2.head, *walker3, *newTerm;
    bool updated=false;

    while(walker1!=NULL)
    {
        //cout << "outer loop\n";


        walker2=p2.head;
        while(walker2!=NULL)
        {
            newTerm= new node(walker1->coefficent*walker2->coefficent,walker1->exponent+walker2->exponent);
            //cout << "new term = " << *newTerm << endl;
            //cout << "updated = " << updated << endl ;

            walker3=p3.head;
            updated=false;
            if(p3.head==NULL)//if no head
            {
                 p3.InsertHead(newTerm);
                 walker3 = p3.head;
                 //cout << "inserting head\n\n";
            }
            else if(walker3 != NULL)
            {
                //cout << "in if\n";
                //cout << "walker3 = " << *walker3 << endl << endl << endl;
                if(walker3 != NULL)
                {                    //cout << "asdasdasd\n";
                    while(walker3!=NULL)
                    {                       // cout << "checking for equal nodes\n";
                        if(walker3->exponent==newTerm->exponent)
                        {   //cout << "same exponent, adding coeffs\n";
                            walker3->coefficent += newTerm->coefficent;
                            //cout << "updated term = " << *walker3 << endl;
                            updated=true;
                        }
                        walker3 = walker3->next;
                    }
                }

                if(updated==false)// if(walker3->exponent!=newTerm->exponent)
                {
                    //cout << "appending - " << *newTerm << endl ;
                    p3.InsertSorted(newTerm);
                }
            }
            walker2=walker2->next;
        }
        walker1=walker1->next;
    }
    return p3;

}

/*******************
  Name: Append
  Arguments: a node
  Returns none void function
  Description: appends a node to the end of the list
  Notes: not too bad
  *******************/
void polynomial::Append(node *insertThis)
{
    try
    {
        if(insertThis == NULL)
            throw -1;

        if(head == NULL)
            InsertHead(insertThis);
        else
        {
            node* walker = head;

            while (walker!=NULL)
            {
                cursor = walker;
                walker = walker->next;
            }

            cursor->next = insertThis;
            insertThis = cursor;

            cursor = insertThis->next;
        }
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Sorry bob. This is not the function you are looking for."<<endl;
    }
}
/*******************
  Name: InsertAfter
  Arguments: two nodes
  Returns nothing, void function
  Description inserts a node after a given node
  Notes: pretty simple.
  *******************/
void polynomial::InsertAfter(node *insertThis, node *afterThis)
{
    const char ch = 'z';

    try
    {
        if(insertThis == NULL)
            throw -1;
        if(afterThis == NULL)
            throw ch;

        insertThis->next = afterThis->next;
        afterThis->next = insertThis;
        cursor = insertThis;
    }
    catch(int e)
    {
        cout<<"CAUTION! First parameter is NULL!"<<endl;
    }
    catch(char z)
    {
        cout<<"CAUTION! Second parameter is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Sorry bob. This is not the function you are looking for."<<endl;
    }
}

/*******************
  Name: InsertBefore
  Arguments: two nodes
  Returns nothing, void function
  Description: inserts before a given node
  Notes: pretty simple, uses insertAfter and a previous function
  *******************/
void polynomial::InsertBefore(node *insertThis, node *beforeThis)
{
    const char ch = 'z';

    try
    {

        if(insertThis == NULL)
            throw -1;
        if(beforeThis == NULL)
            throw ch;

        if(*head == *beforeThis)
            InsertHead(insertThis);
        else
        {
            node *afterThis = Previous(beforeThis);
            InsertAfter(insertThis,afterThis);
        }
    }
    catch(int e)
    {
        cout<<"CAUTION! First parameter is NULL!"<<endl;
    }
    catch(char z)
    {
        cout<<"CAUTION! Second parameter is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Sorry bob. This is not the function you are looking for."<<endl;
    }

}
/*******************
  Name: InsertHead
  Arguments: a node
  Returns none, void function
  Description: Inserts a new head.
  Notes: not too bad
  *******************/
void polynomial::InsertHead(node *insertThis)
{
    try
    {
        if(insertThis == NULL)
            throw -1;

        insertThis->next = head;
        head=cursor=insertThis;
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Sorry bob. This is not the function you are looking for."<<endl;
    }
}

/*******************
  Name: InsertSorted
  Arguments: a node
  Returns none, void function
  Description: once list is sorted, inserts into the list
  Notes: not too bad
  *******************/
void polynomial::InsertSorted(node *insertThis)
{
    try
    {
//        if(!sorted)
//            throw false;

        if(insertThis == NULL)
            throw -1;

        if(head==NULL)
            InsertHead(insertThis);
        else
        {
            node* here = Search(insertThis);

            if(here == NULL)
            {
                node* walker = head;
                cursor = head;

                while(*insertThis <= *walker && walker->next != NULL)
                {
                    walker = walker->next;
                    cursor = walker;
                }

                if(*insertThis <= *cursor)
                {   //sorted = false;
                    InsertAfter(insertThis,cursor);
                    //sorted = true;

                }
                else
                {
                    //sorted = false;
                    InsertBefore(insertThis,cursor);
                    //sorted=true;
                }
            }
            else
            {
                //sorted = false;
                InsertAfter(insertThis,here);
                //sorted = true;
            }
        }
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Please sort first."<<endl;
    }
}

/*******************
  Name: Search
  Arguments: a single node
  Returns returns a pointer to the node if found, otherwise null
  Description: inserts before a given node
  Notes: pretty simple, uses insertAfter and a previous function
  *******************/
node* polynomial::Search(node *findThis)
{
    node* walker = head;
    walker = head;

    if(head==NULL)
        return NULL;

    if(findThis == head)
        return head;

    while(*findThis != *walker && walker->next!=NULL)
        walker = walker->next;

    if(*findThis != *walker && walker->next==NULL)
        return NULL;

    cursor = walker;
    return walker;
}



/*******************
  Name: Previous
  Arguments: two nodes
  Returns a pointer to the previous node to the given node
  Description: returns previous to a given node
  Notes: not too difficult
  *******************/
node* polynomial::Previous(node *findThis)
{
    bool flag = false;
    node *walker = head, *prevNode;

    if(findThis == head)
        return head;

    while(walker != findThis && walker->next!=NULL)
    {
        prevNode = walker;
        walker = walker->next;
        flag = true;
    }

    prevNode = flag!=true?NULL:prevNode;
    cursor = prevNode;
    return prevNode;
}

/*******************
  Name: <<
  Arguments: linked list
  Returns ostream
  Description: outputs a linked list
  Notes: not too bad
  *******************/
ostream& operator <<(ostream& out, polynomial& A)
{
    //cout << "AHEAD = " << *A.head;
    node *walker = A.head;
    while(walker->next != NULL)
    {

        if(walker->coefficent == 0)
        {
            cout << "";
            walker=walker->next;
        }
        else
        {
            if(walker->next->coefficent > 0)
            {
                out << *walker;
                cout << " + ";
                walker = walker->next;
            }
            else if(walker->next->coefficent<0)
            {
                out << *walker;
                walker = walker->next;
            }
            else if(walker->next->coefficent==0)
            {   out << *walker;
                out << " + ";
                walker = walker->next;
            }
        }

    }
    out << *walker;
    walker=walker->next;
    return out;

//    node *walker = A.head;
//    while(walker != NULL)
//    {
//        out << *walker;
//        walker = walker->next;
//        cout << " --> ";
//    }
//    out << " NULL" << endl;
//    return out;
}

/*******************
  Name: DestroyAllNodes
  Arguments: none
  Returns none
  Description: destroys all nodes sets them to Null
  Notes: not too bad
  *******************/
void polynomial::DestroyAllNodes()
{
    delete head;
    head = NULL;
    cursor = NULL;
}


