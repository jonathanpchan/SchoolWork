#ifndef MAZE_H
#define MAZE_H
#include "node.h"

class maze
{
public:
    maze();

    void move(char ch);//moves
    void options();//options
    bool validMove(char ch);//valid move
    node* head;
    node* location;

};

#endif // MAZE_H
