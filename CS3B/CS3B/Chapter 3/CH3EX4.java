/*Name: Jonathan Chan
 *Ex: Chapter 3 Exercice 4
 *Decription: Inputs for this program include the weight of a bag of fertilizer, the cost of that bag, and the area in square feet that it could cover
 *            Outputs of this program include The price per pound of fertilizer and the price to fertilize a quare foot of land.
 *            This program inistially had logic errors that required fixing for the output to be correct. It takes inputs of weight, area, and cost
 *            It calculates the price per pound of fertilizer and the price it costs to fertilize a square foot of land. It had errors in both
 *            the outputs that has now been corrected
 */
package ch.pkg3.ex.pkg4;
import java.util.*;
public class CH3EX4
{
    static Scanner console = new Scanner(System.in);
    public static void main(String[] args)
    {
        double cost;
        double area;
        
        double bagSize;
        
        System.out.print("Enter the amount of feterilizer, in pounds, in one bag: ");
        bagSize = console.nextDouble();
        System.out.println();//input for the weight
        
        System.out.print("Enter the cost of the " + bagSize + " pound fertilizer bag: ");
        cost = console.nextDouble();
        System.out.println();//input for the cost
    
        System.out.print("Enter the area, in square feet, that can be fertilized by one bag: ");
        area = console.nextDouble();
        System.out.println();// getting input for area
        
        System.out.printf("The cost of the fetilizer per pound is: " + "$%.2f%n", cost / bagSize);//This was the logic area it was previously bagSize / cost and not cost/bagsize as it should be
        System.out.printf("the cost of the fertilizing per square foot is: " + "$%.4f%n", cost / area);//This was the second logic area as it was area / cost and to get the correct measurement it should be cost / area
    }
}
/*
run:
Enter the amount of feterilizer, in pounds, in one bag: 100

Enter the cost of the 100.0 pound fertilizer bag: 50

Enter the area, in square feet, that can be fertilized by one bag: 200

The cost of the fetilizer per pound is: $0.50
the cost of the fertilizing per square foot is: $0.2500
BUILD SUCCESSFUL (total time: 10 seconds)
 */
