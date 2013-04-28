#include "maze.h"
#include <cstdlib>
#include <iostream>

using namespace std;


maze::maze()//default constructor
{
    node* A = new node;
    node* B = new node;
    node* C = new node;
    node* D = new node;
    node* E = new node;
    node* F = new node;
    node* G = new node;
    node* H = new node;
    node* I = new node;
    node* J = new node;
    node* K = new node;
    node* L = new node;


    A->room = 'A';
    A->south = E;
    A->east = B;

    B->room = 'B';
    B->south = F;
    B->west = A;

    C->room = 'C';
    C->south = G;
    C->east = D;

    D->room = 'D';
    D->west = C;

    E->room = 'E';
    E->north = A;
    E->south = I;

    F->room = 'F';
    F->north = B;
    F->east = G;

    G->room = 'G';
    G->north = C;
    G->south = K;
    G->east = H;
    G->west = L;

    H->room = 'H';
    H->south = L;
    H->west = G;

    I->room = 'I';
    I->north = E;
    I->east = J;

    J->room = 'J';
    J->west = I;

    K->room = 'K';
    K->north = G;

    L->room = 'L';
    L->north = H;

    location = A;
    head=NULL;
}

/*******************
  Name: Move
  Arguments: character
  Returns none void function
  Description: moves around the maze
  Notes: not too bad
  *******************/
void maze::move(char ch)
{

    if(validMove(toupper(ch)))
    {
        switch(toupper(ch))
        {
        case 'N':
            location = location->north;
            break;
        case 'S':
            location = location->south;
            break;
        case 'E':
            location = location->east;
            break;
        case 'W':
            location = location->west;
            break;
        case 'Q':
            cout << "Quitter!";
            break;
        default:
            cout << "What are you trying to do???\n";
        }
    }





}

/*******************
  Name: options
  Arguments: none
  Returns none void function
  Description: outputs the options
  Notes: not too bad
  *******************/
void maze::options()
{
    if(location->room == 'L')
    {
        cout << "You have reached the end of the maze!\n";
        exit(1);
    }
    cout << "You are in room " << *location << " of a maze of twisty little passages, all alike.\n";
    cout << "You can go ";

    if(location->north != NULL)
        cout << "(N)orth ";
    if(location->south != NULL)
        cout << "(S)outh ";
    if(location->east != NULL)
        cout << "(E)ast ";
    if(location->west != NULL)
        cout << "(W)est ";

    cout << "or you can (Q)uit\n";
}

/*******************
  Name: validMove
  Arguments: char ch
  Returns bool
  Description: if vlaid return true, otherwise false
  Notes: not too bad
  *******************/
bool maze::validMove(char ch)
{
    if(ch=='N' && location->north == NULL)
    {
        cout << "You fell into a bottomless pit, lets retry that\n";
        return false;
    }
    else if(ch=='S' && location->south == NULL)
    {
        cout << "You fell into a bottomless pit, lets retry that\n";
        return false;
    }
    else if(ch=='E' && location->east == NULL)
    {
        cout << "You fell into a bottomless pit, lets retry that\n";
        return false;
    }
    else if(ch=='W' && location->west == NULL)
    {
        cout << "You fell into a bottomless pit, lets retry that\n";
        return false;
    }

    return true;

}



