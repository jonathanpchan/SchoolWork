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

coords creature::AvailablePoints(grid *g)
{
    coords validLocations[4];
    int validMoves=0;

    if((row-1)>=0 && g->Grid[row-1][col] == NULL) //move row up
    {
        validLocations[validMoves] = coords(row-1, col);
       // cout << "Room above " << validLocations[validMoves] << endl;
        validMoves++;

    }

    if((col+1)<= (MAXCOLS-1) && g->Grid[row][col+1] == NULL)//move one column right
    {
        validLocations[validMoves] = coords(row, col+1);
        //cout << "Room to the Right " << validLocations[validMoves] << endl;

        validMoves++;

    }

    if((row+1)<= (MAXROWS-1) && g->Grid[row+1][col] == NULL)//move one row down
    {
        validLocations[validMoves] = coords(row+1, col);
       // cout << "Room Below " << validLocations[validMoves] << endl;
        validMoves++;
    }

    if((col-1) >=0 && g->Grid[row][col-1] == NULL)//move one row left;
    {
        validLocations[validMoves] = coords(row, col-1);
        //cout << "Room to the Left " << validLocations[validMoves] << endl;
        validMoves++;
    }

    if(validMoves>0)
    {
        int num = rand() % validMoves;
        return validLocations[num];
    }
    else
    {
        return coords(row, col);
    }
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



