/*-----------------------------------------------------------------------------------------
Project: 4-11 Time Machine
Author: Jonathan Chan
Description: Calculate the minutes for input into a time machine
-----------------------------------------------------------------------------------------*/


#include <iostream>

using namespace std;


void GetStart(int& sHours, int& sMins, bool& sAm);//gets starting information
void GetFut(int& fHours, int& fMins,bool& fAm);//gets future information
int Compute(int sHours, int sMins, int fHours, int fMins, bool sAm, bool fAm);//compute the number of minutes needed for input into time machine
void Print(int minutes);//prints the minutes

int main()
{
	int startHours, startMins, futureHours, futureMins, total;
	bool startAm, futureAm;
	
	GetStart(startHours, startMins, startAm);
	GetFut(futureHours, futureMins, futureAm);
	total=Compute(startHours, startMins, futureHours, futureMins, startAm, futureAm);
	print(total);
	
	return 0;

}



/*-----------------------------------------------------------------------------------------
 *Name -GetStart
 *Arguments -	start hours, start mins, start am
 *Return values - none input function
 *Description - this function gets the starting information from the user
 *Notes -
 -----------------------------------------------------------------------------------------*/
void GetStart(int& sHours, int& sMins, bool& sAm)
{
}


/*-----------------------------------------------------------------------------------------
 *Name - GetFut
 *Arguments -	future hours, future mins, future am
 *Return values - none, input function
 *Description - this function gets the future information from the user.
 *Notes -
 -----------------------------------------------------------------------------------------*/
void GetFut(int& fHours, int& fMins,bool& fAm)
{
}


/*-----------------------------------------------------------------------------------------
 *Name - Compute
 *Arguments -	start hours start mins, future hours, future mins, start am, start pm
 *Return values - returns total minutes from calculations
 *Description - calculates based on the 6 variables to get a precise amount of minutes to
	input into time machine.
 *Notes -
 -----------------------------------------------------------------------------------------*/
int Compute(int sHours, int sMins, int fHours, int fMins, bool sAm, bool fAm)
{
}



/*-----------------------------------------------------------------------------------------
 *Name - Print
 *Arguments - minutes	
 *Return values - none, output
 *Description - prints the minutes to the user.
 *Notes -
 -----------------------------------------------------------------------------------------*/
void Print(int minutes)
{
}