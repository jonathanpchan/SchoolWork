//#include <windows.h>
#include "display.h"
#include "grid.h"


#define walls


int display::cycleCount = 0;

bool display::paused = 0;
bool display::found = 0;
int display::creatureCol = 0;
int display::creatureRow = 0;
int display::WAIT = 0;





const int window_width = 1280;
const int window_height = 720;
const float scale = 1.0f;
bool wantstats = 0;

//float rotate_y = 0,
//      rotate_z = 0;
//const float rotations_per_tick = .2;
//const float aspect_ratio = ((float)window_height) / window_width;
//static double old_time;
//static double current_time, delta_rotate;




display::display(){}

void GLFWCALL mousepos(int x, int y)
{
    //Convert mouse coords to opengl coords
    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

    gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    display::creatureRow = (int)posX;
    display::creatureCol = (int)posY;
    display::found = 1;

}
void  GLFWCALL MouseHandler(int button, int state)
{
  int x, y;
  switch (button)
  {
      case GLFW_MOUSE_BUTTON_LEFT:
           if (state==GLFW_RELEASE){
           glfwGetMousePos(&x, &y);
           mousepos(x, y);}
           break;
      case GLFW_MOUSE_BUTTON_RIGHT:
           if (state==GLFW_RELEASE)
           {
               if(!display::paused)
                display::paused = 1;
               else
                display::paused = 0;
           }
           break;
      default:
           break;
  }
}

//Called when a key is pressed
void GLFWCALL handleKeypress(int key,int press) //The key that was pressed
{
    switch (key)
    {
        case GLFW_KEY_ESC:
            exit(0);
            break;
        case GLFW_KEY_UP:
             if(glfwGetKey(key) == GLFW_PRESS)
                display::WAIT += 50;
             break;
        case GLFW_KEY_DOWN:
             if(glfwGetKey(key) == GLFW_PRESS)
             {
                 if((display::WAIT-50)<=0)
                 {
                     display::WAIT=0;
                 }
                 else
                 {
                     display::WAIT -= 50;
                 }
             }
             break;
        case GLFW_KEY_KP_1:
             if(glfwGetKey(key) == GLFW_PRESS)
                wantstats = 1;
            break;
        case GLFW_KEY_KP_2:
            if(glfwGetKey(key) == GLFW_PRESS)
                cout << "There have been " << display::cycleCount <<  " cycles\n\n\n";
            break;
        case GLFW_KEY_KP_9:
            if(glfwGetKey(key) == GLFW_PRESS)
                system("cls");
            break;
//        case GLFW_KEY_LEFT:
//            if(glfwGetKey(key) == GLFW_PRESS)
//            {
//                rotate_y += delta_rotate;
//                rotate_z += delta_rotate;
//            }
//            break;
//        case GLFW_KEY_RIGHT:
//            if(glfwGetKey(key) == GLFW_PRESS)
//            {
//                rotate_y -= delta_rotate;
//                rotate_z += delta_rotate;
//            }
//            break;



    }
}

void GLFWCALL handleResize(int width,int height)
{
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport( 0, 0, width, height );
    gluOrtho2D(0, width, height, 0);//left, right, bottom, top


    glMatrixMode( GL_PROJECTION ); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //reset the camera
/*    gluPerspective( 45.0f,                      //camera angle
                (GLfloat)width/(GLfloat)height, //The width to height ratio
                 1.0f,                          //The near z clipping coordinate
                100.0f ); */                      //The far z clipping coordinate
}

