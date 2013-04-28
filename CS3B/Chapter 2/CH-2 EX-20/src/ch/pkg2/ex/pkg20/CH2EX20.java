/*Name: Jonathan Chan
 *Ex: Chapter 2 Exercise 20
 *Description: Inputs for this project include shares sold, price per share(buy), and sell price per share.
 *             Outputs for the project include prompts for the user input, the amount invested into stocks.
 *             The total gain from service charges, the net change, and the amount you have after sales.
 *             This progam starts by prompting the user for input for shares sold, buy cost, sell price. 
 *             After input is given it calculates and outputs the total invested, total from selling, the service charge, net change and the amount left after sales.
 */
package ch.pkg2.ex.pkg20;
import java.util.*;
public class CH2EX20
{
    static Scanner console = new Scanner(System.in);
    public static void main(String[] args)
    {
        final double SERVICE_CHARGE = .015;
        double shares_sold;//shares sold
        double purchase_cost_share;//cost to buy per share
        double total_purchased;//total invested in shares
        double sell_price_share;//price shares sold at
        double total_sold;//total price sold at
        double total_service_charge;//total gain from service charge
        double net_change;//gain-investment
        double total_after_sales;//total after sales

        System.out.println("Please enter the number of shares sold");
        shares_sold = console.nextDouble();//input for shares sold
        System.out.println("Please enter the purchase price per share");
        purchase_cost_share = console.nextDouble();//input for cost to buy per share
        System.out.println("Please enter the selling price per share");
        sell_price_share = console.nextDouble();//input for selling price per share
        
        total_purchased = (shares_sold * purchase_cost_share);
        total_sold = (shares_sold * sell_price_share);
        total_service_charge = (SERVICE_CHARGE *(total_purchased + total_sold));
        net_change = (total_sold - total_purchased);
        total_after_sales = (net_change + total_purchased);
                
        System.out.println("The amount invested into stocks is $" + total_purchased);
        System.out.println("The total service charge is $" + total_service_charge);
        System.out.println("The net change is $" + net_change);
        System.out.println("The amount of money you have now is $" + total_after_sales);
               
    }
}
/*
run:
Please enter the number of shares sold
1000
Please enter the purchase price per share
50
Please enter the selling price per share
51
The amount invested into stocks is $50000.0
The total service charge is $1515.0
The net change is $1000.0
The amount of money you have now is $51000.0
BUILD SUCCESSFUL (total time: 9 seconds)
*/