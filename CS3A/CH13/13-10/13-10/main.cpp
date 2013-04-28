

#include <iostream>
#include "rpn.h"
#include "node.h"
#include <cstdlib>

int main()
{

       rpn polish;
       node* num1 = new node(10);
       node* num2 = new node(2);
       node* num3 = new node(3);
       node* num4 = new node(2);
       node* num5 = new node(5);


       polish.Push(num1);
       polish.Push(num2);
       polish.Push(num3);
       polish.calculate('+');
       polish.calculate('-');
       polish.Push(num4);
       polish.calculate('*');
       polish.Push(num5);
       polish.calculate('/');


       polish.calculate('Q');

       exit(1);

       return 0;


}
/********************************
Error: Stack still has too many items
Press <RETURN> to close this window...


not enough operands
Press <RETURN> to close this window...

The the top of the stack is 2
Press <RETURN> to close this window...


**************************************/
