#include <windows.h>
#include "display.h"
#include "grid.h"
//#include "creature.h"

display::display()
{

}

//Called when a key is pressed
void GLFWCALL handleKeypress(int key,int press) //The key that was pressed
{
    switch (key)
    {
        case GLFW_KEY_ESC:
            exit(0);
    }
}

void GLFWCALL handleResize(int width,int height)
{
    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION ); //Switch to setting the camera perspective
    //Set the camera perspective
    glLoadIdentity(); //reset the camera
    gluPerspective( 45.0f,                      //camera angle
                (GLfloat)width/(GLfloat)height, //The width to height ratio
                 1.0f,                          //The near z clipping coordinate
                100.0f );                       //The far z clipping coordinate
}

void draw(grid* g)
{
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f ); //clear background screen to black

    //Clear information from last draw
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(0, MAX, MAX, 0);//left, right, bottom, top

    //glPushMatrix();
    //glTranslatef(0.0,0.0,-5.0f);

    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
        {
            char species = ' ';
            if(g->Grid[i][j] != NULL)
                species = g->Grid[i][j]->getSpecies();

            if(species == 'O')
            {
                glBegin(GL_QUADS);
                glColor3f(0.0f, 0.0f, 1.0f);
                //square
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (1.0f + i, 0.0f + j);
                glVertex2f (1.0f + i, 1.0f + j);
                glVertex2f (0.0f + i, 1.0f + j);
                glEnd();
                //glfwSwapBuffers();
            }
            else if(species == 'X')
            {
                glBegin(GL_QUADS);
                glColor3f(1.0f, 0.0f, 0.0f);
                //square
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (1.0f + i, 0.0f + j);
                glVertex2f (1.0f + i, 1.0f + j);
                glVertex2f (0.0f + i, 1.0f + j);
                glEnd();
                //glfwSwapBuffers();
            }
            else
            {
                glBegin(GL_QUADS);
                glColor3f(0.0f, 0.0f, 0.0f);
                //square
                glVertex2f (0.0f + i, 0.0f + j);
                glVertex2f (1.0f + i, 0.0f + j);
                glVertex2f (1.0f + i, 1.0f + j);
                glVertex2f (0.0f + i, 1.0f + j);
                glEnd();
                //glfwSwapBuffers();
            }
            //glfwSwapBuffers();
        }
    glfwSwapBuffers();
}

void display::show(grid *g)
{
    bool running = true;
    glfwInit(); //initialize rendering

    glfwSetWindowTitle("Predator vs Prey - Dan Huynh");
    glfwSetWindowSizeCallback(handleResize); //callback function of GLFW to handle window resize
    glfwSetKeyCallback(handleKeypress); //callback function to handle keypress

    if( !glfwOpenWindow(1700, 900, 1, 0, 0, 0, 0, 0, GLFW_WINDOW)) //returns false if window is not created
    {
        glfwTerminate(); //terminating glfw window
        //return 0;
    }

    //int i=0;
    while(running)
    {



        g->Move();
        g->Breed();
        g->Die();
        g->ResetGrid();
        //Sleep(100);
        draw(g);
        //cin.get();


;
//        system("cls");
        //i++;
       //cout << "lap #" << i << endl;
//        cout<<*g<<endl;






        running = glfwGetWindowParam( GLFW_OPENED ); //when glfw window is opened then it return true                                                       //if closed then return false
    }

    //return 0;
}
