#include <iostream>
#include <time.h>
//#include <Windows.h>
#include "creature.h"
#include "predator.h"
#include "prey.h"
#include "grid.h"
#include "display.h"
#include "wall.h"
#include "hunter.h"


int main()
{
    srand(time(NULL));

    grid* g = new grid;
    display test;

    g->Populate();
    cout << "Press Enter To Create Grid\n";
    cin.get();

    test.show(g);
}

//        int i=0;
//        while(running)
//        {
//    //        if(i%100==0)
//    //            cin.get();

//            Sleep(200);
//            //usleep(100*1000);
//            g->Move();
//            system("cls");
//            i++;
//            cout << "Cycle #" << i << endl;
//            cout<<*g<<endl;


            //cin.get();
//        }










