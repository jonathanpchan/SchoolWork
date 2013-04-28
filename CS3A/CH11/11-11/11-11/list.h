#ifndef LIST_H
#define LIST_H

class List
{
public:
    List();
    ~List();
    List(const List &copyThis);

    void Show();
    void Set(double Item);
    int GetCount();
    double GetItemAt(int i);
    double GetLast();
    void DeleteLast();
    List& operator =(const List &copyThis);
private:
    double* list;
    int count;
    int MAX;
};

#endif // LIST_H
