#include "grid.h"




grid::grid()
{
    //cout << "making grid\n";
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
            Grid[i][j] = NULL;

}

void grid::Populate()
{
    int row, column;

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


    for(int i=0;i<(.005*MAXROWS*MAXCOLS);i++)
    {
        row = rand() % MAXROWS;
        column = rand() % MAXCOLS;
        if(Grid[row][column] == NULL)
            Grid[row][column] = new hunter(row, column);
        else
            i--;
    }

    for(int i=0;i<(.05*MAXROWS*MAXCOLS);i++)
    {
        row = rand() % MAXROWS;
        column = rand() % MAXCOLS;
        if(Grid[row][column] == NULL)
            Grid[row][column] = new wall(row, column);
        else
            i--;
    }

}

void grid::Move()
{
    //move/eat
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL && !Grid[i][j]->HasMoved())
            {
                    Grid[i][j]->Move(this);
            }
        }

    //breed
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                Grid[i][j]->Breed(this);
            }
        }

    //die
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                    Grid[i][j]->Starve(this);
            }
        }

    //set flag
    for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                Grid[i][j]->ResetMove();
            }
        }
}

void grid::Stats()
{
    int maxHunterKills=0, maxHunterLife=0, maxHunterBreed=0;
    coords hunterKills, hunterLife, hunterBreed;
    int maxPredatorKills=0, maxPredatorLife=0, maxPredatorBreed=0;
    coords predatorKills, predatorLife, predatorBreed;
    int maxPreyLife=0, maxPreyBreed=0;
    coords preyLife, preyBreed;

    for(int i=0; i<MAXROWS; i++)
    {
        for(int j=0; j<MAXCOLS; j++)
        {
            if(Grid[i][j] != NULL)
            {
                if(Grid[i][j]->getSpecies() == 'H')
                {
                    if(Grid[i][j]->GetKillCount() > maxHunterKills)
                    {
                        maxHunterKills = Grid[i][j]->GetKillCount();
                        hunterKills = coords(i,j);
                    }

                    if(Grid[i][j]->GetAliveCount() > maxHunterLife)
                    {
                        maxHunterLife = Grid[i][j]->GetAliveCount();
                        hunterLife = coords(i,j);
                    }

                    if(Grid[i][j]->GetBabyCount() > maxHunterBreed)
                    {
                        maxHunterBreed = Grid[i][j]->GetBabyCount();
                        hunterBreed = coords(i,j);
                    }
                }
                else if(Grid[i][j]->getSpecies() == 'X')
                {
                    if(Grid[i][j]->GetKillCount() > maxPredatorKills)
                    {
                        maxPredatorKills = Grid[i][j]->GetKillCount();
                        predatorKills = coords(i,j);
                    }

                    if(Grid[i][j]->GetAliveCount() > maxPredatorLife)
                    {
                        maxPredatorLife = Grid[i][j]->GetAliveCount();
                        predatorLife = coords(i,j);
                    }

                    if(Grid[i][j]->GetBabyCount() > maxPredatorBreed)
                    {
                        maxPredatorBreed = Grid[i][j]->GetBabyCount();
                        predatorBreed = coords(i,j);
                    }
                }
                else if(Grid[i][j]->getSpecies() == 'O')
                {

                    if(Grid[i][j]->GetAliveCount() > maxPreyLife)
                    {
                        maxPreyLife = Grid[i][j]->GetAliveCount();
                        preyLife = coords(i,j);
                    }

                    if(Grid[i][j]->GetBabyCount() > maxPreyBreed)
                    {
                       maxPreyBreed = Grid[i][j]->GetBabyCount();
                       preyBreed  = coords(i,j);
                    }
                }
            }


        }

    }

    predator p;
    prey e;
    hunter h;
    cout << "----------------Hunter Stats----------------------\n";
    cout << "There are " << h.GetHunterCount()-1 << " hunters in the grid\n";
    cout << "The Hunter at (" << hunterKills.GetCol() << ", " << hunterKills.GetRow() << ") has the Most Kills with " << maxHunterKills << " kills\n";
    cout << "The Hunter at (" << hunterBreed.GetCol() << ", " << hunterBreed.GetRow() << ") has the Most Babies " << maxHunterBreed << " babies\n";
    cout << "The Hunter at (" << hunterLife.GetCol() << ", " << hunterLife.GetRow() << ") has the lived the longest at " << maxHunterLife<< " cycles\n\n\n";

    cout << "----------------Predator Stats--------------------\n";
    cout << "There are " << (p.getPredatorCount()-1) << " predators in the grid\n";
    cout << "The Predator at (" << predatorKills.GetCol() << ", " << predatorKills.GetRow() << ") has the Most Kills with " << maxPredatorKills << " kills\n";
    cout << "The Predator at (" << predatorBreed.GetCol() << ", " << predatorBreed.GetRow() << ") has the Most Babies " << maxPredatorBreed << " babies\n";
    cout << "The Predator at (" << predatorLife.GetCol() << ", " << predatorLife.GetRow() << ") has the lived the longest at " << maxPredatorLife << " cycles\n\n\n";

    cout << "----------------Prey Stats------------------------\n";
    cout << "There are " << e.getPreyCount()-1 << " prey in the grid\n";
    cout << "The Prey at (" << preyBreed.GetCol() << ", " << preyBreed.GetRow() << ") has the Most Babies " << maxPreyBreed << " babies\n";
    cout << "The Prey at (" << preyLife.GetCol() << ", " << preyLife.GetRow() << ") has the lived the longest at " << maxPreyLife << " cycles\n\n";
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
