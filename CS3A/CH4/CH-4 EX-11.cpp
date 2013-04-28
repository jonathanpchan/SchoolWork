/*-----------------------------------------------------------------------------------------
Project: 4-11 Overload abs
Author: Jonathan Chan
Description: overload the abs function using other data types.
-----------------------------------------------------------------------------------------*/


#include <iostream>
using namespace std;


double abs(double num);//abs for doubles
long abs(long num);//abs for longs
float abs(float num);//abs for floats
int abs(int num);//abs for integers
short abs(short num);//abs for shorts

int main()
{
    double doubleTest, doubleAns;
    float floatTest, floatAns;
    long longTest, longAns;
    int intTest, intAns;
	short shortTest, shortAns;

    cin >> doubleTest;
    doubleAns = abs(doubleTest);
    cout << doubleAns;
    
    cin >> floatTest;
    floatAns=abs(floatTest);
    cout << floatAns;
    
    cin >> longTest;
    longAns = abs(longTest);
    cout << longAns;
    
    cin >> intTest;
    intAns = abs(intTest);
    cout << intAns;

	cin >> shortTest;
    shortAns = abs(shortTest);
    cout << shortAns;

	return 0;
}


/*-----------------------------------------------------------------------------------------
 *Name - abs
 *Arguments -  double num	
 *Return values - absolute value of num
 *Description - overloads abs, returns abs of a double
 *Notes -
 -----------------------------------------------------------------------------------------*/
double abs(double num)
{
    
}


/*-----------------------------------------------------------------------------------------
 *Name - abs
 *Arguments -  long num	
 *Return values - absolute value of num
 *Description - overloads abs, returns abs of a long
 *Notes -
 -----------------------------------------------------------------------------------------*/
long abs(long num)
{
    
}


/*-----------------------------------------------------------------------------------------
 *Name - abs
 *Arguments -  float num	
 *Return values - absolute value of num
 *Description - overloads abs, returns abs of a float
 *Notes -
 -----------------------------------------------------------------------------------------*/
float abs(float num)
{
    
}


/*-----------------------------------------------------------------------------------------
 *Name - abs
 *Arguments -  int num	
 *Return values - absolute value of num
 *Description - overloads abs, returns abs of a int
 *Notes -
 -----------------------------------------------------------------------------------------*/
int abs(int num)
{
    
}


/*-----------------------------------------------------------------------------------------
 *Name - abs
 *Arguments -  short num	
 *Return values - absolute value of num
 *Description - overloads abs, returns abs of a short
 -----------------------------------------------------------------------------------------*/
short abs(short num)
{
}