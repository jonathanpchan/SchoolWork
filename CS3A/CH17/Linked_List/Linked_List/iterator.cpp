#include "iterator.h"


template<class T>
Iterator<T>::Iterator()
{
    ptr=NULL;
    list=NULL;
}

template<class T>
Iterator<T>::Iterator(Node<T> *n, const LinkedList<T>* l)
{
    ptr = n;
    list = l;
}

template<class T>
Node<T>* Iterator<T>::GetNode() const
{
    if(ptr!=NULL)
        return ptr->Copy();
    else
        return NULL;

}

template<class T>
Node<T>* Iterator<T>::GetNext() const
{
//    ptr=ptr->next;
//    if(ptr!=NULL)
//    {

//        return ptr->Copy();
//    }
//    else
//        return NULL;

    if(ptr->next != NULL)
    {
        return ptr->next->Copy();
    }
    else
        return NULL;

}

template<class T>
Node<T>* Iterator<T>::GetPrev()
{
//    ptr=ptr->prev;
//    if(ptr!=NULL)
//    {

//        return ptr->Copy();
//    }
//    else
//        return NULL;

}

template<class T>
Node<T>* Iterator<T>::GetFirst()
{
    if(list!=NULL)
    {
        return(ptr = list->head->Copy());
    }
    else
        return NULL;


}

template<class T>
Node<T>* Iterator<T>::GetRear()
{
   if(list != NULL)
       return(ptr = list->rear->Copy());
   else
       return NULL;
}

template <class T>
void Iterator<T>::Next()
{
    ptr=ptr->next;
}

template <class T>
void Iterator<T>::Prev()
{
    ptr=ptr->prev;
}


template <class T>
bool Iterator<T>::GoPrev()
{
    if(ptr->prev != NULL)
        return true;
    else
        return false;
}

template<class T>
ostream &operator <<(ostream& out, const Iterator<T>& a)
{
    out << *a.ptr;
    return out;
}
