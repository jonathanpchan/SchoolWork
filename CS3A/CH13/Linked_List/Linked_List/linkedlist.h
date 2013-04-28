#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"

class LinkedList
{
public:
    LinkedList();//default constructor
    LinkedList(const LinkedList& a);//copy constructor
    ~LinkedList();//destructor
    Node* Search(Node* findThis);//searches for a given node
    Node* Next();//next node from cursor
    Node* Previous();//previous node from cursor
    Node* Previous(Node* findThis);//previous from given node
    Node* Remove(Node* removeThis);//remove given node
    Node* Remove();//remove cursor
    Node* GetNode();//returns cursor
    void Sort();//sorts the list
    void Append(Node* insertThis);//appends an item to the list

    void InsertHead(Node* insertThis);//inserts a head
    void InsertAfter(Node* insertThis, Node* afterThis);//inserts after a given node
    void InsertBefore(Node* insertThis, Node* beforeThis);//inserts before a given node
    void InsertSorted(Node* insertThis);//inserts into a sorted list
    void DestroyAllNodes();//destroys the node
    LinkedList& operator =(const LinkedList& a);//assignement operator
    friend ostream &operator <<(ostream& out, LinkedList& A);//outputs the list
private:
    bool sorted;
    Node* head;
    Node* rear;
    Node* cursor;
};

#endif // LINKEDLIST_H

