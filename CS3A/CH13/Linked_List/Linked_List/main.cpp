#include <iostream>
#include <cctype>
#include "node.h"
#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList list1, list2, list3, list4;
    Node* thing, *thing2, *thing3, *debug;
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
                thing = new Node(num);
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
            thing = new Node(num);
            list1.Sort();
            list1.InsertSorted(thing);
            cout<<list1<<endl;
            break;
        case 'B':
            cin>>num;
            thing = new Node(num);
            list1.InsertBefore(thing, list1.GetNode());
            cout<<list1<<endl;
            break;
        case 'F':
            cin>>num;
            thing = new Node(num);
            list1.InsertAfter(thing, list1.GetNode());
            cout<<list1<<endl;
            break;
        case 'H':
            cin>>num;
            thing = new Node(num);
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
            thing = new Node(num);
            if(list1.Search(thing)!=NULL)
                cout<<"Found: "<<*(list1.Search(thing))<<endl;
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


//    thing2 = new Node(4);
//    thing3 = new Node(100);

//    for(int i = 0; i<8; i++)
//    {
//        thing =  new Node(i);
//        list1.InsertHead(thing);
//    }

//    cout<<list1<<endl;

//    Node *searchFor = list1.Search(thing2);
//    cout<<"searchFor: "<<*searchFor<<endl;

//    debug = new Node(100);
//    list1.InsertBefore(debug,searchFor);
//    cout<<list1<<endl;
//    debug = new Node(101);
//    list1.InsertBefore(debug,searchFor);
//    cout<<list1<<endl;

//    debug = new Node(102);
//    list1.InsertAfter(debug,searchFor);
//    cout<<list1<<endl;
//    debug = new Node(103);
//    list1.InsertAfter(debug,searchFor);
//    cout<<list1<<endl;

//    cout<<"remove searched item: "<<*(list1.Remove(searchFor))<<endl;
//    cout<<list1<<endl;

//    cout<<"removed item: "<<*(list1.Remove())<<endl;
//    cout<<list1<<endl;

//    Node* num1, *num2, *num3, *num4, *num5, *num6, *num7,*num8;

//    num1 = new Node(4);
//    num2 = new Node(3);
//    num3 = new Node(7);
//    num4 = new Node(0);
//    num5 = new Node(6);
//    num6 = new Node(-99999999);
//    num7 = new Node(2);
//    num8 = new Node(9);

//    list2.InsertSorted(num1);
//    list2.InsertSorted(num2);
//    list2.InsertSorted(num3);
//    list2.InsertSorted(num4);
//    list2.InsertSorted(num5);
//    list2.InsertSorted(num6);
//    list2.InsertSorted(num7);
//    list2.InsertSorted(num8);

//    num1 = new Node(11);
//    num2 = new Node(6);
//    num3 = new Node(7);
//    num4 = new Node(0);
//    num5 = new Node(6);
//    num6 = new Node(-9);
//    num7 = new Node(13);
//    num8 = new Node(14);

//    list3.Append(num1);
//    list3.Append(num2);
//    list3.Append(num3);
//    list3.Append(num4);
//    list3.Append(num5);
//    list3.Append(num6);
//    list3.Append(num7);
//    list3.Append(num8);

//    cout<<"list3: "<<list3<<endl;

//    cout<<"list2: "<<list2<<endl;

//    cout<<"after"<<endl;

//    list3 = list2;

//    num1 = new Node(4);
//    num6 = new Node(101);

//    searchFor = list3.Search(num1);
//    list3.InsertBefore(num6,searchFor);

//    cout<<"list2: "<<list2<<endl;
//    cout<<"list3: "<<list3<<endl;

//    num1 = new Node(11);
//    num2 = new Node(6);
//    num3 = new Node(7);
//    num4 = new Node(0);
//    num5 = new Node(6);
//    num6 = new Node(-9);
//    num7 = new Node(13);
//    num8 = new Node(14);

//    list4.Append(num1);
//    list4.Append(num2);
//    list4.Append(num3);
//    list4.Append(num4);
//    list4.Append(num5);
//    list4.Append(num6);
//    list4.Append(num7);
//    list4.Append(num8);

//    list4.Sort();

//    cout<<list4<<endl;

//    list4.Next();
//    cout<<list4<<endl;

//    list4.Previous();
//    cout<<list4<<endl;

    return 0;
}

/******************
a: Append, o: InsertSorted, b: InsertBefore, f: InsertAfter, h: InsertHead
n: Next, p: Previous, r: Remove, s: Search, t: Sort, d: DestroyAllNodes
a
1
[1] -->  NULL

a
3
1 --> [3] -->  NULL

a66
1 --> 3 --> [66] -->  NULL

a123
1 --> 3 --> 66 --> [123] -->  NULL

a47
1 --> 3 --> 66 --> 123 --> [47] -->  NULL

a
a
Invalid input.
o11
123 --> 66 --> 47 --> [11] --> 3 --> 1 -->  NULL

a33
Sorry bob. This is not the function you are looking for.
123 --> 66 --> 47 --> [11] --> 3 --> 1 -->  NULL

i22
INPUT UNRECOGNIZED ENTER AGAIN

INPUT UNRECOGNIZED ENTER AGAIN

INPUT UNRECOGNIZED ENTER AGAIN

x
Press <RETURN> to close this window...
***********************************************/
