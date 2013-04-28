/*---------------------------------------------------------------------------------------------------------
Project: 4-6 calculate interest on a credit card balance
Author: Jonathan Chan
Description: calculate interest based on initial balance, 
---------------------------------------------------------------------------------------------------------*/



#include <iostream>

using namespace std;

//prototypes
void GetInput(double& balance, double& monthRate, double& months);//gets input from user
double Compute(double balance, double monthRate, double months);//calculates the total interest
void Print(int total);//prints the result



int main()
{
	double initBal, rate, months, total;
	
	GetInput(initBal, rate, months);
	total = Compute(initBal, rate, months);
	print(total);
	

	return 0;
}

/*---------------------------------------------------------------------------------------
 *Name - GetInput
 *Arguments - balance, monthly rate, months
 *Return values - none, input function
 *Description - function that gets input from the user.
 *Notes -
-----------------------------------------------------------------------------------------*/
void GetInput(double& balance, double& monthRate, double& months)
{
}



/*---------------------------------------------------------------------------------------
 *Name - Compute
 *Arguments - balance, monthly rate, months
 *Return values - returns the total that needs to be paid
 *Description - calculates the balance based on the input from user.
 *Notes -
-----------------------------------------------------------------------------------------*/
double Compute(double balance, double monthRate, double months)
{
}

/*---------------------------------------------------------------------------------------
 *Name - Print
 *Arguments - total
 *Return values - none, output function
 *Description - this function simply prints output.
 *Notes -
-----------------------------------------------------------------------------------------*/
void Print(int total)
{
}