void draw(grid* g)
{
    glClearColor( 1.0f, 1.0f, 1.0f, 0.0f ); //clear background screen to black

    //Clear information from last draw
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    //glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 50);

    gluOrtho2D(0, MAXROWS, MAXCOLS, 0);//left, right, bottom, top
    //glTranslatef(0, 0, -30);

    //glPushMatrix();
    //glTranslatef(0.0,0.0,-5.0f);
    //glTranslatef(0, 0, -30);
    // apply the current rotation
//    glRotatef(rotate_y, 0, 1, 0);
//    glRotatef(rotate_z, 0, 0, 1);

    for(int i=0;i<MAXROWS;i++)
        for(int j=0;j<MAXCOLS;j++)
        {
            char species = ' ';
            if(g->Grid[i][j] != NULL)
                species = g->Grid[i][j]->getSpecies();

            if(species == 'O')
            {
                glBegin(GL_QUADS);
                glColor3f(0.0f/255.0f, 0.0f/255.0f, 255.0f/255.0f);
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (scale + i, 0.0f + j);
                glVertex2f (scale + i, scale + j);
                glVertex2f (0.0f + i, scale + j);
                glEnd();

            }
            else if(species == 'X')
            {
                glBegin(GL_QUADS);
                glColor3f(255.0f/255.0f, 255.0f/255.0f, 0.0f/255.0f);
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (scale + i, 0.0f + j);
                glVertex2f (scale + i, scale + j);
                glVertex2f (0.0f + i, scale + j);
                glEnd();
            }
            else if(species == 'H')
            {
                glBegin(GL_QUADS);
                glColor3f(255.0f/255.0f, 0.0f/255.0f, 0.0f/255.0f);
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (scale + i, 0.0f + j);
                glVertex2f (scale + i, scale + j);
                glVertex2f (0.0f + i, scale + j);
                glEnd();
            }

            else
            {
                glBegin(GL_QUADS);
                glColor3f(0.0f, 0.0f, 0.0f);//black
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (scale + i, 0.0f + j);
                glVertex2f (scale + i, scale + j);
                glVertex2f (0.0f + i, scale + j);
                glEnd();
            }
        }
    glfwSwapBuffers();
}

void display::show(grid *g)
{
    bool running = true;
    glfwInit(); //initialize rendering

    if(!glfwOpenWindow(window_width, window_height, 1, 0, 0, 0, 0, 0, GLFW_WINDOW)) //returns false if window is not created
    {
        glfwTerminate(); //terminating glfw window
    }

    glfwSetWindowTitle("Predator vs Prey - Jon Chan");
    glfwSetKeyCallback(handleKeypress); //callback function to handle keypress
    glfwSetMouseButtonCallback(MouseHandler);
    glfwSetWindowSizeCallback(handleResize); //callback function of GLFW to handle window resize

//    old_time = glfwGetTime();



    //int i=0;
    while(running)
    {

//        current_time = glfwGetTime();
//        delta_rotate = (current_time - old_time) * rotations_per_tick * 360;
//        old_time = current_time;

        if(!paused)
        {
        g->Move();
        cycleCount++;
        }
        draw(g);

        if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS)
        {
            cout << "Hi\n";
        }


        glfwSleep(WAIT/1000.0);
        //cin.get();
        if(found==1)
        {
            if(g->Grid[creatureRow][creatureCol] != NULL)
            {
                g->Grid[creatureRow][creatureCol]->DisplayInfo();
                //Sleep(5000);
            }
            else
            {
                cout << "No creature in that location (" << creatureCol << ", " << creatureRow <<")\n\n\n";
            }

            if(paused)
            {
                glBegin(GL_QUADS);
                glColor3f(0.0f/255.0f, 255.0f/255.0f, 127.0f/255.0f);
                //square
                glVertex2f (0.0f + creatureRow, 0.0f + creatureCol);
                glVertex2f (scale + creatureRow, 0.0f + creatureCol);
                glVertex2f (scale + creatureRow, scale + creatureCol);
                glVertex2f (0.0f + creatureRow, scale + creatureCol);
                glEnd();
                glfwSwapBuffers();
                glfwSleep(2);
            }
            found =0;
        }
        if(wantstats==1)
        {
            g->Stats();
            wantstats=0;
        }



        running = glfwGetWindowParam( GLFW_OPENED ); //when glfw window is opened then it return true if closed then return false

    }
}
