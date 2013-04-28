#ifndef GRID_H
#define GRID_H

#include <cstdlib>
#include <iostream>
#include "creature.h"
#include "predator.h"
#include "prey.h"
#include "wall.h"
#include "hunter.h"
#include "display.h"

using namespace std;

int const MAXCOLS = 200;
int const MAXROWS = 200;

//static bool hunters = true;


class creature;
class grid
{

public:
    grid();
    void Populate();
    void Move();
    void Stats();


    friend ostream &operator <<(ostream& out, const grid& a);//outputs the list

    creature* Grid[MAXROWS][MAXCOLS];
};

#endif // GRID_H
