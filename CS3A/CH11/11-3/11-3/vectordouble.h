#ifndef VECTORDOUBLE_H
#define VECTORDOUBLE_H

class VectorDouble
{
public:
    VectorDouble();
    VectorDouble(int Count);//number of elements in the intial dynamic array
    VectorDouble(const VectorDouble &copyThis);
    ~VectorDouble();


    void Show();//shows
    void Set(double num);//push back
    int GetMax();//capacity
    int GetCount();//size
    int ValueAt(int i);//value at i
    void ChangeValueAt(int num, int i);//change the value at i
    void Resize(int size);//resize it

    friend bool operator ==(const VectorDouble &A, const VectorDouble &B);//equivalence operator
    VectorDouble& operator =(const VectorDouble &copyThis);//overload equal operator



private:
    double* doubleArray;
    int maxCount;//size for dynamic array
    int count;//# of positions currently holding values
};

#endif // VECTORDOUBLE_H
