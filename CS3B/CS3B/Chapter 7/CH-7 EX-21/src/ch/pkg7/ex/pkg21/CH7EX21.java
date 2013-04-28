/*Name: Jonathan Chan
 *Ex: Chapter
 *Description:  
 */        
        
package ch.pkg7.ex.pkg21;

import java.util.Scanner;

public class CH7EX21
 {
    public static void get_dimensions(double area)
    {
        double length = area;
        double width;
        double height;
        double volume;
        
        double max_length = 0;        
        double max_width = 0;  
        double max_height = 0;        
        double max_volume = 0;  
        
        for(double i=0; i<=area; i = i + .001)
        {  
            width = area/length;
            height = (((length+width)-Math.sqrt(Math.pow(length, 2)-(length*width)+Math.pow(width, 2)))/6);
            volume = ((length-(2*height))*(width-(2*height))*height);
            if(volume > max_volume)
            {
                max_volume = volume;
                max_width = width;
                max_length = length;
                max_height = height;
            }        
            length = length - .001;
        }
            System.out.printf("The length of the box should be %.3f units long%n", max_length);
            System.out.printf("The width of the box should be %.3f units long%n", max_width);
            System.out.printf("The removed sector should be of the box should be %.3f units long%n", max_height);
            System.out.printf("The maximum volume of the box is %.3f united cubed%n", max_volume);
    }    
    static Scanner console = new Scanner(System.in);      
    public static void main(String[] args)
    {
        double area;
        
        System.out.println("Please enter the area of the flat cardboard piece");
        area = console.nextDouble();
        
        get_dimensions(area);
    }

}
