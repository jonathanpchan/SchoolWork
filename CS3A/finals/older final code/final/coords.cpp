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
