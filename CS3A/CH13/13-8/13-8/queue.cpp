#include "queue.h"
#include <iostream>
#include "node.h"

using namespace std;

queue::queue()
{
    head = NULL;
    rear = NULL;
    cursor = NULL;

}
queue::~queue()
{

}


/*******************
  Name: Search
  Arguments: a single node
  Returns returns a pointer to the node if found, otherwise null
  Description: inserts before a given node
  Notes: pretty simple, uses insertAfter and a previous function
  *******************/
node* queue::Search(node *findThis)
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
node* queue::Previous(node *findThis)
{
    bool flag = false;
    node *walker = head, *prevnode;

    if(findThis == head)
        return head;

    while(walker != findThis && walker->next!=NULL)
    {
        prevnode = walker;
        walker = walker->next;
        flag = true;
    }

    prevnode = flag!=true?NULL:prevnode;
    cursor = prevnode;
    return prevnode;
}

/*******************
  Name: Remove
  Arguments: a node
  Returns a copy to the given node
  Description: removes a given node
  Notes: not too bad
  *******************/
node* queue::Remove(node *removeThis)
{
    try
    {
        if(removeThis == NULL)
            throw -1;

        node* before, *removed;

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
  Name: Append
  Arguments: a node
  Returns none void function
  Description: appends a node to the end of the list
  Notes: not too bad
  *******************/
void queue::Append(node *insertThis)
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
  Name: InsertHead
  Arguments: a node
  Returns none, void function
  Description: Inserts a new head.
  Notes: not too bad
  *******************/
void queue::InsertHead(node *insertThis)
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

bool queue::Empty()
{
    if(head==NULL)
        return true;
    else
        return false;
}



node* queue::Dequeue()
{
    if(head==NULL)
    {
        cout << "ERROR REMOVNING NULL";
    }
    node* temp;
    temp = head;
    head=head->next;
    temp->next=NULL;
//    return(Remove(head));

    return temp;
}

long queue::Time()
{
    long seconds;
    seconds = static_cast<long>(time(NULL));
    return seconds;
}

int queue::getTicket()
{
    return head->ticket;
}

long queue::getTime()
{
    return head->time;
}
