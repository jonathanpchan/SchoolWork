/*Name: Jonathan Chan
 *Ex: Chapter
 *Description:  The inputs for this program include the loan amount, the interest rate and the monthly payment
 *              The outputs for this program include a minimum payment before the user enters a monthly payment, an error message if monthly payment is less than the minimum payment
 *              this program also alerts the user if their final payment is greated than the remaining loan amount and outputs the amount. finally it outputs the user-submitted information
 *              and outputs the number of months it would take to pay off the entire loan, and the total amount of interest paid.
 *              This program recieves inputs of the loan and interest rate from the user via dialog boxes, then calculates a minimum payment
 *              after this the program prompts the user to enter his/her monthly payment. After this it starts to calculate the number of months it would take to pay off the loan
 *              If the monthly payment is less than the interest it gives an error message to the user stating that the loan cannot be paid off at the current rate
 *              otherwise, this program continues until the last payment. If the last payment is greater than the remaining loan, then it alerts the user with the amount that is remaining
 *              finally it tells the user how many months it would take to pay off the loan and how much interest was paid in the end.
 *              
 */

package ch.pkg5.ex.pkg20;

import java.util.*;
import javax.swing.*; 

public class CH5EX20
 {
    static Scanner console = new Scanner(System.in);    
    public static void main(String[] args)
    {         
        String loan_amount_string;//input for loan amount
        String interest_rate_string;//input for interest rate
        String monthly_payment_string;//interest for monthly payment
        //strings for dialog boxes
        double loan_amount;
        double interest_rate;
        double monthly_payment;
        //variables to parse the strings
        double monthly_interest_rate;//calculates the monthly interest rate
        double interest_amount;//calculates the interest amount per month
        double actual_payment;//calculates the remaining payment after interest
        double months;//used to count the number of months
        double initial_loan_amount;//used to store the initial loan amount.
        double total_interest_paid;//used to add all interest paid together
        
        loan_amount_string = JOptionPane.showInputDialog("Please enter the initial loan amount in dollars");
        loan_amount = Double.parseDouble(loan_amount_string);
        interest_rate_string = JOptionPane.showInputDialog("Please enter the annual interest rate");
        interest_rate = Double.parseDouble(interest_rate_string);
        //recieving input to calculate a minimum payment
        
        monthly_interest_rate = ((interest_rate/12)/100);
        interest_amount = (loan_amount * monthly_interest_rate);
        System.out.printf("Your minimum payment is $%.2f%n", interest_amount);
        //calculating the minumum payment and outputting it to the user
        
        monthly_payment_string = JOptionPane.showInputDialog("Please enter your monthly payment");
        monthly_payment = Double.parseDouble(monthly_payment_string);
        //recieving the monthly payment from the user
        
        initial_loan_amount = loan_amount;
        total_interest_paid = 0;
        months = 0;
        //initializing variables

        while(loan_amount > 0)//loop while loan is greater than 0
        {
            interest_amount = (loan_amount * monthly_interest_rate);//calculating interest per month
            actual_payment = (monthly_payment - interest_amount);//the actual amount subtracted from the remaining loan
            loan_amount = (loan_amount - actual_payment);//calculating the remaining loan amount
            total_interest_paid = (total_interest_paid + interest_amount);//adding interest to see how much interest is at the end
            
            if(monthly_payment <= interest_amount)//if monthly payment is less than or equal to the interest amount the loan cannot be paid off therefore error message is sent to the user.
            {
                JOptionPane.showMessageDialog(null, "Your monthly payment is less than or equal to the interest charged. This loan cannot be repaid at your current monthly payment.", "ERROR" ,JOptionPane.ERROR_MESSAGE);//error message about payment being too low
                break;//need to break so the rest of the output is not shown.
            }
            
            months = months + 1;//adding to months per loop before output of how many months it would take.

            if((monthly_payment > loan_amount) && (loan_amount > 0))//the user need not pay more than the remaining loan if the loan amount is less than the monthly payment so this alerts the user of the remaining balance.
            {
                System.out.println("Your monthly payment exceeds the remaining loan amount");
                System.out.printf("The remaining loan amount is %.2f%n", loan_amount);//output to tell user that their monthly payment exceeds the remaining loan amount.
            }
            if(loan_amount <= 0)//once the loan is less than or equal to 0 the loan is effectively paid off so we tell the user how many months it would to pay off their loan along with the total amount of interst paid.
            {
                System.out.println("With an initial loan of $" + initial_loan_amount + " an interest rate of " + interest_rate + "% and monthly payments of $" + monthly_payment);//output of user submitted information.
                System.out.println("It would take you " + months + " months to pay off your loan");//output of months
                System.out.printf("The total amount of interest paid is $%.2f%n", total_interest_paid);//output of total interest paid.
            }
        }
    }
}
/*SAMPLE OUTPUT
run:
Your minimum payment is $6.00
Your monthly payment exceeds the remaining loan amount
The remaining loan amount is 21.79
It would take you 46.0 months to pay off your loan
The total amount of interest paid is $146.92
BUILD SUCCESSFUL (total time: 6 seconds)
*/