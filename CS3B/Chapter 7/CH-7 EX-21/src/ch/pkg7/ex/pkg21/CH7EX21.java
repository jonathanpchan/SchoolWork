/*Name: Jonathan Chan
 *Program: Chapter-7 Exercise-21
 *Description:  Inputs for this program is an area of any rectangle.
 *              outputs for this program are the maximized volume, the dimensions to achieve the maximization and the height to remove to get that maximizaiton.
 *              This program takes in an area of any rectangle from the user. It then sets the length to the maximum possible(the area) and using a for loop we
 *              get the width by setting it equal to area/length. We decrement the length in the for loop to get all the possible dimensions
 *              the program calculates the maximized volume using a formula to get the maximized height to calculate the max possible volume for each dimension.
 *              it uses an if statement to rewrite variables of the calculated volume is greater than what is currently stored.
 *              After calculations are done it outputs the maximized volume, the length and width and the removed sector to get that maximized volume.   
 */        
        
package ch.pkg7.ex.pkg21;

import java.util.Scanner;//using scanner

public class CH7EX21
 {
    public static void maximize_volume(double area)//method to maximize the volume
    {
        double length = area;//setting one length to the maximum length possible for decrementing later.
        double width;//declaring width for now
        double height;//declaring the height or the length to be removed
        double volume;//used to hold volume temporarily
        
        //used to store the maximized variables
        double max_length = 0;         
        double max_width = 0;  
        double max_height = 0;        
        double max_volume = 0;  
        
        for(double i=0; i<=area; i = i + .001)//for loop to calculate each possible dimension
        {  
            width = area/length;//calculating width from the set length. Will always start at 1.
            height = (((length+width)-Math.sqrt(Math.pow(length, 2)-(length*width)+Math.pow(width, 2)))/6);//a maximized height formula for 
            volume = ((length-(2*height))*(width-(2*height))*height);//calculating the volume with all the variables
            if(volume > max_volume)//maximization if the calculated volume is greater than the current maximum volume values are rewritten
            {
                //rewriting variables if the if-statement is met.
                max_volume = volume;
                max_width = width;
                max_length = length;
                max_height = height;
            }        
            length = length - .001;//decrementing the length for calculatings
        }
            //outputting the information
            System.out.printf("The length of the box should be %.3f units long%n", max_length);
            System.out.printf("The width of the box should be %.3f units long%n", max_width);
            System.out.printf("The removed sector should be of the box should be %.3f units long%n", max_height);
            System.out.printf("The maximum volume of the box is %.3f united cubed%n", max_volume);
    }    
    static Scanner console = new Scanner(System.in);      
    public static void main(String[] args)
    {
        double area;//variable to get area from user
        
        System.out.println("Please enter the area of the flat cardboard piece");
        area = console.nextDouble();
        //getting the area of the rectangle from the user.
        
        maximize_volume(area);//method call to calculate and output.
    }

}
