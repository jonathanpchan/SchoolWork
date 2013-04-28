#include "prey.h"
#include "grid.h"

int prey::preyCount=0;

prey::prey()
{
    //face = 'O';
    SetSpecies('O');
    preyCount++;
}

prey::prey(int x, int y)
{
//    face = 'O';
    SetSpecies('O');
    row = x;
    col = y;
    preyCount++;
}

prey::~prey()
{
    preyCount--;
}
void prey::Move(grid* g)
{
    coords location = AvailablePoints(g);

    if(!HasMoved())
    {
        if(location.GetRow() == row && location.GetCol() == col)
        {
            breedCount++;
            aliveCount++;
        }
        else
        {
            g->Grid[location.GetRow()][location.GetCol()] = this;
            g->Grid[row][col] = NULL;
            row = location.GetRow();
            col = location.GetCol();
            breedCount++;
            aliveCount++;
        }
        SetMoved();
    }
}

void prey::Breed(grid* g)
{
    if(breedCount == 3)
    {
        coords breedLoc = AvailablePoints(g);

        if(breedLoc.GetRow()==row && breedLoc.GetCol()==col)
        {
            breedCount=0;
        }
        else
        {
            g->Grid[breedLoc.GetRow()][breedLoc.GetCol()] = new prey(breedLoc.GetRow(), breedLoc.GetCol());
            breedCount = 0;
            babyCount++;
        }
    }
}
int prey::getPreyCount()
{
    return preyCount;
}
void prey::Starve(grid *g)
{
//    if(babyCount==5)
//    {
//        creature* temp = this;
//        g->Grid[row][col] = NULL;
//        delete temp;
//    }
}

