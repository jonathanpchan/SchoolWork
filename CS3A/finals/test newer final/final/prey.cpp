#include "prey.h"
#include "grid.h"

prey::prey()
{
    face = 'O';
    row = 0;
    col = 0;
    breedCount = 0;
    hungerCount = -1;
}

prey::prey(int x, int y)
{
    face = 'O';
    row = x;
    col = y;
    breedCount = 0;
    hungerCount = -1;
}
void prey::Move(grid* g)
{
    coords location = AvailablePoints(g);

    if(!HasMoved())
    {
        if(location.GetRow() == row && location.GetCol() == col)
        {
            breedCount++;
        }
        else
        {
            g->Grid[location.GetRow()][location.GetCol()] = this;
            g->Grid[row][col] = NULL;
            row = location.GetRow();
            col = location.GetCol();
            breedCount++;
        }
        SetMoved();
    }
}

void prey::Breed(grid* g)
{
    if(breedCount == 3)
    {
        //cout << "prey breed";
        coords breedLoc = AvailablePoints(g);

        if(breedLoc.GetRow()==row && breedLoc.GetCol()==col)
        {
            breedCount = 0;
        }
        else
        {
            g->Grid[breedLoc.GetRow()][breedLoc.GetCol()] = new prey(breedLoc.GetRow(), breedLoc.GetCol());
            breedCount = 0;
        }

    }

}

void prey::Starve(grid *g)
{
}

bool prey::HasMoved()
{
    return moved;
}
