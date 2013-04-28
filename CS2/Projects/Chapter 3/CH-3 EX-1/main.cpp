/*

Programmer:     Jonathan Chan
Project:        Chapter 3 Excercise 1
Class:          CS2
Due:            9/23/2011
Description     This Program helps play a game of rock papers and scissors. It asks for input then compares them and outputs
                the winner.

*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    char player1;
    char player2;
    char repeat;

    do
    {
        system ("cls");
        cout << "Rock, Paper, Scissors Game v. 1\n";
        cout << "Player 1 It is now your turn.\n";
        cout << "Player 1 Please Enter R for Rock, P for Paper or S for Scissors.\n";
        cin >> player1;
        cout << "Player 2 It is now your turn.\n";
        cout << "Player 2 Please Enter R for Rock, P for Paper or S for Scissors.\n";
        cin >> player2;

        switch (player1)
        {
            case 'r':
            case 'R':
                switch (player2)
                {
                    case 's':
                    case 'S':

                        cout << "Player 1 Wins! Rock Smashes Scissors.\n";
                        break;

                case 'p':
                case 'P':

                        cout << "Player 2 Wins! Paper Covers Rock.\n";
                        break;

                case 'r':
                case 'R':

                        cout << "It's A Tie! Both players chose Rock.\n";
                        break;
                }
            break;

            case 's':
            case 'S':
                switch (player2)
                {
                    case 'p':
                    case 'P':

                        cout << "Player 1 Wins! Scissors Cuts Paper.\n";
                        break;

                    case 'r':
                    case 'R':

                        cout << "Player 2 Wins! Rock Smashes Scissors.\n";
                        break;

                    case 's':
                    case 'S':

                        cout << "It's A Tie! Both players chose Scissors.\n";
                        break;
                }
            break;

            case 'p':
            case 'P':

                switch (player2)
                {
                    case 'r':
                    case 'R':

                        cout << "Player 1 Wins! Rock Covers Paper.\n";
                        break;

                    case 's':
                    case 'S':

                        cout << "Player 2 Wins! Scissors Cuts Paper.\n";
                        break;

                    case 'p':
                    case 'P':

                        cout << "It's A Tie! Both players chose paper.\n";
                        break;
                }
            break;
        }

        cout << "Do You Wish To Play Again?\n";
        cin >> repeat;

    } while (repeat =='y' || repeat == 'Y');

    return 0;
}
/*
Rock, Paper, Scissors Game v. 1
Player 1 It is now your turn.
Player 1 Please Enter R for Rock, P for Paper or S for Scissors.
r
Player 2 It is now your turn.
Player 2 Please Enter R for Rock, P for Paper or S for Scissors.
s
Player 1 Wins! Rock Smashes Scissors.
Do You Wish To Play Again?
n

Process returned 0 (0x0)   execution time : 5.063 s
Press any key to continue.
*/

