#ifndef HUNTER_H
#define HUNTER_H
#include "creature.h"
#include "coords.h"

class grid;
class hunter:public creature
{
    public:
        hunter();
        hunter(int x, int y);
        ~hunter();
        void Move(grid* g);
        void Breed(grid* g);
        void Starve(grid* g);

        int GetHunterCount();

    private:
        static int hunterCount;


};

#endif // HUNTER_H
