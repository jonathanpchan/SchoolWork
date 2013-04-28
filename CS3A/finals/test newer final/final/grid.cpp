#include "grid.h"


grid::grid()
{
    cout << "making grid\n";
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
            Grid[i][j] = NULL;

    cout << "finished grid\n";
}

void grid::Populate()
{
    int row, column;

    //(.0125*MAXROWS*MAXROWS)
    //insert predators

    for(int i=0;i<(.0125*MAXROWS*MAXCOLS);i++)
    {
        row = rand()%MAXROWS;
        column = rand() % MAXCOLS;
        if(Grid[row][column] == NULL)
            Grid[row][column] = new predator(row, column);
        else
            i--;
    }


    //(.25*MAXROWS*MAXROWS)
    //insert prey
    for(int i=0;i<(.25*MAXROWS*MAXCOLS);i++)
    {
        row = rand() % MAXROWS;
        column = rand() % MAXCOLS;
        if(Grid[row][column] == NULL)
            Grid[row][column] = new prey(row, column);
        else
            i--;
    }




}


void grid::Move()
{
    //cout << "moving\n";
    //move/eat
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            //cout<<"test\n";
            if(Grid[i][j] != NULL && !Grid[i][j]->HasMoved())
            {
                    Grid[i][j]->Move(this);
            }
        }
    //cout << "finished moving\n";

//    dd
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                Grid[i][j]->Breed(this);
            }
        }

//    die
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                    Grid[i][j]->Starve(this);
            }
        }

//    //set flag
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                Grid[i][j]->ResetMove();
            }
        }

}

void grid::CreatureCount()
{
    int predators=0, prey=0;
    {
        for(int i=0; i<MAXROWS; i++)
            for(int j=0; j<MAXCOLS; j++)
            {
                if(Grid[i][j] != NULL)
                {
                    if(Grid[i][j]->getSpecies() == 'X')
                        predators++;
                    if(Grid[i][j]->getSpecies() == 'O')
                        prey++;
                }
            }
    }
    if(predators == 0)
    {
        cout << "no more predators\n";
        cin.get();
    }


    cout << "There are " << predators << " predators in the grid.\n";
    cout << "There are " << prey << " prey in the grid.\n";
}

ostream &operator <<(ostream &out, const grid &a)
{

    for(int i=0; i<MAXROWS; i++)
    {


        for(int j=0; j<MAXCOLS; j++)
        {
            if(a.Grid[i][j] != NULL)
                out << *a.Grid[i][j];
            else
                out << " - ";

        }
        out << endl;
    }

    return out;
}
