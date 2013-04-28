/*
Programmer-     Jonathan Chan
Assignment-     CH-5 EX-4
Due Date        10/27/11
Class-          CS2
Description-    This program takes 4 scores and then computes average and standard deviation using a function that calls other functions
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void the_function(double& score1, double& score2, double& score3, double& score4, double& average, double& standard_deviation);//gets inputs calls other functions
void the_average(double score1, double score2, double score3, double score4, double& average);//computes average
void the_standard_deviation(double score1, double score2, double score3, double score4, double& average, double& standard_deviation);//computers standard deviation
int main()
{
    double score1;
    double score2;
    double score3;
    double score4;
    double average;
    double standard_deviation;
    char repeat;
    //variable declaration
    do
    {
        system("cls");
        the_function(score1, score2, score3, score4, average, standard_deviation);//main function call
        cout << "Press Y to try again.\n";
        cin >> repeat;
    }while (repeat == 'y' || repeat == 'Y');//loop

    return 0;
}
void the_function(double& score1, double& score2, double& score3, double& score4, double& average, double& standard_deviation)
{
    cout << "Please enter score 1.\n";
    cin >> score1;
    cout << "Please enter score 2.\n";
    cin >> score2;
    cout << "Please enter score 3.\n";
    cin >> score3;
    cout << "Please enter score 4.\n";
    cin >> score4;
    //recieving score inputs

    the_average(score1, score2, score3, score4, average);//average function call
    the_standard_deviation(score1, score2, score3, score4, average, standard_deviation);//standard deviation function call

    cout << "If your scores are " << score1 << ", " << score2 << ", " << score3 << ", " << score4 << ".\n";
    cout << "Then your average is " << average << ".\n";
    cout << "and your Standard Deviation is " << standard_deviation << ".\n";
    //output of results

}
void the_average(double score1, double score2, double score3, double score4, double& average)//computes average

{
    average = ((score1+score2+score3+score4)/4);
}
void the_standard_deviation(double score1, double score2, double score3, double score4, double& average, double& standard_deviation)//computes standard deviation
{
    standard_deviation = sqrt((pow((score1 - average),2)+pow((score2 - average),2)+pow((score3 - average),2)+pow((score4 - average),2))/4);
}
/*

SAMPLE OUTPUT

Please enter score 1.
5
Please enter score 2.
10
Please enter score 3.
15
Please enter score 4.
20
If your scores are 5, 10, 15, 20.
Then your average is 12.5.
and your Standard Deviation is 5.59017.
Press Y to try again.
n

Process returned 0 (0x0)   execution time : 4.185 s
Press any key to continue.
*/
