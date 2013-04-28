/*-----------------------------------------------------------------------------------------
Project: 10-9 Mom Counter
Author: Jonathan Chan
Description: Increments by 1, 10, 100, 1000
Notes: 2/6 farily easy.
-----------------------------------------------------------------------------------------*/
#include <iostream>
#include "counter.h"
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    Counter MomCounter;
    char choice;

    cout<<setw(4)<<setfill('0') << endl <<MomCounter.GetCount() << endl << endl;

    cin>>choice;

    choice=toupper(choice);


    while(choice!='X')
    {
        switch(choice)
        {

            case 'F':
                if(MomCounter.GetCount()+1<=MomCounter.GetMax())
                {
                MomCounter.Incr1();
                }
                else
                {
                    cout << "\n|OVERFLOW|\n";
                }

                break;

            case 'D':
                if(MomCounter.GetCount()+10<=MomCounter.GetMax())
                {
                    MomCounter.Incr10();
                }
                else
                {
                    cout << "\n|OVERFLOW|\n";
                }
                break;

            case 'S':
                if(MomCounter.GetCount()+100<=MomCounter.GetMax())
                {
                    MomCounter.Incr100();
                }
                else
                {
                    cout << "\n|OVERFLOW|\n";
                }
                break;

            case 'A':
                if(MomCounter.GetCount()+1000<=MomCounter.GetMax())
                {
                    MomCounter.Incr1000();
                }
                else
                {
                    cout << "\n|OVERFLOW|\n";
                }
                break;


            case 'R':
                MomCounter.Reset();
                break;


        }
        cout<<setw(4)<<setfill('0') << endl <<MomCounter.GetCount() << endl;
        cout<<"\n:" ;
        cin>>choice;


        choice = toupper(choice);
    }

    
    return 0;
}
