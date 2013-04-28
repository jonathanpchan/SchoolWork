/*Name: Jonathan Chan
 *Program: Chapter-8 Exercise-2
 *Description:  Inputs for this program are a roman numeral string and a choice for wanted output
 *              Outputs for this program include the converted number and the roman numeral based on user input
 *              This program uses a class and the methods in the class to make a program to convert roman numerals
 *              it uses an array to store each character from the roman numeral string and uses simple math to calculate the
 *              converted number. Then based on user input it outputs either the converted number or the roman numeral the user entered. 
 */     
package ch.pkg8.ex.pkg2;
import java.util.Scanner;

public class CH8EX2
{  
    static Scanner console = new Scanner(System.in);
    public static void main(String[] args)
    {
        Roman convert = new Roman();//creating object Roman named convert
        int choice;//used for user choice for output
        String roman;//used to take in string.
        
        System.out.println("Pleas enter a roman numeral");
        roman = console.next().toUpperCase();//to upper for easy conversion
        
        convert.getString(roman);//using getstring method
        convert.getValues();//using get value method
        convert.romanToDecimal();//using romanToDecimal method
        
        System.out.println("If you want the decimal enter 1, if you want the roman numeral enter 2");//user choice
        choice = console.nextInt();//taking user choice
        convert.showOutput(choice);//output depending on user choice
    }     
    public static class Roman//class roman
    {
        private String roman_numeral;//string to store the text string
        private int[] values;//array to hold the converted numbers broken down
        private int converted = 0;
        
        public void getString(String roman)//getting input from the user
        { 
            roman_numeral = roman;//getting input            
        }
        public void getValues()//getting values for each part of the roman numeral
        {
            values = new int[roman_numeral.length() + 1];//array + 1 forr when it reaches the end of the string used in later output
            values[roman_numeral.length()] = 0;//setting the last variable in the array to 0 for later
            for(int i = 0; i<roman_numeral.length(); i++)//for loop to break down the string into seperate numbers
            {
                if(roman_numeral.charAt(i)== 'M')//storing value of M to be 1000
                {
                    values[i] = 1000;
                }
                else if(roman_numeral.charAt(i)== 'D')//storing value of D to be 500
                {
                    values[i] = 500;
                }
                else if(roman_numeral.charAt(i)== 'C')//storing value of C to be 100
                {
                    values[i] = 100;
                }
                else if(roman_numeral.charAt(i)== 'L')//storing value of L to be 50
                {
                    values[i] = 50;
                }
                else if(roman_numeral.charAt(i)== 'X')//storing value of x to be 10
                {
                    values[i] = 10;
                }
                else if(roman_numeral.charAt(i)== 'V')//storing value of V to be 5
                {
                    values[i] = 5;
                }
                else if (roman_numeral.charAt(i) == 'I')//storing value of I to be 1
                {
                    values[i] = 1;
                }
                else//if input is not roman numeral outputs error and ends program
                {
                    System.out.println("Error in input");
                    System.exit(1);
                }
            }            
        }
        public void romanToDecimal()//to calculate the number from the roman numeral
        {
           for(int i=0; i < roman_numeral.length(); i++)//using for loop 
           {
                if(values[i] < values[i + 1])//it current one is less than the next one it subtracts the current one from the current "converted"
                {
                    converted = converted - values[i];
                }
                else//if current one is larger or equal then it adds it the the current "converted"
                {
                    converted = converted + values [i];
                }
           }     
        }
        public void showOutput(int choice)//show output based on user choice
        {
            if(choice == 1)//if they choose 1 it outputs the converted number
            {
                System.out.println("The Roman Numeral " + roman_numeral + " is " + converted);                 
            }
            else//otherwise it outputs the roman numeral that they entered.
            {
                System.out.println("The Roman Numeral you entered is " + roman_numeral);                       
            }
        }
    }    
}
//Sample run:
//run:
//Pleas enter a roman numeral
//MDCXIV
//If you want the decimal enter 1, if you want the roman numeral enter 2
//1
//The Roman Numeral MDCXIV is 1614
//BUILD SUCCESSFUL (total time: 11 seconds)
