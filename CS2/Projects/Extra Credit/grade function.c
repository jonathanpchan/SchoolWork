/*
Programmer : Jonathan Chan
date: 9/29/11
project: 9/29 extra credit
description: uses a function at the end to ask for a score and total and outputs the grade on the test
*/
#include <iostream>

using namespace std;

char grade (double total_par,double score_par); //returns grade based on percentage
//function declaration
int main()
{
    do
    {
        double total;
        double score;
        char lettergrade;
        char repeat;
        // Decleration of variables

        cout << "Please enter the points you got, and the total points on the test.\n";
        cin >> score >> total; //variable input
        lettergrade = grade(total, score); //function call
        cout << "If you got " << score << " out of " << total;
        cout << " Then you got an " << lettergrade << " on the test";
        cout << "If you wish to try again press Y, else press any key and enter";
        cin >> repeat;
    while (repeat = 'y' || repeat = 'Y')

        //output
        return 0;
}

char grade(double total_par,double score_par)// function head
{
    double percentage;
    percentage = score_par/total_par;
    if (percentage >= .9)
    {
        return 'A'; //returns a if % >.9
    }

    else if ((percentage < .9)&&(percentage >=.8))
    {
        return 'B'; //returns b if % >.8 and < .9
    }

    else if ((percentage < .8)&&(percentage >=.7))
    {
        return 'C'; //returns c if % >.7 and <.8
    }

    else if ((percentage < .7)&&(percentage >=.6))
    {
        return 'D'; //returns d if % >.6 and <.6
    }
    else
    {
        return 'F'; //returns f
    }
//function body
}



