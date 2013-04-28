#include "creature.h"
#include "grid.h"

creature::creature()
{
    face = '-';
    row = 0;
    col = 0;
    breedCount = 0;
    hungerCount = -1;
    moved = false;
}

creature::creature(int x, int y)
{
    face = '-';
    row = x;
    col = y;
    breedCount = 0;
    hungerCount = -1;
    moved = false;
}

bool creature::HasMoved()
{
    return moved;
}

void creature::SetMoved()
{
    moved = true;
}

void creature::ResetMove()
{
    moved=false;
}

char creature::getSpecies()
{
    return face;
}

int creature::Row()
{
    return row;
}
int creature::Col()
{
    return col;
}

ostream &operator <<(ostream &out, const creature &a)
{
    out << " " << a.face <<  " ";
    return out;
}

void creature::Move(grid* g)
{

}



void creature::Breed(grid* g)
{

}



