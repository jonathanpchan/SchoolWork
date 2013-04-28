#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include "coords.h"
using namespace std;

class grid;
class creature
{
    public:
        creature();
        creature(int x, int y);
        virtual ~creature();
        virtual void Move(grid* g) = 0;
        virtual void Breed(grid* g) = 0;
        virtual void Starve(grid* g) = 0;

        bool HasMoved();
        void SetMoved();
        void ResetMove();

        void DisplayInfo();

        char getSpecies();
        void SetSpecies(char s);

        int Row();
        int Col();
        void SetRow(int ROW);
        void SetCol(int COL);

        coords AvailablePoints(grid* g);
        coords AvailableFood(grid *g, char f);

        friend ostream &operator <<(ostream& out, const creature& a);//outputs the list


        int GetKillCount();
        int GetBabyCount();
        int GetAliveCount();




    protected:

        int row;
        int col;
        int hungerCount;
        int breedCount;
        int noBabyCount;
        int killCount;
        int babyCount;
        int aliveCount;
        bool moved;
        char face;


    private:







};

#endif // CREATURE_H
