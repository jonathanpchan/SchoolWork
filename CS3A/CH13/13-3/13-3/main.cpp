#include "node.h"
#include "polynomial.h"
#include <iostream>

using namespace std;

int main()
{
    polynomial p1, p2, p3;
    node* n1, *n2;
    n1 = new node(3, 7);
    n2 = new node(99, 6);
    p1.InsertHead(n1);
    p2.InsertHead(n2);

    n1 = new node(51,5);
    n2 = new node(3,5);
    p1.Append(n1);
    p2.Append(n2);

    n2 = new node(9,4);
    p2.Append(n2);
    n2 = new node(15,3);
    p2.Append(n2);
    n2 = new node(7,2);
    p2.Append(n2);
    n2 = new node(6,1);
    p2.Append(n2);
    n2 = new node(2);
    p2.Append(n2);

//    n1 = new node(2,1);
//    n2 = new node(10);

//    p1.InsertHead(n1);
//    p1.Append(n2);

//    n1 = new node(-1,1);
//    n2 = new node(5);
//    p2.InsertHead(n2);
//    p2.Append(n2);


    cout << p1 << "\n * \n" << p2 << "\n = \n";
    p3 = p2 * p1;
    cout << "p3 = " << p3 << endl;



//    cout << "\n\n\n\n\n";

//    cout << p1 << " - \n" << p2 << " = \n";
//    p3 = p1 - p2;
//    cout << "p3 = " << p3 << endl;




//    cout << "term 1 - " << *n << endl;
//    cout << "poly 1 - " << p << endl;
    return 0;
}
