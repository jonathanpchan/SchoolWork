#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H

class CounterType
{
public:
    CounterType();//default constructor
    CounterType(int num);//constructor with terms

    void IncrementCount();//increases counter
    void DecrementCount();//decreases counter
    int GetCounter();//gets coutner for cout

private:
    int counter;
};

#endif // COUNTERTYPE_H
