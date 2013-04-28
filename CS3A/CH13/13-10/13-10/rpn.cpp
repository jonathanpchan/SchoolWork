#include "rpn.h"
#include <cstdlib>

rpn::rpn()
{
    head = NULL;
    cursor = NULL;

}

rpn::rpn(const rpn &copyThis)
{
    try
    {
        node* walker = copyThis.head;

        delete head;
        head = NULL;
        cursor = NULL;
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


rpn::~rpn()
{
    delete head;

}

rpn &rpn::operator =(const rpn &a)
{
    try
    {
        node* walker = a.head;

        if(a.head == NULL)
        {
            delete head;
            head = NULL;
            cursor = NULL;
            return *this;
        }
        if(a.head == head)
            return *this;
        else
        {
            delete head;
            head = NULL;
            cursor = NULL;
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
  Name: Push
  Arguments: a node
  Returns none, void function
  Description: Inserts a new head.
  Notes: not too bad
  *******************/
void rpn::Push(node* insertThis)
{
    try
    {
        if(insertThis == NULL)
            throw -1;

        insertThis->next = head;
        head=insertThis;
    }
    catch(int e)
    {
        cout<<"CAUTION! Number is NULL!"<<endl;
    }
}

/*******************
  Name: Pop
  Arguments: a node
  Returns node*
  Description: returns and removes the node.
  Notes: not too bad
  *******************/
node* rpn::Pop()
{
    node* temp;
    if(head==NULL)
    {
        temp = NULL;
        return temp;
    }
    temp = head;
    head=head->next;
    temp->next=NULL;
//    return(Remove(head));

    return temp;

}

/*******************
  Name: empty
  Arguments: none
  Returns bool
  Description:checks if stack is empty
  Notes: not too bad
  *******************/
bool rpn::Empty()
{
    if(head==NULL)
        return true;
    else
        return false;
}

/*******************
  Name: calculate
  Arguments: character
  Returns none
  Description:calculates the stack using rpn
  Notes: not too bad
  *******************/
void rpn::calculate(char operation)
{
    node* t1;
    node* t2;
    node* t3;
    int answer;
    switch(operation)
    {
    case '+':
        try
        {
            t1=Pop();
            t2=Pop();
            if(t1==NULL || t2==NULL)
                throw -1;
        }
        catch(int e)
        {
            cout << "not enough operands\n";
            exit(1);
        }

        t3=new node;
        *t3 = *t1 + *t2;
        Push(t3);
        break;

    case '-':
        try
        {
            t1=Pop();
            t2=Pop();
            if(t1==NULL || t2==NULL)
                throw -1;
        }
        catch(int e)
        {
            cout << "not enough operands\n";
            exit(1);
        }
        t3=new node;
        *t3=*t2 - *t1;
        Push(t3);
        break;

    case '*':
        try
        {
            t1=Pop();
            t2=Pop();
            if(t1==NULL || t2==NULL)
                throw -1;
        }
        catch(int e)
        {
            cout << "not enough operands\n";
            exit(1);
        };
        t3=new node;
        *t3 = *t1 * *t2;
        Push(t3);
        break;

    case '/':
        try
        {
            t1=Pop();
            t2=Pop();
            if(t1==NULL || t2==NULL)
                throw -1;
        }
        catch(int e)
        {
            cout << "not enough operands\n";
            exit(1);
        }
        t3=new node;
        *t3 = *t2 / *t1;
        Push(t3);
        break;
    case 'Q':

        answer = head->data;

        t2=Pop();
        t1=Pop();
        if(t1 != NULL)
        {
            cout << "Error: Stack still has too many items\n";

            exit(1);

        }
        else
        {

            if(t2!=NULL)
            {
            cout << "The the top of the stack is " << answer << endl;
            }
            else if(head==NULL)
            {
                cout << "Empty List, nothing to Pop\n";
            }
        }

        break;
    }
}
/*******************
  Name: Append
  Arguments: a node
  Returns none void function
  Description: appends a node to the end of the list
  Notes: not too bad
  *******************/
void rpn::Append(node *insertThis)
{
    try
    {

        if(insertThis == NULL)
            throw -1;

        if(head == NULL)
            Push(insertThis);
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



