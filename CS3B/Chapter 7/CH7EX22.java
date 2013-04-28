/*Name: Jonathan Chan
 *Program: Chapter-7 Exercise-22
 *Description:  Inputs for this program are the width of the river, the distance to the power plant downstream, and the costs of installing cable underwate and overaland.
 *              The outputs for this program include the minimzied cost for installing cable, the length that you need install cable overland and underwater.
 *              This is a minimzation program to minimize cost of installing cable over a river and over some extra land. This program gets input from the user on the
 *              river width and the distance to the powerplant. and the cost of installing cable per foot in those repsective places. It uses a method to do calculations and output.
 *              It uses a while loop and increments the land remaining after land cable installation starting from 0. With that it calculates the water cable length using the pythagorean theorem
 *              and the land cable length by subtracting the land remaining from it. It then calculates the cost of the cabling. Using an if statement if the minimum cost is greater than the calculated cost
 *              then it rewrites the minimum cost the water cable length and the land cable length. After calculations are done it outputs the minimzed cost, and the length of the cabling underwater and overland to the user.
 */              
        
package ch.pkg7.ex.pkg22;

import java.util.Scanner;//using scanner


public class CH7EX22
 {
    public static void minimize_cost(double river_width, double land_length, double water_cost, double land_cost)//method to minimize the cost
    {
        double cost;//a temp variable for the cost
        double water_cable_length;//length of the cable underwater
        double land_cable_length;//length of the cable overland
        double possible_land_length = 0;//used to increment for the calculatings
                
        //used to convert the lengths to feet for calcualates
        double land_length_feet = land_length * 5280;
        double water_length_feet = river_width * 5280;
        
        //variables to hold minimized statistics
        double min_cost = 999999999;//set at this for minimization
        double min_water_length = 0;
        double min_land_length = 0;
               
        while(possible_land_length <= land_length_feet)//start from straight across the river and the whole land length.
        {
            water_cable_length = Math.sqrt((Math.pow(water_length_feet,2))+(Math.pow(possible_land_length, 2)));//calculates the amount of length of the river cabling needed
            land_cable_length = land_length_feet-possible_land_length;//the remaining land would be overland cabling
            
            cost = (water_cost*water_cable_length)+(land_cost*land_cable_length);//calculating cost from users input
            
            if(cost < min_cost)//if cost is less than the current minimum cost then we re-write variables
            {
                //setting the minimum cost, and the lengths needed to get that minimum
                min_cost = cost;
                min_water_length = water_cable_length;
                min_land_length = land_cable_length;
            }         
            possible_land_length = possible_land_length + 1;//incrementing per foot to get the minimzied cost
        }
        //outputting information back to the user.
        System.out.printf("The minimum cost to install power lines  is $%.3f%n", min_cost);//output cost
        System.out.printf("The length of cabling underwater is %.3f miles%n", min_water_length/5280);//output water cabling length
        System.out.printf("The length of cabling overland is %.3f miles%n", min_land_length/5280);//output land cabling length
    }
    static Scanner console = new Scanner(System.in);//scanner for input      
    public static void main(String[] args)
    {
        double river_width, land_length, water_cost, land_cost;//variables for the input from the user
        
        System.out.println("Please enter the width of the river in miles");
        river_width = console.nextDouble();
        //getting the width of the river
        System.out.println("Please enter the distance of factory downstream on the other side of the river in miles");
        land_length = console.nextDouble();                
        //getting the distance of the factory downstream
        System.out.println("Please enter the cost per foot of laying power line underwater");
        water_cost = console.nextDouble();
        //getting the cost of laying powerline underwater
        System.out.println("Please enter the cost per foot of laying power line over land");
        land_cost = console.nextDouble();
        //getting the cost of laying powerline overland.
        
        minimize_cost(river_width, land_length, water_cost, land_cost);//method call to calcualte and output.
    }
}
