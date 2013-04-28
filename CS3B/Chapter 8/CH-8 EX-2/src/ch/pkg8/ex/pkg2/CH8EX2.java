package ch.pkg8.ex.pkg2;
import java.util.Scanner;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH8EX2
{  
    static Scanner console = new Scanner(System.in);
    public static void main(String[] args)
    {
        Roman convert = new Roman();//creating object Roman named convert
        int choice;
		  String roman;
		  System.out.println("Pleas enter a roman numeral");
		  roman = console.next().toUpperCase();
        convert.getString(roman);
        convert.getValues();
        convert.romanToDecimal();
		  System.out.println("If you want the decimal enter 1, if you want the roman numeral enter 2");
        choice = console.nextInt();
        convert.showOutput(choice);
    }     
    public static class Roman
    {
        private String roman_numeral;
        private int[] values;
        private int converted = 0;
        
        public void getString(String roman)
        { 
            roman_numeral = roman;            
        }
        public void getValues()
        {
            values = new int[roman_numeral.length() + 1];
            values[roman_numeral.length()] = 0;
            for(int i = 0; i<roman_numeral.length(); i++)
            {
					switch(roman_numeral.charAt(i))
					{
						case 'M':
							values[i] = 1000;
							break;
						case 'D':
							values[i] = 500;
							break;
						case 'C':
							values[i] = 100;
							break;
						case 'L':
							values[i] = 50;
							break;
						case 'X':
							values[i] = 10;
							break;
						case 'V':
							values[i] = 5;
							break;
						case 'I':
							values[i] = 1;
							break;
						default:
							System.out.println("Error in input");
                     System.exit(1);
					}
                if(roman_numeral.charAt(i)== 'M')
                {
                    values[i] = 1000;
                }
                else if(roman_numeral.charAt(i)== 'D')
                {
                    values[i] = 500;
                }
                else if(roman_numeral.charAt(i)== 'C')
                {
                    values[i] = 100;
                }
                else if(roman_numeral.charAt(i)== 'L')
                {
                    values[i] = 50;
                }
                else if(roman_numeral.charAt(i)== 'X')
                {
                    values[i] = 10;
                }
                else if(roman_numeral.charAt(i)== 'V')
                {
                    values[i] = 5;
                }
                else if (roman_numeral.charAt(i) == 'I')
                {
                    values[i] = 1;
                }
                else
                {
                    System.out.println("Error in input");
                    System.exit(0);
                }
            }            
        }
        public void romanToDecimal()
        {
           for(int i=0; i < roman_numeral.length(); i++)
           {
                if(values[i] < values[i + 1])
                {
                    converted = converted - values[i];
                }
                else
                {
                    converted = converted + values [i];
                }
           }     
        }
        public void showOutput(int choice)
        {
            if(choice == 1)
            {
                System.out.println("The Roman Numeral " + roman_numeral + " is " + converted);                 
            }
            else
            {
                System.out.println("The Roman Numeral you entered is " + roman_numeral);                       
            }
        }
    }    
}

