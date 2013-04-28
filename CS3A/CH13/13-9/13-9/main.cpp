#include <iostream>
#include "maze.h"
using namespace std;

int main()
{
    maze m;
    char ch;
    m.options();
    cin>> ch;
    cout << endl << endl;
    while (toupper(ch) != 'Q')
    {

        m.move(ch);
        m.options();

        cin >> ch;
        cout << endl << endl;
    }
}
/***************************
You are in room A of a maze of twisty little passages, all alike.
You can go (S)outh (E)ast or you can (Q)uit
e


You are in room B of a maze of twisty little passages, all alike.
You can go (S)outh (W)est or you can (Q)uit
n


You fell into a bottomless pit, lets retry that
You are in room B of a maze of twisty little passages, all alike.
You can go (S)outh (W)est or you can (Q)uit
s


You are in room F of a maze of twisty little passages, all alike.
You can go (N)orth (E)ast or you can (Q)uit
e


You are in room G of a maze of twisty little passages, all alike.
You can go (N)orth (S)outh (E)ast (W)est or you can (Q)uit
e


You are in room H of a maze of twisty little passages, all alike.
You can go (S)outh (W)est or you can (Q)uit
s


You have reached the end of the maze!
Press <RETURN> to close this window...
********************************************************************/

