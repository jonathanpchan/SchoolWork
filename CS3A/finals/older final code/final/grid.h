#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <iostream>
#include "creature.h"
#include "predator.h"
#include "prey.h"

int const MAX = 750;
using namespace std;

class creature;
class grid
{

public:
    grid();
    void Populate();
    void Move();
    void Breed();
    void Die();
    void ResetGrid();
    void CreatureCount();

    friend ostream &operator <<(ostream& out, const grid& a);//outputs the list




    creature* Grid[MAX][MAX];
private:



};

#endif // GRID_H
