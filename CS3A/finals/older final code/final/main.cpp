//move functions incomplete;

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
//    cin.get();


    test.show(g);

//    int i=0;
//    while(running)
//    {
////        if(i%100==0)
////            cin.get();

//        //Sleep(200);
//        //usleep(100*1000);
//        g->Move();
//        g->Breed();
//        g->Die();
//        system("cls");
//        i++;
//        cout << "lap #" << i << endl;
//        cout<<*g<<endl;
//        g->CreatureCount();
//        g->ResetGrid();//sets moved flags to false
//        //cin.get();


////          test.show(g);






//    }

}






