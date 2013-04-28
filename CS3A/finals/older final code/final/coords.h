#ifndef COORDS_H
#define COORDS_H
#include <iostream>
using namespace std;

class coords
{
public:
    coords();
    coords(int ROW, int COL);
    int GetRow();
    int GetCol();


    friend ostream &operator <<(ostream &out, const coords &a);
private:
    int row;
    int col;
};

#endif // COORDS_H


