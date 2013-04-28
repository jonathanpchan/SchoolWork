#include "hunter.h"
#include "grid.h"

int  hunter::hunterCount = 0;

hunter::hunter()
{
    //face = 'H';
    SetSpecies('H');
    hunterCount++;
}

hunter::hunter(int x, int y)
{
    //face = 'H';
    SetSpecies('H');
    row= x;
    col = y;
    hunterCount++;
}

hunter::~hunter()
{
    hunterCount--;
}


void hunter::Move(grid *g)
{
    coords eatLoc = AvailableFood(g,'X');//hunters can only eat to move around;


     if(!HasMoved())
     {
         if(eatLoc.GetRow() == row && eatLoc.GetCol() == col)
         {
             hungerCount++;
             aliveCount++;
             //moved=true;
             SetMoved();
         }
         else
         {
             //cout << "dinner at " << eatLoc << endl;
             delete g->Grid[eatLoc.GetRow()][eatLoc.GetCol()];
             g->Grid[eatLoc.GetRow()][eatLoc.GetCol()] = this;
             g->Grid[row][col] = NULL;

             row = eatLoc.GetRow();
             col = eatLoc.GetCol();

             hungerCount = 0;
             aliveCount++;
             killCount++;
             breedCount++;//needs to kill before it can breed
             //moved = true;
             SetMoved();
         }
     }
}

void hunter::Breed(grid *g)
{
    if(breedCount >= 3)
    {
        coords breedLoc = AvailablePoints(g);

        if(breedLoc.GetRow()==row && breedLoc.GetCol()==col){}
        else
        {
            g->Grid[breedLoc.GetRow()][breedLoc.GetCol()] = new hunter(breedLoc.GetRow(), breedLoc.GetCol());
            breedCount = 0;
            babyCount++;
        }
    }
}

void hunter::Starve(grid *g)
{
    if(hungerCount==35)
    {
        creature* temp = this;
        g->Grid[row][col] = NULL;
        delete temp;
    }
}

int hunter::GetHunterCount()
{
    return hunterCount;
}
