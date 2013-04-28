/*Name: Jonathan Chan
 *Ex: Chapter
 *Description:  
 */        
        
package ch.pkg7.ex.pkg22;

import java.util.Scanner;


public class CH7EX22
 {
    public static void minimize_cost(double river_width, double land_length, double water_cost, double land_cost)
    {
        double cost;
        double water_cable_length;//length of the cable underwater
        double land_cable_length;//length of the cable overland
        
        double possible_land_length = 0;
        double land_length_feet = land_length * 5280;
        double water_length_feet = river_width * 5280;
        
        double min_cost = 999999999;
        double min_water_length = 0;
        double min_land_length = 0;
        
        while(possible_land_length <= land_length_feet)
        {
            water_cable_length = Math.sqrt((Math.pow(water_length_feet,2))+(Math.pow(possible_land_length, 2)));
            land_cable_length = land_length_feet-possible_land_length;
            
            cost = (water_cost*water_cable_length)+(land_cost*land_cable_length);
            
            if(cost < min_cost)
            {
                min_cost = cost;
                min_water_length = water_cable_length;
                min_land_length = land_cable_length;
            }         
            possible_land_length++;
        }
        System.out.printf("The minimum cost to install power lines  is $%.3f%n", min_cost);
        System.out.printf("The length of cabling underwater is %.3f miles%n", min_water_length/5280);
        System.out.printf("The length of cabling overland is %.3f miles%n", min_land_length/5280);        
    }
    static Scanner console = new Scanner(System.in);      
    public static void main(String[] args)
    {
        double river_width, land_length, water_cost, land_cost;
        
        System.out.println("Please enter the width of the river in miles");
        river_width = console.nextDouble();
        System.out.println("Please enter the distance of factory downstream on the other side of the river in miles");
        land_length = console.nextDouble();                
        System.out.println("Please enter the cost per foot of laying power line underwater");
        water_cost = console.nextDouble();
        System.out.println("Please enter the cost per foot of laying power line over land");
        land_cost = console.nextDouble();    
        
        minimize_cost(river_width, land_length, water_cost, land_cost);
    }
}
