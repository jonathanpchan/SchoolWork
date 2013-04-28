#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
public:
    Counter();//default constructor
    Counter(int Max);//constructor for max.

    int Reset();//resets counter to 0
    int Incr1();//increments 1
    int Incr10();//increments 10
    int Incr100();//increments 100
    int Incr1000();//increments 1000
    int GetCount();//gets counter
    int GetMax();//gets max
private:
    int counter;
    int max;

};

#endif // COUNTER_H
