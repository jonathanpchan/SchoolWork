#ifndef DISPLAY_H
#define DISPLAY_H
#include <GL/glfw.h>
//#include <Windows.h>

using namespace std;

class grid;

class display
{
public:
   display();
   void show(grid *g);
};

#endif // DISPLAY_H
