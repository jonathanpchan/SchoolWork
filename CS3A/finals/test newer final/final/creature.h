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
        virtual void Move(grid* g) = 0;
        virtual void Breed(grid* g) = 0;
        virtual void Starve(grid* g) = 0;
        virtual bool HasMoved();
        void SetMoved();
        void ResetMove();


        char getSpecies();

        coords AvailablePoints(grid* g);



        int Row();
        int Col();

        friend ostream &operator <<(ostream& out, const creature& a);//outputs the list




        int hungerCount;
        int breedCount;
        char face;

        int row;
        int col;
        coords location;

        bool moved;


};

#endif // CREATURE_H
