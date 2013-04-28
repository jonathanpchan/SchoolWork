#ifndef COORDS_H
#define COORDS_H
#include <iostream>
using namespace std;

class coords
{
public:
    coords();
    coords(int ROW, int COL);
    coords(const coords& a);
    coords& operator =(const coords& a);
    ~coords();
    int GetRow();
    int GetCol();
    int SetRow(int r);
    int SetCol(int c);

    friend bool operator ==(const coords& a, const coords& b);
    friend ostream &operator <<(ostream &out, const coords &a);
private:
    int row;
    int col;
};

#endif // COORDS_H


