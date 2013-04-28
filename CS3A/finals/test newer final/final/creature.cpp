#include "creature.h"
#include "grid.h"


creature::creature()
{
    face = '-';
    row = 0;
    col = 0;
    breedCount = 0;
    hungerCount = 0;
    babyCount = 0;
    killCount = 0;
    aliveCount = 0;
    moved = false;
}

creature::creature(int x, int y)
{
    row = x;
    col = y;
    breedCount = 0;
    hungerCount = 0;
    babyCount = 0;
    killCount = 0;
    aliveCount = 0;
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

void creature::DisplayInfo()
{
    cout << "The creature at ("<< col << ", " << row <<") ";
    if(face == 'X')
    {
        cout <<"is a Predator. \n";
        cout << "It has been alive for " << aliveCount << " cycles. \n";
        cout << "It has eaten " << killCount << " prey. \n";
        cout << "It has produced " << babyCount << " babies \n";
        cout << "It will die if it does not eat within " << 3-hungerCount << " cycles. \n";
        cout << "It will produce offspring in " << 8-breedCount << " cycles. \n\n\n";
    }
    else if(face == 'O')
    {
        cout << "is Prey.\n";
        cout << "It has been alive for " << aliveCount << " cycles. \n";
        cout << "It has produced " << babyCount << " babies \n";
        cout << "It will produce offspring in " << 3-breedCount << " cycles. \n\n\n";
    }
    else if(face == 'H')
    {
        cout <<"is a Hunter. \n";
        cout << "It has been alive for " << aliveCount << " cycles. \n";
        cout << "It has eaten " << killCount << " predators. \n";
        cout << "It has produced " << babyCount << " babies \n";
        cout << "It will die if it does not eat within " << 35-hungerCount << " cycles. \n";
        if(3-breedCount <=0)
            cout << "It is waiting for space to breed";
        else
            cout << "It will produce offspring in " << 3-breedCount << " Kills. \n\n\n";
    }
}


char creature::getSpecies()
{
    return face;
}

void creature::SetSpecies(char s)
{
    face = s;
}

coords creature::AvailablePoints(grid *g)
{
    coords validLocations[8];
    int validMoves=0;

    if((row-1)>=0 && g->Grid[row-1][col] == NULL) //move row up
    {
        validLocations[validMoves] = coords(row-1, col);
        validMoves++;
    }

    if((col+1)<= (MAXCOLS-1) && g->Grid[row][col+1] == NULL)//move one column right
    {
        validLocations[validMoves] = coords(row, col+1);
        validMoves++;
    }

    if((row+1)<= (MAXROWS-1) && g->Grid[row+1][col] == NULL)//move one row down
    {
        validLocations[validMoves] = coords(row+1, col);
        validMoves++;
    }

    if((col-1) >=0 && g->Grid[row][col-1] == NULL)//move one row left;
    {
        validLocations[validMoves] = coords(row, col-1);
        validMoves++;
    }

    if(((row-1) >= 0 && (col-1)>= 0) && g->Grid[row-1][col-1] == NULL)//check northwest
    {
        validLocations[validMoves] = coords(row-1, col-1);
        validMoves++;
    }


    if(((row+1) <= (MAXROWS-1) && (col-1)>=0) && g->Grid[row+1][col-1] == NULL)//check southwest
    {
        validLocations[validMoves] = coords(row+1, col-1);
        validMoves++;
    }

    if(((row+1) <= (MAXROWS-1) && (col+1)<=(MAXCOLS-1)) && g->Grid[row+1][col+1] == NULL)//southeast
    {
        validLocations[validMoves] = coords(row+1, col+1);
        validMoves++;
    }

    if(((row-1) >= 0 && (col+1)<=(MAXCOLS-1)) && g->Grid[row-1][col+1] == NULL)//check NorthEast
    {
        validLocations[validMoves] = coords(row-1, col+1);
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

coords creature::AvailableFood(grid *g, char c)
{
    coords validPrey[8];
    int numPrey=0;

    if((row-1)>=0 && g->Grid[row-1][col] != NULL) //check row up
    {
        if(g->Grid[row-1][col]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row-1, col);
            numPrey++;
        }
    }

    if((col+1) <= (MAXCOLS-1) && g->Grid[row][col+1] != NULL)//check one column right
    {
        if(g->Grid[row][col+1]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row, col+1);
            numPrey++;
        }
    }

    if((row+1) <= (MAXROWS-1) && g->Grid[row+1][col] != NULL)//check one row down
    {
        if(g->Grid[row+1][col]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row+1, col);
            numPrey++;
        }
    }

    if((col-1) >=0 && g->Grid[row][col-1] != NULL)//check one row left;
    {
        if(g->Grid[row][col-1]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row, col-1);
            numPrey++;
        }
    }

    if(((row-1) >= 0 && (col-1)>= 0) && g->Grid[row-1][col-1] != NULL)//check northwest
    {
        if(g->Grid[row-1][col-1]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row-1, col-1);
            numPrey++;
        }
    }

    if(((row+1) <= (MAXROWS-1) && (col-1)>= 0) && g->Grid[row+1][col-1] != NULL)//check southwest
    {
        if(g->Grid[row+1][col-1]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row+1, col-1);
            numPrey++;
        }
    }

    if(((row+1) <= (MAXROWS-1) && (col+1) <= (MAXCOLS-1)) && g->Grid[row+1][col+1] != NULL)//check southeast
    {
        if(g->Grid[row+1][col+1]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row+1, col+1);
            numPrey++;
        }
    }

    if(((row-1) >= 0 && (col+1) <= (MAXCOLS-1)) && g->Grid[row-1][col+1] != NULL)//check southeast
    {
        if(g->Grid[row-1][col+1]->getSpecies() == c)
        {
            validPrey[numPrey] = coords(row-1, col+1);
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

int creature::Row(){//returns row
    return row;
}
int creature::Col(){//returns col
    return col;
}

void creature::SetRow(int ROW)
{
    row=ROW;
}

void creature::SetCol(int COL)
{
    col=COL;
}

ostream &operator <<(ostream &out, const creature &a)
{
    out << " " << a.face <<  " ";
    return out;
}

void creature::Move(grid* g){}

void creature::Breed(grid* g){}

creature::~creature(){}


int creature::GetKillCount()
{
    return killCount;
}

int creature::GetBabyCount()
{
    return babyCount;
}

int creature::GetAliveCount()
{
    return aliveCount;
}


