#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
double pow();

void welcome();
void input(int user_input[]);
bool test_for_validity(int user_input[]);
void hex_to_dec(int user_input[], int output[]);
int calculation(int user_input[],int output[]);
void display(int user_input);


int main()
{
    char ans;
    int user_output[2];
    int user_input[2], output;
    //string user_input;

    welcome();

    do
    {
        do
        {
            input(user_input);
        }
        while(test_for_validity(user_input)==true);

//        do
//        {
//            input(user_input[1]);
//        }
//        while(test_for_validity(user_input[1])==true);

        hex_to_dec(user_input, output);
//        hex_to_dec(user_input[1]);

        calculation(user_input, output);

        display(output);
        //display(user_input[1]);

        cout << "Would you like to run this again? [y/n]\n";
        cin >> ans;
    }
    while (ans=='y' || ans=='Y');

    return 0;
}

void welcome()
    {
        cout << "This program will take in two 10 digit hexadecimal numbers\n"
             << "and display the sum in hexadecimal. If the sum is greater than\n"
             << "10 hexadecimal characters, it will display an overflow error.\n\n";
    }

void input(int user_input[])
    {
        string user_input;
        cout << "Please enter a 10 digit hexadecimal number.\n";
        cin >> user_input;

        while (user_input.length() > 10)
        {
            cout << "\nNumber is larger than 10 digits. Please try again.\n";
            cin >> user_input;
        }

        for (int i=0;i<user_input.length();i++)
            user_input[i]=toupper(user_input[i]);
    }

bool test_for_validity(int user_input[])
    {
    bool valid_flag;
    char hex_check[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    for (int i=0;i<user_input.length();i++)
        {
            int j=0;

            do
            {
                if (user_input[i] == hex_check[j])
                    {
                        break;
                    }
                else if (user_input[i] != hex_check[j])
                    {
                        j++;
                    }

                if (j==16)
                    {
                        cout << "Not a valid hexadecimal input.\n";
                        return valid_flag=true;
                    }
            }
            while (j<16);
        }
    }

void hex_to_dec(int user_input[], int output[])
    {
        int length;
        length = user_input.length();
        //int output[length];
        int hex[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        char hex_check[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

        //array = output[user_input.length()-1];

        for (int i=0;i<user_input.length();i++)
            {
                int j=0;

                do
                {
                    if (user_input[i] == hex_check[j])
                        {
                            output[i]=hex[j];
                            //cout << output[i];
                            break;
                        }
                    else if (user_input[i] != hex_check[j])
                        {
                            j++;
                        }
                }
                while (j<15);
            }
        //cout << array;
        //return user_input;
    }

int calculation(int user_input[], int output[])
    {
        int number=0;
        double length,num;
        length = user_input.length();
        for(int i=0;i<length;i++)
            {
                num = output[i];
                number = number + (num*pow(16,length-i));
                cout << num;
            }
        return number;
    }

void display(int user_input)
    {
        cout << user_input << endl;
    }


