#include "wall.h"
#include "grid.h"

wall::wall()
{}

wall::wall(int x, int y)
{
    face = 'W';
    row = x;
    col = y;

}


wall::~wall()
{
}

void wall::Move(grid *g)
{
}

void wall::Breed(grid *g)
{
}

void wall::Starve(grid *g)
{
}


