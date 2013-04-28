#ifndef PREDATOR_H
#define PREDATOR_H

#include "creature.h"
#include "coords.h"

class grid;

class predator:public creature
{
    public:
        predator();
        predator(int x, int y);
        void Move(grid* g);
        void Breed(grid* g);
        void Starve(grid* g);

        bool HasMoved();

        coords AvailablePrey(grid* g);


};

#endif // PREDATOR_H
