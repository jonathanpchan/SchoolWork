#include "predator.h"
#include "grid.h"

int  predator::predatorCount = 0;
predator::predator()
{
    //face = 'X';
    SetSpecies('X');
    predatorCount++;
}

predator::predator(int x, int y)
{
    //cout << "new predator current predator count = " << predatorCount  << endl;
    //face = 'X';
    SetSpecies('X');
    row= x;
    col = y;
    predatorCount++;
}

predator::~predator()
{
    predatorCount--;
}


void predator::Move(grid* g)
{
    coords eatLoc = AvailableFood(g,'O');
    coords location = AvailablePoints(g);

    if(!HasMoved())
    {
        if(eatLoc.GetRow() == row && eatLoc.GetCol() == col);
        else
        {
            //cout << "dinner at " << eatLoc << endl;
            delete g->Grid[eatLoc.GetRow()][eatLoc.GetCol()];
            g->Grid[eatLoc.GetRow()][eatLoc.GetCol()] = this;
            g->Grid[row][col] = NULL;

            row = eatLoc.GetRow();
            col = eatLoc.GetCol();

            hungerCount = 0;
            breedCount++;
            aliveCount++;
            killCount++;
            //moved = true;
            SetMoved();
        }
    }

    if(!HasMoved())
    {

        if(location.GetRow() == row && location.GetCol() == col)
        {
            breedCount++;
            hungerCount++;
            aliveCount++;
        }
        else
        {
            g->Grid[location.GetRow()][location.GetCol()] = this;
            g->Grid[row][col] = NULL;
            row = location.GetRow();
            col = location.GetCol();
            breedCount++;
            hungerCount++;
            aliveCount++;
        }
        //moved=true;
        SetMoved();
    }
}

void predator::Breed(grid* g)
{

    if(breedCount == 8)
    {        
        coords breedLoc = AvailablePoints(g);

        if(breedLoc.GetRow()==row && breedLoc.GetCol()==col)
        {
            breedCount=0;
        }
        else
        {
            g->Grid[breedLoc.GetRow()][breedLoc.GetCol()] = new predator(breedLoc.GetRow(), breedLoc.GetCol());
            breedCount = 0;
            babyCount++;
        }
    }
}

void predator::Starve(grid* g)
{
    if(hungerCount==3)
    {
        creature* temp = this;
        g->Grid[row][col] = NULL;
        delete temp;
    }
}

int predator::getPredatorCount()
{
    return predatorCount;
}

