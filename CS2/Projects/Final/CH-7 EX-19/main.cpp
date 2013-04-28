/*
Programmer-     Jonathan Chan
Assignment-     CH-7 EX-19
Due Date        12/15/11
Class-          CS2
Description-    This program has a pin and randomized numbers (1-3) for each value (0-10) the user inputs the corresponding randomized numbers as a password, the program checks this and either grants access or locks the user out.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void mix_the_numbers(int random_numbers[], int size);//assigns 10 random numbers between 1 and 3
void show_mixed_numbers(int random_numbers[], int size);//displays the mixed numbers in correlation with the standard numbers
void password_input(int entered_password[], int size);//takes in a password
void pin_to_password(int random_numbers[], int correct_password[]);//converts a number to a correct input
void check_password(int entered_password[], int correct_password[],int size);//checks the passwords to see if they are correct
int main()
{

    int random_numbers[10];//array for randomized numbers
    int entered_password[5];//array for inputted password
    int correct_password[5];//array to check inputted password against


    mix_the_numbers(random_numbers, 10);//assigns 10 random numbers between 1 and 3
    show_mixed_numbers(random_numbers, 10); //outputs the numbers and the corresponding randomized number
    password_input(entered_password, 5);//acceots a password from the user
    pin_to_password(random_numbers, correct_password);//converts the pin 12345 to the correct random password
    check_password(entered_password, correct_password, 5);//checks the password
    }
void mix_the_numbers(int random_numbers[], int size)
{
    srand (time(NULL));//random seed
    for (int i = 0; i < size; i++)
    {
        random_numbers[i] = (rand() % 3) + 1;//randomizes the number from 1-3

    }
}
void show_mixed_numbers(int random_numbers[], int size)// showing the random numbers to the correct pin number
{
    cout << "The Pin Number is 12345.\n";
    cout << "Number: 0 1 2 3 4 5 6 7 8 9\n";
    cout << "Random: ";
    for (int i = 0; i < size; i++)
    {
        cout << random_numbers[i] << " ";
    }
    cout << "\n";
 }
void password_input(int entered_password[], int size)//takes a password in from the user
{
    cout << "Please enter the corresponding number to the pin.\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter digit " << i+1 << " of your password.\n";
        cin >> entered_password[i];
    }
}
void pin_to_password(int random_numbers[], int correct_password[])//makes an array witht the correct password
{
    for (int i = 0; i < 6; i++)
    {
        correct_password[i] = random_numbers[i+1];
    }
}
void check_password(int entered_password[], int correct_password[],int size)//checks to see if the password is correct
{
    if(entered_password[0]!=correct_password[0])
    {
        cout << "Wrong password inputted, locking user out" << endl;
    }
    else if(entered_password[1]!=correct_password[1])
    {
        cout << "Wrong password inputted, locking user out" << endl;
    }
    else if(entered_password[2]!=correct_password[2])
    {
        cout << "Wrong password inputted, locking user out" << endl;
    }
    else if(entered_password[3]!=correct_password[3])
    {
        cout << "Wrong password inputted, locking user out" << endl;
    }
    else if(entered_password[4]!=correct_password[4])
    {
        cout << "Wrong password inputted, locking user out" << endl;
    }
    else
    {
        cout << "Access Granted" << endl;
    }
}
/*
Sample output
The Pin Number is 12345.
Number: 0 1 2 3 4 5 6 7 8 9
Random: 2 1 2 2 2 2 1 3 3 1
Please enter the corresponding number to the pin.
Enter digit 1 of your password.
1
Enter digit 2 of your password.
2
Enter digit 3 of your password.
2
Enter digit 4 of your password.
2
Enter digit 5 of your password.
2
Access Granted
Process returned 0 (0x0)   execution time : 4.760 s
Press any key to continue.
*/
