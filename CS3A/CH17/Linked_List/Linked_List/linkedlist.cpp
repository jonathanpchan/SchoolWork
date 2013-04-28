#include "linkedlist.h"
#include "node.h"
#include "iterator.h"
#include <cstdlib>
#include <iostream>

using namespace std;
/*
  DEFAULT CONSTRUCTOR
  */

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    cursor = NULL;
    rear = NULL;
    sorted = false;
}

/*******************
  Copy CONSTRUCTOR
  *******************/
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& a)
{
    try
    {
        Iterator<T> P = a.Begin();
        //Node<T>* walker = a.head;
        sorted = a.sorted;

        DestroyAllNodes();
        while(P.GetNode() != NULL)
        {
            //Node<T>* newNode = new Node<T>(*P.GetNode());
            Append(P.GetNode());
            P.Next();
        }
        cursor = head;
    }
    catch(std::bad_alloc&)
    {
        cout<<"Failed to allocate memory."<<endl;
    }
}

/*******************
  Destructor
  *******************/
template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
}

/*******************
  Name: InsertAfter
  Arguments: two nodes
  Returns nothing, void function
  Description inserts a node after a given node
  Notes: pretty simple.
  *******************/
template <class T>
void LinkedList<T>::InsertAfter(Node<T> *insertThis, Node<T> *afterThis)
{
    const char ch = 'z';
    Node<T>* temp;
    try
    {
        if(sorted)
            throw true;
        if(insertThis == NULL)
            throw -1;
        if(afterThis == NULL)
            throw ch;


        insertThis->next = afterThis->next;
        insertThis->prev = afterThis;

        afterThis->next=insertThis;

        if(afterThis==rear)
        {
            rear = afterThis->next;
        }
        else
        {

            temp = insertThis->next;
            temp->prev = insertThis;
        }
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
        cout<<"Sorry bob. This insertAfter is not the function you are looking for."<<endl;
    }
}

/*******************
  Name: InsertBefore
  Arguments: two nodes
  Returns nothing, void function
  Description: inserts before a given node
  Notes: pretty simple, uses insertAfter and a previous function
  *******************/
