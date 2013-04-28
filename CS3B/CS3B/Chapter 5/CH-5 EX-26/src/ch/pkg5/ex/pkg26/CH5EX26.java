/*Name: Jonathan Chan
 *Ex: Chapter 5 Exercice 26
 *Decription:   The inputs for the program is the radius of the wax paper.
 *              The outputs for the program are the maximum volume and the optimal sector length to remove to achieve that volume.
 *              The program itself first asks for the radius of the wax paper from the user using an option pane. 
 *              Then it parses that number and uses it to calculate the circumfrence of the circle to ensure the removed sector does not exceed the circumfrence using a while loop
 *              within the while loop it calculates the cup radius, cup height volume for each increment of sector length.
 *              If at any time in the while loop a the calculated volume exceeds the maximum value currently stored it writes the new volume and the sector length that it took to get that volume
 *              After it finishes the loop the program then outputs information on the maximum volume and the optimal sector length to remove to maximize volume.
 */
package ch.pkg5.ex.pkg26;
import java.util.*;
import java.math.*;
import javax.swing.*;

public class CH5EX26
{
    static Scanner console = new Scanner(System.in);    
    public static void main(String[] args)
    {
        String wax_paper_radius_string;//input for option pane
        double wax_paper_radius;//parsed radius from option pane
        double wax_paper_circumfrence;//circumfrence for calculating optimal sector size
        double cup_radius;//radius of the cup after removed sector length
        double cup_height;//the height of the cup
        double sector_length;//the sector length to be removed
        double optimal_sector_length;//to store the optimal sector length
        double volume;//the volume of the cup
        double max_volume;//to store the maximum volume of the cup
          
        wax_paper_radius_string = JOptionPane.showInputDialog("Please enter the radius of the wax paper in inches");
        wax_paper_radius = Double.parseDouble(wax_paper_radius_string);
        //getting the radius of the wax paper from the user
        
        max_volume = 0;
        sector_length = 0;//start at the minimum sector length
        optimal_sector_length = 0;
        //initializing variables
        wax_paper_circumfrence = (2 * Math.PI * wax_paper_radius);//calculations for circumfrence to get optimal sector length.
        
        while(sector_length <= wax_paper_circumfrence)//ensures the removed sector does not exceed the circumfrence
        {
          cup_radius = wax_paper_radius - (sector_length / (2*Math.PI));//calculates the radius of the cup
          cup_height = Math.sqrt(Math.pow(wax_paper_radius,2)-Math.pow(cup_radius,2));// calculates the height of the cup using pythagorean theorem
          volume = ((Math.PI * Math.pow(cup_radius,2) * cup_height)/3);//calculates the volume with the calculated variables with v=(pi*(r^2)*h)/3
                  
          if(max_volume < volume)//used to store the maximum volume and optimal sector length
          {
              max_volume = volume;//stores volume into max_volume if max volume was less than the calculated volume.
              optimal_sector_length = sector_length;//stores the optimal sector length when max volume is less than volume
          }
         
          sector_length = sector_length + .01;//used to increment sector length slowly up to the circumfence of the circle
        }
        System.out.printf("The maximum volume of the cup from the wax paper with radius " + wax_paper_radius + " inches is %.2f" + " inches cubed%n", max_volume);//outputs information about volume
        System.out.printf("The optimal sector length to remove is %.2f inches.%n", optimal_sector_length);//outputs the information on the optimal sector length to be removed for maximized volume.
    }
}
/*
run:
The maximum volume of the cup from the wax paper with radius 4.0 inches is 25.80 inches cubed
The optimal sector length to remove is 4.61 inches.
BUILD SUCCESSFUL (total time: 3 seconds)
 */