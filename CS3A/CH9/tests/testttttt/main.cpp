#include <iostream>

using namespace std;
int main()
{

    char** twoD= new char*[2];
    char** rowWalker;
    char* seatWalker = *rowWalker;



    rowWalker = twoD;

    for(int i=0; i<2; i++)
    {
        *rowWalker++ = new char[2];
    }
    rowWalker = twoD;


    *rowWalker = "12";
    cout << *rowWalker << endl;

    rowWalker++;


    *rowWalker = "34";
    cout << *rowWalker << endl;

    rowWalker = twoD;

    seatWalker = *rowWalker;


    cout << "*seatWalker = " << *seatWalker << endl;

    seatWalker++;

    cout << "*seatWalker = " << *seatWalker << endl;

    rowWalker++;

    seatWalker = *rowWalker;

    cout << "*seatWalker = " << *seatWalker << endl;

    seatWalker++;

    cout << "*seatWalker = " << *seatWalker << endl;








    return 0;
}
