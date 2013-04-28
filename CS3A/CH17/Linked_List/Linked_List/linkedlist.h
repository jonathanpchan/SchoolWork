#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"


template <class T>
class Node;
template <class T>
class Iterator;


template <class T>
class LinkedList
{
    friend class Node<T>;
    friend class Iterator<T>;
public:
    LinkedList();//default constructor
    LinkedList(const LinkedList& a);//copy constructor
    ~LinkedList();//destructor
    LinkedList<T>& operator =(const LinkedList<T>& a);//assignement operator

    //Node<T>* Search(Node<T>* findThis);//searches for a given node

    Node<T>* Next();//next node from cursor
    Node<T>* Previous();//previous node from cursor
    Node<T>* Remove(Node<T>* removeThis);//remove given node
    Node<T>* Remove();//remove cursor
    Node<T>* Remove(Iterator<T> P);
    Node<T>* GetNode();//returns cursor

    void InsertAfter(Node<T>* insertThis, Iterator<T> afterThis);
    void InsertBefore(Node<T>* insertThis, Iterator<T> beforeThis);

    void Append(Node<T> *insertThis);//appends an item to the list
    void InsertAfter(Node<T>* insertThis, Node<T>* afterThis);//inserts after a given node
    void InsertBefore(Node<T>* insertThis, Node<T>* beforeThis);//inserts before a given node
    void InsertHead(Node<T>* insertThis);//inserts a head
    void InsertSorted(Node<T>* insertThis);//inserts into a sorted list
    void DestroyAllNodes();//destroys the node
    void Sort();//sorts the list

    Iterator<T> Search(Node<T>* findThis);
    Iterator<T> Begin() const;
    Iterator<T> End() const;

    bool IsEmpty() const;

    template <class U>
    friend ostream &operator <<(ostream& out, const LinkedList<U>& A);//outputs the list
private:
    bool sorted;
    Node<T>* head;
    Node<T>* rear;
    Node<T>* cursor;
};
#endif // LINKEDLIST_H
