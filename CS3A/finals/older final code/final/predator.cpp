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
    coords validLocations[4];
    coords validPrey[4];
    int validMoves=0;
    int preyNum=0;

//    coords test = AvailablePoints(g);
//    cout << "test - " << test << endl;

    //check up
    if((row-1)>=0 && g->Grid[row-1][col] == NULL) //move row up
    {
        validLocations[validMoves] = coords(row-1, col);
        validMoves++;

//        cout << "case 1 - old ROW/COL: ("  << row << ", " << col << ")\n";

    }
    else if((row-1)>=0 && g->Grid[row-1][col] != NULL)
    {
        if(g->Grid[row-1][col]->getSpecies() == 'O' )
        {
            validPrey[preyNum] = coords(row-1, col);
            preyNum++;
        }

    }

    //check right
    if((col+1)<=MAX-1 && g->Grid[row][col+1] == NULL)//move one column right
    {
        validLocations[validMoves] = coords(row, col+1);
        validMoves++;
    }
    else if((col+1)<=MAX-1 && g->Grid[row][col+1] != NULL)
    {
        if(g->Grid[row][col+1]->getSpecies() == 'O')
        {
            validPrey[preyNum] = coords(row, col + 1);
            preyNum++;
        }
    }


    //check down
    if((row+1)<=MAX-1 && g->Grid[row+1][col] == NULL)//move one row down
    {
        validLocations[validMoves] = coords(row+1, col);
        validMoves++;
    }
    else if((row+1)<=MAX-1 && g->Grid[row+1][col] != NULL)
    {
        if(g->Grid[row+1][col]->getSpecies() == 'O' )
        {
            validPrey[preyNum] = coords(row+1, col);
            preyNum++;
        }
    }


    //check left
    if((col-1) >=0 && g->Grid[row][col-1] == NULL)//move one row left;
    {
        validLocations[validMoves] = coords(row, col-1);
        validMoves++;
    }
    else if((col-1) >=0 && g->Grid[row][col-1] != NULL)
    {
        if(g->Grid[row][col-1]->getSpecies() == 'O')
        {
            validPrey[preyNum] = coords(row, col-1);
            preyNum++;
        }
    }


    if(preyNum>0)//eating prey
    {

        int dir = rand() % preyNum;

        int newRow;
        int newCol;

        if(dir == 0)
        {

            newRow = validPrey[0].GetRow();
            newCol = validPrey[0].GetCol();
//            cout << "prey case 0 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "prey case 0 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";
//            cout <<  "prey case 0 - newROW/COL should be " << this->getSpecies() << endl;
            delete g->Grid[newRow][newCol];
            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;

            row = newRow;
            col = newCol;
//            cout << "end case 0\n";

        }
        else if(dir==1)
        {
            newRow = validPrey[1].GetRow();
            newCol = validPrey[1].GetCol();
//            cout << "prey case 1 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "prey case 1 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";
//            cout <<  "prey case 1 - newROW/COL should be " << this->getSpecies() << endl;

            delete g->Grid[newRow][newCol];
            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;

            row = newRow;
            col = newCol;
//            cout << "end case 1\n";
        }
        else if(dir==2)
        {
            newRow = validPrey[2].GetRow();
            newCol = validPrey[2].GetCol();
//            cout << "prey case 2 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "prey case 2 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";
//            cout <<  "prey case 2 - newROW/COL should be " << this->getSpecies() << endl;


            delete  g->Grid[newRow][newCol];
            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;

            row = newRow;
            col = newCol;
//            cout << "end case 2\n";
        }
        else if(dir==3)
        {
            newRow = validPrey[3].GetRow();
            newCol = validPrey[3].GetCol();
//            cout << "prey case 3 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "prey case 3 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";
//            cout <<  "prey case 3 - newROW/COL should be " << this->getSpecies() << endl;

            delete g->Grid[newRow][newCol];
            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;
            row = newRow;
            col = newCol;
//            cout << "end case 3\n";
        }
        hungerCount = 0;
    }

    //cout << "num of validMoves = " << validMoves << endl;

    if(validMoves>0 && preyNum == 0)
    {

        int dir = rand() % validMoves;

        int newRow;
        int newCol;

        if(dir == 0)
        {
            newRow = validLocations[0].GetRow();
            newCol = validLocations[0].GetCol();
//            cout << "case 0 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "case 0 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";

            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;

            row = newRow;
            col = newCol;
//            cout << "end case 0\n";

        }
        else if(dir==1)
        {
            newRow = validLocations[1].GetRow();
            newCol = validLocations[1].GetCol();
//            cout << "case 1 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "case 1 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";

            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;

            row = newRow;
            col = newCol;
//            cout << "end case 1\n";
        }
        else if(dir==2)
        {
            newRow = validLocations[2].GetRow();
            newCol = validLocations[2].GetCol();
//            cout << "case 2 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "case 2 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";

            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;

            row = newRow;
            col = newCol;
//            cout << "end case 2\n";
        }
        else if(dir==3)
        {
            newRow = validLocations[3].GetRow();
            newCol = validLocations[3].GetCol();
//            cout << "case 3 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "case 3 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";

            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;
            row = newRow;
            col = newCol;
//            cout << "end case 3\n";
        }
        hungerCount++;
    }

    moved=true;
    breedCount++;

}

void predator::Breed(grid* g)
{

    if(breedCount == 8)
    {
        coords validLocations[4];
        int validMoves=0;

        if((row-1)>=0 && g->Grid[row-1][col] == NULL) //move row up
        {
            validLocations[validMoves] = coords(row-1, col);
            validMoves++;
            //cout << "can breed up\n";

        }

        if((col+1)<=MAX-1 && g->Grid[row][col+1] == NULL)//move one column right
        {
            validLocations[validMoves] = coords(row, col+1);
            validMoves++;
            //cout << "can breed right\n";
        }

        if((row+1)<=MAX-1 && g->Grid[row+1][col] == NULL)//move one row down
        {
            validLocations[validMoves] = coords(row+1, col);
            validMoves++;
            //cout << "can breed down\n";
        }

        if((col-1) >=0 && g->Grid[row][col-1] == NULL )//move one row left;
        {
            validLocations[validMoves] = coords(row, col-1);
            validMoves++;
            //cout << "can breed left\n";
        }

        if(validMoves>0)
        {
            int dir = rand() % validMoves;
            int newRow;
            int newCol;


            if(dir == 0)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new predator(newRow, newCol);

                //cout << "case 0 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
            else if(dir==1)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new predator(newRow, newCol);

                //cout << "case 1 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
            else if(dir==2)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new predator(newRow, newCol);

                //cout << "case 2 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
            else if(dir==3)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new predator(newRow, newCol);

                //cout << "case 3 - newROW/COL: ("  << newRow << ", " << newCol << ")\n";
            }
        }
        breedCount = 0;
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
