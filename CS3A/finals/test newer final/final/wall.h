#ifndef WALL_H
#define WALL_H
#include "creature.h"

class grid;
class wall:public creature
{
    public:
        wall();
        wall(int x, int y);
        ~wall();
        void Move(grid* g);
        void Breed(grid* g);
        void Starve(grid* g);
};

#endif // WALL_H
