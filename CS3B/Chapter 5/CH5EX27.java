/*Name: Jonathan Chan
 *Ex: Chapter
 *Description:  Inputs for this program include the number of apartments, the cost of rent per unit, the increase in rent which leads to vacancy, and the maitenence cost
 *              Outputs for this program include prompts the user provided data, the data they provide, and the optimal number of apartments, the rent that comes along with it and maximized profits
 *              This program calculates a maximized profits for an apartment complex. It prompts the user for the number of units, the cost per unit, the amount of increase that leads to vacancy and the maitenance fee
 *              After this it calculates each possibility using a while look for each variation of rented units/increased rent. Afterwards it outputs this data to the user.       
 */        
        
package ch.pkg5.ex.pkg27;

import java.util.*;
import javax.swing.*;

public class CH5EX27
 {
    static Scanner console = new Scanner(System.in);      
    public static void main(String[] args)
    {
        String number_of_apartments_string;
        String rent_per_unit_string;
        String vacancy_increase_string;
        String maintenance_cost_string;
        //option box strings
        double number_of_apartments;
        double rent_per_unit;
        double vacancy_increase;
        double maintenance_cost;
        //to parse doubles from the strings above
        double maximum_apartments;
        double vacant_units;        
        double rented_apartments;
        //used to help calculate the number of apartments
        double maximum_profit;
        double profit;
        //used for profit and to store maximum profit
        double maximum_rent;
        double increased_rent;
        //used to calculate the increasing rent

        number_of_apartments_string = JOptionPane.showInputDialog("Please enter the number of apartment units");
        number_of_apartments = Double.parseDouble(number_of_apartments_string);
        System.out.println("Number of apartments: " + number_of_apartments);
        //input for the number of apartments
        rent_per_unit_string = JOptionPane.showInputDialog("Please enter the cost of rent per unit where all units are occupied");
        rent_per_unit = Double.parseDouble(rent_per_unit_string);
        System.out.println("Rent per unit: $" + rent_per_unit);
        //input for the rent per unit
        vacancy_increase_string = JOptionPane.showInputDialog("Please enter the increase in rent that results in a vacant unit");
        vacancy_increase = Double.parseDouble(vacancy_increase_string);
        System.out.println("Increase per Vacant Unit: $" + vacancy_increase);
        //input for the cost it takes to create a vacancy 
        maintenance_cost_string = JOptionPane.showInputDialog("Please enter the cost of maintenance per unit");
        maintenance_cost = Double.parseDouble(maintenance_cost_string);
        System.out.println("Maintenance Costs: $" + maintenance_cost);
        //input for the maintenance costs
        maximum_apartments = 0;
        maximum_profit = 0;
        maximum_rent = 0;
        vacant_units = 0;
        //initializing variables 
        while(vacant_units <= number_of_apartments)//while look to calculate for each situation of apartment/rent cost
        {
            rented_apartments = (number_of_apartments - vacant_units);//numbering the current rented apartments
            increased_rent = (rent_per_unit + (vacant_units * vacancy_increase));//calculating the increasing rent cost
            profit = ((rented_apartments) * increased_rent)- ((rented_apartments) * maintenance_cost);//calculating the total profit after maintenance

            if(maximum_profit < profit)//if maximum profit is less than the current profit it resaves the values of apartments, profit and the amount of rent.
            {
                maximum_apartments = (rented_apartments);//maximized number of rented apartments
                maximum_profit = profit;//the maximized profit
                maximum_rent = rent_per_unit;//the optimal cost per unit
            }
            
            vacant_units = vacant_units + 1;//increment number of vacant units due to increased rent.
        }
        System.out.printf("Maximum profit occurs when you rent %.2f units at a cost of $%.2f per unit%n", maximum_apartments, maximum_rent);
        System.out.printf("The maximum profit is $%.2f%n", maximum_profit);
        //output of data, maximum apartments, maximum rent, and the maximum profit
    }
}
/*
run:
Number of apartments: 50.0
Rent per unit: $600.0
Increase per Vacant Unit: $40.0
Maintenance Costs: $27.0
Maximum profit occurs when you rent 32.00 units at a cost of $600.00 per unit
The maximum profit is $41376.00
BUILD SUCCESSFUL (total time: 7 seconds)
 */