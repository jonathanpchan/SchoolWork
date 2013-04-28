/*Name: Jonathan Chan
 *Ex: Chapter 3 Exercice 5
 *Decription: Inputs for this program box/sideline/premium/general tickets sold and prices
 *            outputs for this file include the total number of tickets sold and the total from sales
 *            This program uses Scanner to read a file listing different types of tickets, their price and the number of tickets that were sold
 *            This program reads all the information then calculates the total number of tickets sold and the total from sales.
 */
package ch.pkg3.ex.pkg5;
import java.io.*;
import java.util.*;

public class CH3EX5
{

    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner inFile = new Scanner(new FileReader("ticketdata.txt"));//open file
        
        double box_price;
        double box_sold;
        double box_total;
        //variables for box tickets
        double sideline_price;
        double sideline_sold;
        double sideline_total;
        //variables for sideline tickets
        double premium_price;
        double premium_sold;
        double premium_total;
        //variables for premium tickets
        double general_price;
        double general_sold;
        double general_total;
        //variables for general tickets
        double total_tickets;
        double total;
        //totals
        String ticket_prices;
        String tickets_sold;
        //for the first two strings in the file
        
        
        ticket_prices = inFile.next();
        tickets_sold = inFile.next();
        //getting the first two strings
        box_price = inFile.nextDouble();
        box_sold = inFile.nextDouble();
        //box ticket information
        sideline_price = inFile.nextDouble();
        sideline_sold = inFile.nextDouble();
        //sideline ticket information
        premium_price = inFile.nextDouble();
        premium_sold = inFile.nextDouble();
        //premium ticket information
        general_price = inFile.nextDouble();
        general_sold = inFile.nextDouble();
        //general ticket information
        
        box_total = (box_price * box_sold);
        sideline_total = (sideline_price * sideline_sold);
        premium_total = (premium_price * premium_sold);
        general_total = (general_price * general_sold);
        //calculating for the total price
        total_tickets = (box_sold + sideline_sold + premium_sold + general_sold);
        total = (box_total + sideline_total + premium_total + general_total);
        //calculating total tickets and the total sales amount
                
        System.out.printf("The total number of tickets sold is %.2f. The total amout from sales is $%.2f%n", total_tickets, total);//output of information
        
        inFile.close();//close file
    }
}
/*
run:
The total number of tickets sold is 88250.00. The total amout from sales is $6493750.00
BUILD SUCCESSFUL (total time: 0 seconds)

(in ticketdata.txt)
ticketPrice numberOfTicketsSold
250 5750
100 28000
50 35750
25 18750
*/
