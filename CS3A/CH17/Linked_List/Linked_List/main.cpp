#include <iostream>
#include <cctype>
#include "node.cpp"
#include "linkedlist.cpp"
#include "iterator.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "polynomial.cpp"
using namespace std;

void TestStack();
void TestList();
void TestQueue();
void testpoly();
int main()
{
//    cout << "HUEUEUEUE\n";
//    TestList();
    //TestStack();
    //TestQueue();
    //testpoly();

    return 0;
}

void TestList()
{
    LinkedList<int> list1;//, list2, list3, list4;
    Node<int>* thing;//, *thing2, *thing3, *debug;
    int num;
    char ch;

    cout<<"a: Append, o: InsertSorted, b: InsertBefore, f: InsertAfter, h: InsertHead"<<endl;
    cout<<"n: Next, p: Previous, r: Remove, s: Search, t: Sort, d: DestroyAllNodes"<<endl;

    cin>>ch;

    while(toupper(ch)!='X')
    {
        switch(toupper(ch))
        {
        case 'A':
            try
            {
                cin>>num;
                if(!cin)
                    throw -1;

                thing = new Node<int>(num);
                list1.Append(thing);
                cout<<list1<<endl;
            }
            catch(int e)
            {
                cout<<"Invalid input."<<endl;
                cin.clear();
                cin.sync();
                //cin >> ch;
            }
            break;
        case 'O':
            cin>>num;
            thing = new Node<int>(num);
            list1.Sort();
            list1.InsertSorted(thing);
            cout<<list1<<endl;
            break;
        case 'B':
            cin>>num;
            thing = new Node<int>(num);
            list1.InsertBefore(thing, list1.GetNode());
            cout<<list1<<endl;
            break;
        case 'F':
            cin>>num;
            thing = new Node<int>(num);
            list1.InsertAfter(thing, list1.GetNode());
            cout<<list1<<endl;
            break;
        case 'H':
            cin>>num;
            thing = new Node<int>(num);
            list1.InsertHead(thing);
            cout<<list1<<endl;
            break;
        case 'N':
            list1.Next();
            cout<<list1<<endl;
            break;
        case 'P':
            list1.Previous();
            cout<<list1<<endl;
            break;
        case 'R':
            list1.Remove();
            cout<<list1<<endl;
            break;
        case 'D':
            list1.DestroyAllNodes();
            cout<<list1<<endl;
            break;
        case 'S':
            cin>>num;
            thing = new Node<int>(num);
            if(list1.Search(thing).GetNode()!=NULL)
                cout<<"Found: "<<(list1.Search(thing))<<endl;
            else
                cout<<"Not found."<<endl;
            cout<<list1<<endl;
            break;
        case 'T':
            list1.Sort();
            cout<<list1<<endl;
            break;
        default:
            cout << "INPUT UNRECOGNIZED ENTER AGAIN\n"<<endl;
        }
        cin >> ch;
    }
}



void TestStack()
{
    stack<int> list1;
    Node<int>* thing;
    int num;
    char ch;

    cout << "p: push, o: pop\n";

    cin>>ch;
    while(toupper(ch)!='X')
    {
        switch(toupper(ch))
        {
        case 'P':
            cin>>num;
            thing = new Node<int>(num);
            list1.Push(thing);
            cout<<list1<<endl;
            break;
        case 'O':
            list1.Pop();
            cout<<list1<<endl;
            break;
        default:
            cout << "INPUT UNRECOGNIZED ENTER AGAIN\n"<<endl;
        }
        cin >> ch;
    }
}
void TestQueue()
{
    queue<int> list1;
    Node<int>* thing;
    int num;
    char ch;

    cout << "e: EnQueue, D: DeQueue\n";

    cin>>ch;
    while(toupper(ch)!='X')
    {
        switch(toupper(ch))
        {
        case 'E':
            cin>>num;
            thing = new Node<int>(num);
            list1.Enqueue(thing);
            cout<<list1<<endl;
            break;
        case 'D':
            list1.Dequeue();
            cout<<list1<<endl;
            break;
        default:
            cout << "INPUT UNRECOGNIZED ENTER AGAIN\n"<<endl;
        }
        cin >> ch;
    }
}
void testpoly()
{
   polynomial list1, list2, list3;
   polyterm poly1, poly2, poly3, poly4, poly5;
   Node<polyterm> *t1,*t2,*t3,*t4,*t5;

   poly1 = polyterm(7,11);
   poly2 = polyterm(4,5);
   poly3 = polyterm(15,4);
   poly4 = polyterm(-5,3);
   poly5 = polyterm(3,2);


   t1 = new Node<polyterm>(poly1);
   t2 = new Node<polyterm>(poly2);
   t3 = new Node<polyterm>(poly3);
   t4 = new Node<polyterm>(poly4);
   t5 = new Node<polyterm>(poly5);

   list1.Append(t1);
   list1.Append(t2);
   list1.Append(t3);
   list1.Append(t4);
   list1.Append(t5);

   poly1 = polyterm(12,3);
   poly2 = polyterm(5,5);
   poly3 = polyterm(9,11);
   poly4 = polyterm(-33,7);
   poly5 = polyterm(1,6);

   t1 = new Node<polyterm>(poly3);
   t2 = new Node<polyterm>(poly4);
   t3 = new Node<polyterm>(poly5);
   t4 = new Node<polyterm>(poly2);
   t5 = new Node<polyterm>(poly1);

   list2.Append(t1);
   list2.Append(t2);
   list2.Append(t3);
   list2.Append(t4);



//   cout << "list 1 :: " << list1 << endl;
//   cout << "list 2 :: " << list2 << endl;
//   cout << "negative list 2 :: " << -list2 << endl << endl << endl;




//   list3 = list1+list2;
//   cout << "list3 = " << list3 << endl << endl << endl;

//   list3 = list1-list2;
//   cout << "list3 = " << list3 << endl;


//   list3 = list1*list2;
//   cout << "list3 = " << list3 << endl;

}


