#include <iostream>
#include <time.h>
#include <Windows.h>
#include "creature.h"
#include "predator.h"
#include "prey.h"
#include "grid.h"
#include "display.h"


int main()
{
    srand(time(NULL));

    bool running = true;
    grid* g = new grid;
    display test;

    g->Populate();
//    cout << "INITIAL GRID\n";
//    cout << *g << endl;
//    cout << "END INITIAL GRID\n";
    cin.get();

    test.show(g);

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

}









