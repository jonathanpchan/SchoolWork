#include "linkedlist.h"
#include "node.h"
#include <cstdlib>
#include <iostream>

using namespace std;
/*
  DEFAULT CONSTRUCTOR
  */
LinkedList::LinkedList()
{
    head = NULL;
    cursor = NULL;
    rear = NULL;
    sorted = false;
}


/*******************
  Copy CONSTRUCTOR
  *******************/
LinkedList::LinkedList(const LinkedList& a)
{
    try
    {
        Node* walker = a.head;
        sorted = a.sorted;

        DestroyAllNodes();
        while(walker!=NULL)
        {
            Node* newNode = new Node(*walker);
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

/*******************
  Destructor
  *******************/
LinkedList::~LinkedList()
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
void LinkedList::InsertAfter(Node *insertThis, Node *afterThis)
{
    const char ch = 'z';

    try
    {
        if(sorted)
            throw true;
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
void LinkedList::InsertBefore(Node *insertThis, Node *beforeThis)
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
            Node *afterThis = Previous(beforeThis);
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
  Name: Search
  Arguments: a single node
  Returns returns a pointer to the node if found, otherwise null
  Description: inserts before a given node
  Notes: pretty simple, uses insertAfter and a previous function
  *******************/
Node* LinkedList::Search(Node *findThis)
{
    Node* walker = head;
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
  Arguments: zero argument previous
  Returns previous to cursor
  Description: returns previous to the cursor
  Notes: uses previous function
  *******************/
Node *LinkedList::Previous()
{
    return (cursor = Previous(cursor));
}

/*******************
  Name: Previous
  Arguments: two nodes
  Returns a pointer to the previous node to the given node
  Description: returns previous to a given node
  Notes: not too difficult
  *******************/
Node* LinkedList::Previous(Node *findThis)
{
    bool flag = false;
    Node *walker = head, *prevNode;

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
  Name: Remove
  Arguments: a node
  Returns a copy to the given node
  Description: removes a given node
  Notes: not too bad
  *******************/
Node* LinkedList::Remove(Node *removeThis)
{
    try
    {
        if(removeThis == NULL)
            throw -1;

        Node* before, *removed;

        if(removeThis==head)
        {
            removed = head;

            head=removeThis->next;
            cursor = head;

            removed->next = NULL;
        }
        else
        {
            before = Previous(removeThis);
            removed = Search(removeThis);

            before->next = removed->next;
            removed->next = NULL;

            cursor = before->next;

            if(cursor == NULL)
                cursor = before;
        }
        return removed;
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
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
Node *LinkedList::Remove()
{
    return Remove(cursor);
}

/*******************
  Name: Getnode
  Arguments: none
  Returns returns the cursor
  Description: returns the curspr
  Notes: not too bad,uses insert sroted
  *******************/
Node *LinkedList::GetNode()
{
    return cursor;
}

/*******************
  Name: Sort
  Arguments: none
  Returns none void function
  Description: Sorts the list
  Notes: not too bad
  *******************/
void LinkedList::Sort()
{
    try
    {
        LinkedList newList;
        Node* walker = head;


        sorted = true;
        while(walker!=NULL)
        {
            Node* newNode = new Node(*walker);
            newList.InsertSorted(newNode);
            walker = walker->next;
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
void LinkedList::Append(Node *insertThis)
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
            Node* walker = head;

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
  Name: InsertHead
  Arguments: a node
  Returns none, void function
  Description: Inserts a new head.
  Notes: not too bad
  *******************/
void LinkedList::InsertHead(Node *insertThis)
{
    try
    {
        if(sorted)
            throw true;
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
void LinkedList::InsertSorted(Node *insertThis)
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
            Node* here = Search(insertThis);

            if(here == NULL)
            {
                Node* walker = head;
                cursor = head;

                while(*insertThis <= *walker && walker->next != NULL)
                {
                    walker = walker->next;
                    cursor = walker;
                }

                if(*insertThis <= *cursor)
                {   sorted = false;
                    InsertAfter(insertThis,cursor);
                    sorted = true;

                }
                else
                {
                    sorted = false;
                    InsertBefore(insertThis,cursor);
                    sorted=true;
                }
            }
            else
            {
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
}

/*******************
  Name: DestroyAllNodes
  Arguments: none
  Returns none
  Description: destroys all nodes sets them to Null
  Notes: not too bad
  *******************/
void LinkedList::DestroyAllNodes()
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
LinkedList& LinkedList::operator =(const LinkedList &a)
{
    try
    {
        Node* walker = a.head;
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
            while(walker!=NULL)
            {
                Node* newNode = new Node(*walker);
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
  Name: <<
  Arguments: linked list
  Returns ostream
  Description: outputs a linked list
  Notes: not too bad
  *******************/
ostream& operator <<(ostream& out, LinkedList& A)
{
    Node *walker = A.head;
    while(walker != NULL)
    {
        if (walker == A.cursor)
            cout<<"[";
        out << *walker;
        if (walker == A.cursor)
            cout<<"]";
        walker = walker->next;
        cout << " --> ";
    }
    out << " NULL" << endl;
    return out;
}

/*******************
  Name: next
  Arguments: none
  Returns returns a copy to the next node
  Description: moves cursor to the next node.
  Notes: not too bad
  *******************/
Node *LinkedList::Next()
{
    return cursor->next!=NULL?cursor = cursor->next:cursor;
    //return (cursor = cursor->next);
}
