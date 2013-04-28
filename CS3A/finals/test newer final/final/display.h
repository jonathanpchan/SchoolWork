#ifndef DISPLAY_H
#define DISPLAY_H
#include <GL/glfw.h>
#include "coords.h"

using namespace std;

class grid;
class display
{
public:
   display();
   void show(grid *g);

   void GLFWCALL mousepos(int x, int y);

   static int creatureRow;
   static int creatureCol;
   static bool found;
   static bool paused;

   static int cycleCount;
   static int WAIT;





private:

};

#endif // DISPLAY_H
