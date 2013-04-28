#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <iostream>
#include "creature.h"
#include "predator.h"
#include "prey.h"

using namespace std;

int const MAXROWS = 444;
int const MAXCOLS = 444;

class creature;
class grid
{

public:
    grid();
    void Populate();
    void Move();
//    void Breed();
//    void Die();
//    void ResetGrid();
    void CreatureCount();

    friend ostream &operator <<(ostream& out, const grid& a);//outputs the list




    creature* Grid[MAXROWS][MAXCOLS];
private:



};

#endif // GRID_H