template <class T>
void LinkedList<T>::InsertBefore(Node<T> *insertThis, Node<T> *beforeThis)
{
    const char ch = 'z';

    try
    {
        if(sorted)
            throw true;
        if(insertThis == NULL)
            throw -1;
        if(beforeThis == NULL)
            throw ch;

        if(*head == *beforeThis)
            InsertHead(insertThis);
        else
        {
            Node<T>* afterThis = beforeThis->prev;
            InsertAfter(insertThis,afterThis);
            cursor=insertThis;
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
        cout<<"Sorry bob. This insertBefore is not the function you are looking for."<<endl;
    }

}

/*******************
  Name: Search
  Arguments: a single node
  Returns returns a pointer to the node if found, otherwise null
  Description: inserts before a given node
  Notes: pretty simple, uses insertAfter and a previous function
  *******************/
template <class T>
Iterator<T> LinkedList<T>::Search(Node<T>* findThis)
//Node<T>* LinkedList<T>::Search(Node<T> *findThis)
{

//    Node<T>* walker = head;
//    walker = head;

    Iterator<T> P = this->Begin();

    if(head==NULL)
        return Iterator<T>(NULL, this);

    if(findThis == head)
        return this->Begin();

    while(*findThis != *P.GetNode() && P.GetNext()!=NULL)
        P.Next();

    if(*findThis != *P.GetNode() && P.GetNext()==NULL)
        return Iterator<T>(NULL, this);

    cursor = P.ptr;
    return P;
}



/*******************
  Name: Previous
  Arguments: zero argument previous
  Returns previous to cursor
  Description: returns previous to the cursor
  Notes: uses previous function
  *******************/
template <class T>
Node<T> *LinkedList<T>::Previous()
{
    return cursor->prev!=NULL?cursor = cursor->prev:cursor;

}

/*******************
  Name: Remove
  Arguments: a node
  Returns a copy to the given node
  Description: removes a given node
  Notes: not too bad
  *******************/
template <class T>
Node<T>* LinkedList<T>::Remove(Node<T> *removeThis)
{
    try
    {

        if(removeThis == NULL)
            throw -1;

        Node<T>* temp, *removed;

        if(removeThis==head)
        {
            //cout << "test head\n";
            removed = head;

            if(removeThis->next==NULL)
            {
                head->prev=NULL;
                head->next=NULL;
                head=NULL;
            }
            else
            {
                head = removeThis->next;
                head->prev = NULL;
            }
            cursor = head;
            //cout << "bottom of head\n";
        }
        else if(removeThis==rear)
        {
            //cout << "test rear\n";
            removed = rear;
            rear = removeThis->prev;
            rear->next = NULL;
            cursor = rear;
        }
        else
        {
            //cout << "test other\n";
            removed = removeThis;

            temp = removeThis->prev;
            temp->next=removeThis->next;

            temp = removeThis->next;
            temp->prev=removeThis->prev;
        }
        removed->next=NULL;
        removed->prev=NULL;
        return removed;
    }
    catch(int e)
    {
        cout<<"CAUTION! head is NULL!"<<endl;
        return NULL;
    }
}

/*******************
  Name: Remove
  Arguments: none
  Returns a copy to the removed node
  Description: removes the cursor
  Notes: not too bad
  *******************/
template <class T>
Node<T>* LinkedList<T>::Remove()
{
    return Remove(cursor);
}

template <class T>
Node<T> *LinkedList<T>::Remove(Iterator<T> P)
{
    return Remove(P.ptr);
}

/*******************
  Name: Getnode
  Arguments: none
  Returns returns the cursor
  Description: returns the curspr
  Notes: not too bad,uses insert sroted
  *******************/
template <class T>
Node<T> *LinkedList<T>::GetNode()
{
    return cursor;
}

template <class T>
void LinkedList<T>::InsertAfter(Node<T> *insertThis, Iterator<T> afterThis)
{
    InsertAfter(insertThis, afterThis.ptr);
}

template <class T>
void LinkedList<T>::InsertBefore(Node<T> *insertThis, Iterator<T> beforeThis)
{
    InsertBefore(insertThis, beforeThis.ptr);
}

/*******************
  Name: Sort
  Arguments: none
  Returns none void function
  Description: Sorts the list
  Notes: not too bad
  *******************/
template <class T>
void LinkedList<T>::Sort()
{
    try
    {
        LinkedList newList;
        //Node<T>* walker = head;

        Iterator<T> P = this->Begin();



        while(P.GetNode()!=NULL)
        {
            newList.sorted = true;
            sorted = true;
            //Node<T>* newNode = new Node<T>(*P.GetNode());
            newList.InsertSorted(P.GetNode());

            P.Next();
        }

        head = newList.head;
        newList.head = NULL;
        rear = newList.rear;
        newList.rear = NULL;
        cursor = newList.cursor;
        newList.cursor = NULL;


    }
    catch(std::bad_alloc&)
    {
        cout<<"Failed to allocate memory."<<endl;
    }
}



/*******************
  Name: Append
  Arguments: a node
  Returns none void function
  Description: appends a node to the end of the list
  Notes: not too bad
  *******************/
template <class T>
void LinkedList<T>::Append(Node<T>* insertThis)
{
    try
    {
        if(sorted)
            throw true;
        if(insertThis == NULL)
            throw -1;

        if(head == NULL)
            InsertHead(insertThis);
        else
        {
            insertThis->prev=rear;
            rear->next=insertThis;
            insertThis->next=NULL;
            cursor = rear = insertThis;
        }
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Sorry bob. This Append is not the function you are looking for."<<endl;
    }
}

/*******************
  Name: InsertHead
  Arguments: a node
  Returns none, void function
  Description: Inserts a new head.
  Notes: not too bad
  *******************/
template <class T>
void LinkedList<T>::InsertHead(Node<T> *insertThis)
{
    try
    {
        if(sorted)
            throw true;
        if(insertThis == NULL)
            throw -1;

        if(head == NULL)
        {
            insertThis->next=head;
            cursor = head = insertThis;
            insertThis->prev=NULL;
            rear = head;
        }
        else
        {
            head->prev = insertThis;
            insertThis->next = head;
            insertThis->prev = NULL;
            head=cursor=insertThis;
        }
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
    }
    catch(bool b)
    {
        cout<<"Sorry bob. This insertHead is not the function you are looking for."<<endl;
    }
}

/*******************
  Name: InsertSorted
  Arguments: a node
  Returns none, void function
  Description: once list is sorted, inserts into the list
  Notes: not too bad
  *******************/
template <class T>
void LinkedList<T>::InsertSorted(Node<T>* insertThis)
{
    try
    {

//        if(!sorted)
//            throw false;

        if(insertThis == NULL)
            throw -1;

        if(head==NULL)
        {   sorted = false;
            InsertHead(insertThis);
            sorted = true;
        }
        else
        {
           Iterator<T> here = Search(insertThis);

            if(here.GetNode() == NULL)
            {
                //Node<T>* walker = head;
                Iterator<T> P = this->Begin();
                cursor = head;

                while(*insertThis <= *P.GetNode() && P.GetNext() != NULL)
                {
                    P.Next();
                    if(P.GetNode()==NULL)
                        throw 'x';
                    cursor = P.ptr;
                    //walker = walker->next;
                    //cursor = walker;
                }

                if(*insertThis <= *cursor)
                {   sorted = false;
                    InsertAfter(insertThis,P);
                    sorted = true;

                }
                else
                {
                    sorted = false;
                    InsertBefore(insertThis,P);
                    sorted=true;
                }
            }
            else
            {
                //cout << "second instance\n";
                sorted = false;
                InsertAfter(insertThis,here);
                sorted = true;
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
    catch(char x)
    {
        cout << "wat";
    }
}

/*******************
  Name: DestroyAllNodes
  Arguments: none
  Returns none
  Description: destroys all nodes sets them to Null
  Notes: not too bad
  *******************/
template <class T>
void LinkedList<T>::DestroyAllNodes()
{
    delete head;
    head = NULL;
    cursor = NULL;
    rear = NULL;
    sorted = false;
}

/*******************
  Name: Assignment operator
  Arguments: const linked list
  Returns a linked list copy
  Description: copies a list
  Notes: not too bad
  *******************/
template <class T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList<T> &a)
{
    try
    {
        Iterator<T> P = a.Begin();
        //Node<T>* walker = a.head;
        sorted = a.sorted;

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
            while(P.GetNode()!=NULL)
            {
                //Node<T>* newNode = new Node<T>(*walker);
                Append(P.GetNode());
                //walker = walker->next;
                P.Next();
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
  Name: <<
  Arguments: linked list
  Returns ostream
  Description: outputs a linked list
  Notes: not too bad
  *******************/

template <class T>
ostream& operator <<(ostream& out, const LinkedList<T>& a)
{
    if(a.IsEmpty())
    {
        cout << "EMPTY LIST\n";

    }
    else
    {
        Iterator<T> P = a.Begin();
        while(P.GetNode() != NULL)
        {
    //        out << *(P.GetNode());
            if(*(P.GetNode())==*a.cursor)
                out << "[";
            out << P;
            if(*(P.GetNode())==*a.cursor)
                out << "]";

            P.Next();
            out << " --> ";
        }
        out << " NULL" << endl;
    }

    return out;
}

/*******************
  Name: next
  Arguments: none
  Returns returns a copy to the next Node
  Description: moves cursor to the next node.
  Notes: not too bad
  *******************/
template <class T>
Node<T>* LinkedList<T>::Next()
{
    return cursor->next!=NULL?cursor = cursor->next:cursor;
    //return (cursor = cursor->next);
}

template<class T>
Iterator<T> LinkedList<T>::Begin() const
{
    Iterator<T> P(head, this);
    return P;
}

template<class T>
Iterator<T> LinkedList<T>::End() const
{

    Iterator<T> P(rear, this);
    return P;

}

template<class T>
bool LinkedList<T>::IsEmpty() const
{
    if(head==NULL)
        return true;
    else
        return false;
}
