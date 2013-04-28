#include "coords.h"

coords::coords()
{
    row = 0;
    col = 0;
}

coords::coords(int ROW, int COL)
{
    row = ROW;
    col = COL;
}

coords::coords(const coords &a)
{
    row = a.row;
    col = a.col;

}

coords &coords::operator =(const coords &a)
{
    row = a.row;
    col = a.col;
    return *this;
}

coords::~coords()
{
}

int coords::GetRow()
{
    return row;
}

int coords::GetCol()
{
    return col;
}

ostream &operator <<(ostream &out, const coords &a)
{
    out << "(" << a.row << ", " << a.col <<  ")";
    return out;
}
