#include "grid.h"


grid::grid()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            Grid[i][j] = NULL;
}

void grid::Populate()
{
    int row, column;

    //insert predators
    for(int i=0;i<(.0125*MAX*MAX);i++)
    {
        row = rand()%MAX;
        column = rand()%MAX;
        if(Grid[row][column] == NULL)
            Grid[row][column] = new predator(row, column);
        else
            i--;
    }

    //insert prey
    for(int i=0;i<(.25*MAX*MAX);i++)
    {
        row = rand()%MAX;
        column = rand()%MAX;
        if(Grid[row][column] == NULL)
            Grid[row][column] = new prey(row, column);
        else
            i--;
    }


}


void grid::Move()
{
//    creature* temp[400];
//    int count = 0;

    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
        {
            if(Grid[i][j] != NULL && !Grid[i][j]->HasMoved())
            {
                    Grid[i][j]->Move(this);
            }
        }
//    //cout << "Before Move (" << temp[0]->row << ", " << temp[0]->col << ")\n";
//    for(int i=0; i<count; i++)
//    {
//        temp[i]->Move(this);//somehow overwriting creatures??????
//    }
    //    //cout << "After Move (" << temp[0]->row << ", " << temp[0]->col << ")\n";
}

void grid::Breed()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
        {
            if(Grid[i][j] != NULL)
            {
                Grid[i][j]->Breed(this);
            }
        }

}

void grid::Die()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
        {
            if(Grid[i][j] != NULL)
            {

                    Grid[i][j]->Starve(this);

            }
        }
}

void grid::ResetGrid()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
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
        for(int i=0; i<MAX; i++)
            for(int j=0; j<MAX; j++)
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
    cout << "     00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19\n\n";

    for(int i=0; i<MAX; i++)
    {
        if(i>MAX/2)
            cout << i << "   ";
        else
            cout << "0" << i << "   ";

        for(int j=0; j<MAX; j++)
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
