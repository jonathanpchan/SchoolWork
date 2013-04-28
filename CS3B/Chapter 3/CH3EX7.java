/*Name: Jonathan Chan
 *Ex: Chapter 3 Exercice 7
 *Decription: Inputs for this program is a text file that includes 3 employees names their salaries and a pay raise amount
 *            Outputs for this program is a .dat file that rearranges the name from last, first to first, last and the updated salary after the pay raise
 *            This program reads a Ch3_Ex7Data.txt and takes the different names and salaries into individual variables. After extracting the data the program
 *            calculates the updated salaries of the 3 workers then outputs first name, last name and then the updated salary into Ch3_Ex7Output.dat
 *            
 */
package ch.pkg3.ex.pkg7;
import java.io.*;
import java.util.*;
public class CH3EX7 
{

    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner inFile = new Scanner(new FileReader("Ch3_Ex7Data.txt"));//open file with data
        PrintWriter outFile = new PrintWriter("Ch3_Ex7Output.dat");//creates file to be written to
        
        String employee1_last_name;
        String employee1_first_name;
        String employee2_last_name;
        String employee2_first_name;
        String employee3_last_name;
        String employee3_first_name;
        //strings for employee names
        double employee1_salary;
        double employee2_salary;
        double employee3_salary;
        //employee's salaries
        double employee1_pay_raise;
        double employee2_pay_raise;
        double employee3_pay_raise;
        //employee's pay raises
        double employee1_updated_salary;
        double employee2_updated_salary;
        double employee3_updated_salary;
        //employee's updated salary
        
        employee1_last_name = inFile.next();
        employee1_first_name = inFile.next();
        employee1_salary = inFile.nextDouble();
        employee1_pay_raise = inFile.nextDouble();
        //getting employee 1 information
        employee2_last_name = inFile.next();
        employee2_first_name = inFile.next();
        employee2_salary = inFile.nextDouble();
        employee2_pay_raise = inFile.nextDouble();
        //getting employee 2 information
        employee3_last_name = inFile.next();
        employee3_first_name = inFile.next();
        employee3_salary = inFile.nextDouble();
        employee3_pay_raise = inFile.nextDouble();
        //getting employee 3 information
        
        employee1_updated_salary = ((1+(employee1_pay_raise/100)) * employee1_salary);
        employee2_updated_salary = ((1+(employee2_pay_raise/100)) * employee2_salary);
        employee3_updated_salary = ((1+(employee3_pay_raise/100)) * employee3_salary);
        //calculating updated salaries
        
   
        outFile.printf(employee1_first_name + " " + employee1_last_name + " %.2f%n", employee1_updated_salary);
        outFile.printf(employee2_first_name + " " + employee2_last_name + " %.2f%n", employee2_updated_salary);
        outFile.printf(employee3_first_name + " " + employee3_last_name + " %.2f%n", employee3_updated_salary);
        //writing first name, last name then the updated salaries of the three employees
        
        inFile.close();
        outFile.close();
    }
}
/*
run:
BUILD SUCCESSFUL (total time: 0 seconds)
(In Ch3_Ex7Data.txt)(which is where info was extracted from
Miller Andrew 65789.87 5
Greem Sheila 75892.56 6
Sethi Amit 74900.50 6.1
 
(In Ch3_Ex7Output.dat)(which is created)
Andrew Miller 69079.36
Sheila Greem 80446.11
Amit Sethi 79469.43
*/