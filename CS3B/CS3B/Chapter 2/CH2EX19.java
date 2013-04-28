/*Name: Jonathan Chan
 *Ex: Chapter 2 Exercice 19
 *Decription: The one input for the program is the amount of rice in pounds are in a single bag
 *            The output for this program is a prompt for the user to enter the weight of the bag and the amount of bags needed for a metric ton of rice
 *            The program simply grabs the input for the weight per bag of rice and divides it into a metric ton to get the amount of bags needed to have a metric ton of rice.
 */
package ch.pkg2.ex.pkg19;
import java.util.*;

public class CH2EX19
{
    static Scanner console = new Scanner(System.in);
    public static void main(String[] args)
    {
        final int METRIC_TON = 2205;//1 metric ton is 2205 pounds
        double ricebag_weight;//weight per bag of rice
        double bags_per_metric_ton;//bags per metric ton
        
        System.out.println("How many pounds of rice are in a single bag");
        ricebag_weight = console.nextDouble();//input for pounds in a bag
        
        bags_per_metric_ton = (METRIC_TON / ricebag_weight);//calculates how many bags needed for a metric ton of rice
        System.out.println("You need " + bags_per_metric_ton + " bags to have a metric ton of rice");//output of results
    }
}
/*
run:
How many pounds of rice are in a single bag
66
You need 33.40909090909091 bags to have a metric ton of rice
BUILD SUCCESSFUL (total time: 3 seconds)
*/