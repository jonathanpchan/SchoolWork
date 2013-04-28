#include "predator.h"
#include "grid.h"

predator::predator()
{
    face = 'X';
    row= 0;
    col = 0;
    hungerCount = 0;
    breedCount = 0;
    moved = false;
}

predator::predator(int x, int y)
{
    face = 'X';
    row= x;
    col = y;
    hungerCount = 0;
    breedCount = 0;
    moved = false;
}



void predator::Move(grid* g)
{
    coords eatLoc = AvailablePrey(g);
    coords location = AvailablePoints(g);


    if(!moved)
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
            moved = true;
        }
    }

    if(!moved)
    {
        //cout <<"blah";
        //cout << "No Prey\n";
        //cout << "predator at (" << row << ", " << col << ") can move\n";

        if(location.GetRow() == row && location.GetCol() == col)
        {
           // cout << "predator could not move, location has not changed\n";
            breedCount++;
            hungerCount++;
        }
        else
        {
            //cout << "predator moving to " << location << endl;
            g->Grid[location.GetRow()][location.GetCol()] = this;
            g->Grid[row][col] = NULL;
            row = location.GetRow();
            col = location.GetCol();
            breedCount++;
            hungerCount++;
        }
        moved=true;
    }
    //cout << "current hunger " << hungerCount << endl;
    //cout << "current Breed num " << breedCount << endl;
}

void predator::Breed(grid* g)
{

    if(breedCount == 8)
    {        
       // cout << "predator at (" << row << ", " << col << ") can breed\n";
        coords breedLoc = AvailablePoints(g);

        if(breedLoc.GetRow()==row && breedLoc.GetCol()==col)
        {
            breedCount=0;
        }
        else
        {           //cout << "predator moving to " << breedLoc << endl;
            g->Grid[breedLoc.GetRow()][breedLoc.GetCol()] = new predator(breedLoc.GetRow(), breedLoc.GetCol());
            breedCount = 0;
        }

    }
}

void predator::Starve(grid* g)
{
    if(hungerCount==3)
    {
        g->Grid[row][col] = NULL;
        delete g->Grid[row][col];
    }

}

bool predator::HasMoved()
{
    return moved;
}

coords predator::AvailablePrey(grid *g)
{
    coords validPrey[4];
    int numPrey=0;

    if((row-1)>=0 && g->Grid[row-1][col] != NULL) //check row up
    {
        if(g->Grid[row-1][col]->getSpecies() == 'O' )
        {
            validPrey[numPrey] = coords(row-1, col);
           // cout << "prey at " << validPrey[numPrey] << endl;
            numPrey++;
        }
    }

    if((col+1) <= (MAXCOLS-1) && g->Grid[row][col+1] != NULL)//check one column right
    {
        if(g->Grid[row][col+1]->getSpecies() == 'O' )
        {
            validPrey[numPrey] = coords(row, col+1);
            //cout << "prey at " << validPrey[numPrey] << endl;
            numPrey++;
        }
    }

    if((row+1) <= (MAXROWS-1) && g->Grid[row+1][col] != NULL)//check one row down
    {
        if(g->Grid[row+1][col]->getSpecies() == 'O' )
        {
            validPrey[numPrey] = coords(row+1, col);
           // cout << "prey at " << validPrey[numPrey] << endl;
            numPrey++;
        }
    }

    if((col-1) >=0 && g->Grid[row][col-1] != NULL)//check one row left;
    {
        if(g->Grid[row][col-1]->getSpecies() == 'O' )
        {
            validPrey[numPrey] = coords(row, col-1);
            //cout << "prey at " << validPrey[numPrey] << endl;
            numPrey++;
        }
    }



    if(numPrey>0)
    {
        int num = rand() % numPrey;
        return validPrey[num];
    }
    else
    {
        return coords(row, col);
    }
}
