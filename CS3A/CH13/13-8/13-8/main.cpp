#include <iostream>
#include "queue.h"
#include "node.h"

int main()
{
    queue q;
    node* n;
    int num, i=1;
    long time;
    long average;


    cin >> num;
    while(num!=3)
    {
    switch(num)
    {
        case 1:

            time = q.Time();
            n = new node(i, time);
            if(q.Empty())
            {
                q.InsertHead(n);
            }
            else{

                q.Append(n);

            }
            cout <<  "Customer " << i << " entered the queue at time " << time << endl;
            i++;
            break;
        case 2:

            if(!q.Empty())
            {
                time = q.Time();
                cout << "Customer " << q.getTicket() <<  " is being helped at " << time << ". Wait time = " << time-q.getTime() << " seconds\n";
                q.Dequeue();
            }
            else
            {
                cout << "Nobody else in the line\n";
            }

            break;
        case 3:
            cout << "exit now";

        }
    cin >> num;
    }


    return 0;


}
