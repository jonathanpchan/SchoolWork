#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inputstream1;
    ifstream inputstream2;

    inputstream1.open("data1.txt");
    inputstream2.open("data2.txt");
    inputstream.

    int num1;
    int num2;
    inputstream1 >> num1;
    inputstream2 >> num2;

    cout << num1 << " " << num2 << endl;

    while(!inputstream2.eof())
    {
        inputstream2 >> num2;
        cout << num2 << endl;
    }
    inputstream1.close();
    inputstream2.close();

}

