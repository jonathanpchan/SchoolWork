#ifndef PREY_H
#define PREY_H
#include "creature.h"

class grid;

class prey:public creature
{
    public:
        prey();
        prey(int x, int y);
        void Move(grid* g);
        void Breed(grid* g);
        void Starve(grid* g);

        bool HasMoved();
};

#endif // PREY_H
