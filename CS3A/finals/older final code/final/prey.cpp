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
    coords validLocations[4];
    int validMoves=0;

    if((row-1)>=0&& g->Grid[row-1][col] == NULL) //move row up
    {
        validLocations[validMoves] = coords(row-1, col);
        validMoves++;

    }

    if((col+1)<=MAX-1 && g->Grid[row][col+1] == NULL)//move one column right
    {
        validLocations[validMoves] = coords(row, col+1);
        validMoves++;
    }

    if((row+1)<=MAX-1 && g->Grid[row+1][col] == NULL)//move one row down
    {
        validLocations[validMoves] = coords(row+1, col);
        validMoves++;
    }

    if((col-1) >=0 && g->Grid[row][col-1] == NULL)//move one row left;
    {
        validLocations[validMoves] = coords(row, col-1);
        validMoves++;
    }

    //cout << "num of validMoves = " << validMoves << endl;



    if(validMoves>0)
    {
        int dir = rand() % validMoves;
        int newRow;
        int newCol;


        if(dir == 0)
        {
            newRow = validLocations[0].GetRow();
            newCol = validLocations[0].GetCol();
//            cout << "case 0 - old ROW/COL: ("  << row << ", " << col << ")\n";
//            cout << "case 0 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

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
//            cout << "case 1 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

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
//            cout << "case 2 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

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
//            cout << "case 3 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            g->Grid[newRow][newCol] = this;
            g->Grid[row][col] = NULL;
            row = newRow;
            col = newCol;
//            cout << "end case 3\n";
        }
    }
    moved = true;
    breedCount++;
    //cout << "new ROW/COL BREED COUNT: ("  << newRow << ", " << newCol << ") " << breedCount << endl;

}

void prey::Breed(grid* g)
{
    if(breedCount == 3)
    {
        coords validLocations[4];
        int validMoves=0;

        if((row-1)>=0 && g->Grid[row-1][col] == NULL) //move row up
        {
            validLocations[validMoves] = coords(row-1, col);
            validMoves++;
            //cout << "can breed up\n";

        }

        if((col+1)<=19 && g->Grid[row][col+1] == NULL)//move one column right
        {
            validLocations[validMoves] = coords(row, col+1);
            validMoves++;
            //cout << "can breed right\n";
        }

        if((row+1)<=19 && g->Grid[row+1][col] == NULL)//move one row down
        {
            validLocations[validMoves] = coords(row+1, col);
            validMoves++;
            //cout << "can breed down\n";
        }

        if((col-1) >=0 && g->Grid[row][col-1] == NULL)//move one row left;
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
                g->Grid[newRow][newCol] = new prey(newRow, newCol);

                //cout << "case 0 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
            else if(dir==1)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new prey(newRow, newCol);

                //cout << "case 1 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
            else if(dir==2)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new prey(newRow, newCol);

                //cout << "case 2 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
            else if(dir==3)
            {
                newRow = validLocations[0].GetRow();
                newCol = validLocations[0].GetCol();
                g->Grid[newRow][newCol] = new prey(newRow, newCol);

                //cout << "case 3 - new ROW/COL: ("  << newRow << ", " << newCol << ")\n";

            }
        }
        breedCount = 0;
    }

}

void prey::Starve(grid *g)
{
}

bool prey::HasMoved()
{
    return moved;
}
