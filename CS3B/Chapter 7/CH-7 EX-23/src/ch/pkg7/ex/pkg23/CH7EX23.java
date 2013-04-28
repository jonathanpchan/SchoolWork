/*Name: Jonathan Chan
 *Program: Chapter-7 Exercise-23 
 *Description:  Inputs for this program are simple just the widths of two hallways
 *              The Output for this program is the maximum pipe length you can carry through the two hallways
 *              This program calculates the maximum pipe length that you can carry through two hallways with the widths provided by the user.
 *              It uses a for loop that increments theta and calculates two parts of the pipe and adds them together to get the total length
 *              In reality it isn't a maximization problem but a minimzation problem. So if the calculation is less than the current "max" the
 *              max is set to the current pipe length.
 */        
        
package ch.pkg7.ex.pkg23;

import java.util.Scanner;//using scanner.

public class CH7EX23
 {
    public static void pipe_length(double hallway_width_1, double hallway_width_2)//method taking in two hallway widths
    {
        double pipe_length;//to calculate the pipe length
        double max_pipe_length = 999999999;//set at this number to minimize
        
        for(double theta = .01; theta < (Math.PI/2);theta = theta + .01)//loop to calculate the "Maximum pipe length" for each increment of theta
        {
            pipe_length = (((hallway_width_1)/Math.sin(theta))+((hallway_width_2)/Math.cos(theta)));//calculates the length of the pipe
            if(pipe_length < max_pipe_length)//in reality it's a minimization problem. so used to set the "maximum pipe length"
            {
                max_pipe_length = pipe_length;//setting the maximum length possible to carry through the hallways
            }
        }
        System.out.printf("The Maximum Length of the pipe you can carry through hallways with widths %.0f feet and %.0f feet is %.0f feet long.%n",hallway_width_1, hallway_width_2, max_pipe_length);
        //formatting and outputting the maximum pipe length.
    }
    static Scanner console = new Scanner(System.in);//scanner to take in user input      
    public static void main(String[] args)
    {
        double hallway1, hallway2;//to set the hallway lengths
        System.out.println("Please enter the width of the first hallway.");
        hallway1 = console.nextDouble();
        //asking for and taking the first hallway width
        System.out.println("Please enter the width of the second hallway.");
        hallway2 = console.nextDouble();
        //asking for and taking the second hallway width
        pipe_length(hallway1, hallway2);//method call to calculate and output   
    }
}
