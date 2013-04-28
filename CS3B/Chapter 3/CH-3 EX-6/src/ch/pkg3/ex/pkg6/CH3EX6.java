/*Name: Jonathan Chan
 *Ex: Chapter 3 Exercice 6
 *Decription: Inputs for this program are dialog boxes that ask for an employee name and the gross amount to be paid
 *            Outputs for this program is a file that contains the employee name, gross amount, federal/state/social security/medicare(medicaid) taxes(amount)
 *            the pension plan/health insurance(amount) and the net pay(total after taxes and fees)
 *            This program opens and writes to a new file called paycheck.txt It then asks using dialog boxes for an employee name and a gross amount
 *            in then parses the gross amount from the string and uses that number to calculate all the taxes and fees. Then the program starts to write
 *            the employee name, gross amount, taxes/pension/insurance(individual amount) and the net pay after all fees.
 *            
 */
package ch.pkg3.ex.pkg6;
import java.io.*;
import java.util.*;
import javax.swing.*;


public class CH3EX6
{

    public static void main(String[] args) throws FileNotFoundException
    {
        PrintWriter outFile = new PrintWriter("paycheck.txt");//creates file to be written to
        
        String employee_name;
        String gross_amount_string;
        //inputs from user
        double gross_amount;
        //double for gross amount
        final double FEDERAL_INCOME_TAX = .15;
        double federal_tax_total;
        //federal tax information
        final double STATE_TAX = .035;
        double state_tax_total;
        //state tax information
        final double SOCIAL_SECURITY_TAX = .0575;
        double social_security_tax_total;
        //social security tax information
        final double MEDICARE_MEDICAID_TAX = .0275;
        double medicare_medicaid_tax_total;
        //medicare/medicaid tax information
        final double PENSION_PLAN = .05;
        double pension_plan_total;
        //pension plan information
        final double HEALTH_INSURANCE = 75;
        //health insurance costs
        double net_pay;
        
        employee_name = JOptionPane.showInputDialog("Please enter the Employee Name and press OK");
        gross_amount_string = JOptionPane.showInputDialog("Please enter the gross amount to be paid");
        //getting input via dialog box from user
        gross_amount = Double.parseDouble(gross_amount_string);
        //parsing the number from the input
        
        federal_tax_total = (FEDERAL_INCOME_TAX * gross_amount);
        state_tax_total = (STATE_TAX * gross_amount);
        social_security_tax_total = (SOCIAL_SECURITY_TAX * gross_amount);
        medicare_medicaid_tax_total = (MEDICARE_MEDICAID_TAX* gross_amount);
        pension_plan_total = (PENSION_PLAN * gross_amount);
        net_pay = (gross_amount - federal_tax_total - state_tax_total - social_security_tax_total - medicare_medicaid_tax_total - pension_plan_total - HEALTH_INSURANCE);
        //Calculates totals for taxes and fees
                   
        outFile.println("Employee:              " + employee_name);
        outFile.printf("Gross Amount:          $%.2f%n", gross_amount);
        outFile.printf("Federal Income Tax:    $%.2f%n", federal_tax_total);
        outFile.printf("State Tax:             $%.2f%n", state_tax_total);
        outFile.printf("Social Security Tax    $%.2f%n", social_security_tax_total);
        outFile.printf("Medicare/Medicaid Tax  $%.2f%n", medicare_medicaid_tax_total);
        outFile.printf("Pension Plan           $%.2f%n", pension_plan_total);
        outFile.printf("Health Insurance       $%.2f%n", HEALTH_INSURANCE);
        outFile.printf("Net Pay:               $%.2f%n", net_pay);
        //writes the inputs recieved by the user and the fees and taxes that were calculated to a file called paycheck.txt
               
        outFile.close();//close the file
    }
}
/*
 * run:
BUILD SUCCESSFUL (total time: 16 seconds)
(In paycheck.txt)
Employee:              Bob The Builder
Gross Amount:          $3575.00
Federal Income Tax:    $536.25
State Tax:             $125.13
Social Security Tax    $205.56
Medicare/Medicaid Tax  $98.31
Pension Plan           $178.75
Health Insurance       $75.00
Net Pay:               $2356.00

*/