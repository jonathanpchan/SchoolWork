#include <iostream>
#include "queue.h"
#include "node.h"

int main()
{
    queue q;
    node* n;
    int num, i=1;
    long time;
    long averageWait;

    cout << "Enter 1 to enter queue, 2 to be helped, 3 to exit\n";
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
                averageWait = q.AverageTime(time-q.getTime());
                cout << "Average Wait Time is " << averageWait << " seconds\n";
                q.Dequeue();
            }
            else
            {
                cout << "Nobody else in the line\n";
            }

            break;
        default:
            cout << "what exactly are you trying to do?\n";
        }
    cin >> num;
    }


    return 0;
}
/**************************
Enter 1 to enter queue, 2 to be helped, 3 to exit
1
Customer 1 entered the queue at time 1364856199
1
Customer 2 entered the queue at time 1364856210
1
Customer 3 entered the queue at time 1364856215
2
Customer 1 is being helped at 1364856216. Wait time = 17 seconds
Average Wait Time is 17 seconds
1
Customer 4 entered the queue at time 1364856230
2
Customer 2 is being helped at 1364856232. Wait time = 22 seconds
Average Wait Time is 19 seconds
1
Customer 5 entered the queue at time 1364856239
2
Customer 3 is being helped at 1364856242. Wait time = 27 seconds
Average Wait Time is 22 seconds
2
Customer 4 is being helped at 1364856247. Wait time = 17 seconds
Average Wait Time is 22 seconds
2
Customer 5 is being helped at 1364856248. Wait time = 9 seconds
Average Wait Time is 17 seconds
2
Nobody else in the line
3
Press <RETURN> to close this window...
****************************************/
