/*
Programmer-     Jonathan Chan
Assignment-     CH-4 EX-5
Due Date        10/4/11
Class-          CS2
Description-    This program takes input of the past price of a movie ticket and the current price. It calculates the inflation rate and outputs the
                price a year from now and two year from now. Using functions to do the calculations and calling them for the output.
*/
#include <iostream>
#include <cstdlib>

using namespace std;

double inflation(double past_price, double current_price);
//calculates inflation rate by taking current_price/past_price subtracting 1 and multiplying by 100 to get a number
double future_price(double rate, double current_price);
//calculates a future price by mutiplying rate and current price.

int main()
{
    char repeat;
    do
    {
        double past_price;
        double current_price;
        double inflation_rate;
        double future_cost;
        double two_year_cost;
        //variable declaration

        system("cls");

        cout << "Please enter the price of a movie ticket a year ago.\n";
        cin >> past_price;
        cout << "Please enter the current price of a movie ticket.\n";
        cin >> current_price;
        //inputs for calculations

        inflation_rate = inflation(past_price, current_price);// main function call

        future_cost  = future_price(inflation_rate, current_price);//second function call

        two_year_cost = future_price(inflation_rate, future_cost);
        //calculations on price

        cout << "If a ticket was $" << past_price << " a year ago and is now $" << current_price << endl;
        cout << "The inflation rate is " << inflation_rate <<"%\n";
        cout << "At the same rate of inflation a movie will cost $" << future_cost << " next year.\n";
        cout << "and it will cost $" << two_year_cost << " two years from now.\n";
        cout << "If you wish to try again, enter Y, other wise enter any key.\n";
        cin >> repeat;
        //output of the calculations
    }while (repeat == 'y' || repeat == 'Y');
    return 0;
}

double inflation(double past_price, double current_price)//main function
{
    double rate;
    rate = current_price/past_price;
    return((rate - 1) * 100);
}
double future_price(double inflation_rate, double current_price)//secondary function
{
  return (((inflation_rate/100)+1)*current_price);
}


