/*
Programmer-     Jonathan Chan
Assignment-     CH-4 EX-13
Due Date        10/18/11
Class-          CS2
Description-    This Program gets a number input 1-99 from the user converts that number to a the textual string version of that number and then
                outputs the lyrics of Ninety-Nine Bottles of Beer on the Wall from that number.
*/
#include <iostream>
#include <string>

using namespace std;

string number_in_english(int bottles);

int main()
{
    int bottles;
    string converted_number;
    //variable declaration

    cout << "Ninety-Nine Bottles of Beer on the Wall Lyric Checker v.1\n";
    cout << "Please enter a number from 0-99.\n";
    cin >> bottles;//getting input for the number of bottles
    cout << "Here We Go!\n";
    while (bottles > 0)//loop for lyrics to repeat until lyrics hit zero
    {
        converted_number = number_in_english(bottles);//converts the number into the text string
        cout << converted_number << " Bottles Of Beer on the Wall,\n";//output of that text string
        cout << converted_number << " Bottles Of Beer!\n";
        cout << "Take One Down, Pass it around,\n";
        bottles = bottles - 1;//changes the value of bottles to the next lowest number
        converted_number = number_in_english(bottles);//calculates the new number for bottle.
        cout << converted_number << " Bottles Of Beer on the Wall.\n";//outputs the next number and loops if bottles is > 0
    }
    return 0;
}
string number_in_english(int bottles)
{
    int tens;
    int ones;
    string number_changed;
    //variable declaration to help split the number into tens and ones

    tens = bottles/10;//calculates the tens-value, ninety, eighty, seventy etc.
    ones = bottles%10;//calculates the ones-value, nine, eight, seven etc.

    switch(tens)//switch to first set the first part of the number if it is over 10
    {
        case 9:
            number_changed = "Ninety";//Sets Ninety as string if tens = 9
            break;
        case 8:
            number_changed = "Eighty";//Sets Eighty as string if tens = 8
            break;
        case 7:
            number_changed = "Seventy";//Sets Seventy as string if tens = 7
            break;
        case 6:
            number_changed = "Sixty";//Sets Sixty as string if tens = 6
            break;
        case 5:
            number_changed = "Fifty";//Sets Fifty as string if tens = 5
            break;
        case 4:
            number_changed = "Fourty";//Sets Fourty as string if tens = 4
            break;
        case 3:
            number_changed = "Thirty";//Sets Thirty as string if tens = 3
            break;
        case 2:
            number_changed = "Twenty";//Sets Twenty as string if tens = 2
            break;
        case 1:
            switch (ones)//Special case switch for the teen values
            {
                case 9:
                    number_changed = "Nineteen";//Sets Nineteen as string when tens = 1 and ones = 9
                    break;
                case 8:
                    number_changed = "Eighteen";//Sets Eighteen as string when tens = 1 and ones =8
                    break;
                case 7:
                    number_changed = "Seventeen";//Sets Seventeen as string when tens = 1 and ones = 7
                    break;
                case 6:
                    number_changed = "Sixteen";//Sets Sixteen as string when tens = 1 and ones = 6
                    break;
                case 5:
                    number_changed = "Fifteen";//Sets Fifteen as string when tens = 1 and ones = 5
                    break;
                case 4:
                    number_changed = "Fourteen";//Sets Four as string when tens = 1 and ones = 4
                    break;
                case 3:
                    number_changed = "Thirteen";//Sets Thirteen as string when tens = 1 and ones = 3
                    break;
                case 2:
                    number_changed = "Twelve";//Sets Twelve as string when tens = 1 and ones = 2
                    break;
                case 1:
                    number_changed = "Eleven";//Sets Eleven as string when tens = 1 and ones = 1
                    break;
                case 0:
                    number_changed = "Ten";//Sets Ten as string when tens = 1 and ones = 0
                    break;
            }
            break;
        case 0://When tens=0 there is no tens string so this sets the string to be blank
            number_changed = "";
            break;
    }
    if ((ones > 0) && (tens > 1))//adds a dash if the one value is > 0 and tens > 1 to avoid errors in the dash placement ex ninteteen- or -eight
    {
        number_changed = number_changed + "-";
    }
    if (tens != 1)//adds the one value as long as tens != to one to avoid conflict with the special case switch
    {
        switch (ones)
        {
            case 9:
                number_changed = number_changed + "Nine";//Adds Nine to string when ones = 9
                break;
            case 8:
                number_changed = number_changed + "Eight";//Adds Eight to string when ones = 8
                break;
            case 7:
                number_changed = number_changed + "Seven";//Adds Seven to string when ones = 7
                break;
            case 6:
                number_changed = number_changed + "Six";//Adds Six to string when ones = 6
                break;
            case 5:
                number_changed = number_changed + "Five";//Adds Five to string when ones = 5
                break;
            case 4:
                number_changed = number_changed + "Four";//Adds Four to string when ones = 4
                break;
            case 3:
                number_changed = number_changed + "Three";//Adds Three to string when ones = 3
                break;
            case 2:
                number_changed = number_changed + "Two";//Adds Two to string when ones = 2
                break;
            case 1:
                number_changed = number_changed + "One";//Adds One to string when ones = 1
                break;
            case 0:
                number_changed = number_changed + "";//Adds nothing to string when ones = 0
                break;
        }
    }
    if (tens == 0 && ones == 0)//Special case at the end to set string to be Zero for the last line
    {
     number_changed = "Zero";
    }
    return(number_changed);//returns the string to the main progra,
}
/*
SAMPLE OUTPUT

Ninety-Nine Bottles of Beer on the Wall Lyric Checker v.1
Please enter a number from 0-99.
25
Here We Go!
Twenty-Five Bottles Of Beer on the Wall,
Twenty-Five Bottles Of Beer!
Take One Down, Pass it around,
Twenty-Four Bottles Of Beer on the Wall.
Twenty-Four Bottles Of Beer on the Wall,
Twenty-Four Bottles Of Beer!
Take One Down, Pass it around,
Twenty-Three Bottles Of Beer on the Wall.
Twenty-Three Bottles Of Beer on the Wall,
Twenty-Three Bottles Of Beer!
Take One Down, Pass it around,
Twenty-Two Bottles Of Beer on the Wall.
Twenty-Two Bottles Of Beer on the Wall,
Twenty-Two Bottles Of Beer!
Take One Down, Pass it around,
Twenty-One Bottles Of Beer on the Wall.
Twenty-One Bottles Of Beer on the Wall,
Twenty-One Bottles Of Beer!
Take One Down, Pass it around,
Twenty Bottles Of Beer on the Wall.
Twenty Bottles Of Beer on the Wall,
Twenty Bottles Of Beer!
Take One Down, Pass it around,
Nineteen Bottles Of Beer on the Wall.
Nineteen Bottles Of Beer on the Wall,
Nineteen Bottles Of Beer!
Take One Down, Pass it around,
Eighteen Bottles Of Beer on the Wall.
Eighteen Bottles Of Beer on the Wall,
Eighteen Bottles Of Beer!
Take One Down, Pass it around,
Seventeen Bottles Of Beer on the Wall.
Seventeen Bottles Of Beer on the Wall,
Seventeen Bottles Of Beer!
Take One Down, Pass it around,
Sixteen Bottles Of Beer on the Wall.
Sixteen Bottles Of Beer on the Wall,
Sixteen Bottles Of Beer!
Take One Down, Pass it around,
Fifteen Bottles Of Beer on the Wall.
Fifteen Bottles Of Beer on the Wall,
Fifteen Bottles Of Beer!
Take One Down, Pass it around,
Fourteen Bottles Of Beer on the Wall.
Fourteen Bottles Of Beer on the Wall,
Fourteen Bottles Of Beer!
Take One Down, Pass it around,
Thirteen Bottles Of Beer on the Wall.
Thirteen Bottles Of Beer on the Wall,
Thirteen Bottles Of Beer!
Take One Down, Pass it around,
Twelve Bottles Of Beer on the Wall.
Twelve Bottles Of Beer on the Wall,
Twelve Bottles Of Beer!
Take One Down, Pass it around,
Eleven Bottles Of Beer on the Wall.
Eleven Bottles Of Beer on the Wall,
Eleven Bottles Of Beer!
Take One Down, Pass it around,
Ten Bottles Of Beer on the Wall.
Ten Bottles Of Beer on the Wall,
Ten Bottles Of Beer!
Take One Down, Pass it around,
Nine Bottles Of Beer on the Wall.
Nine Bottles Of Beer on the Wall,
Nine Bottles Of Beer!
Take One Down, Pass it around,
Eight Bottles Of Beer on the Wall.
Eight Bottles Of Beer on the Wall,
Eight Bottles Of Beer!
Take One Down, Pass it around,
Seven Bottles Of Beer on the Wall.
Seven Bottles Of Beer on the Wall,
Seven Bottles Of Beer!
Take One Down, Pass it around,
Six Bottles Of Beer on the Wall.
Six Bottles Of Beer on the Wall,
Six Bottles Of Beer!
Take One Down, Pass it around,
Five Bottles Of Beer on the Wall.
Five Bottles Of Beer on the Wall,
Five Bottles Of Beer!
Take One Down, Pass it around,
Four Bottles Of Beer on the Wall.
Four Bottles Of Beer on the Wall,
Four Bottles Of Beer!
Take One Down, Pass it around,
Three Bottles Of Beer on the Wall.
Three Bottles Of Beer on the Wall,
Three Bottles Of Beer!
Take One Down, Pass it around,
Two Bottles Of Beer on the Wall.
Two Bottles Of Beer on the Wall,
Two Bottles Of Beer!
Take One Down, Pass it around,
One Bottles Of Beer on the Wall.
One Bottles Of Beer on the Wall,
One Bottles Of Beer!
Take One Down, Pass it around,
Zero Bottles Of Beer on the Wall.

Process returned 0 (0x0)   execution time : 1.750 s
Press any key to continue.
*/
