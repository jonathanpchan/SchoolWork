/*Name: Jonathan Chan
 *Ex: Chapter 2 Exercice 18
 *Decription: Inputs for the program are dimensions of the room, door, windows, shelf, paint cost and carpet cost.
 *            Outputs for the program are prompts for the individual dimensions and the costs for painting the walls, carpeting and total cost. 
 *            This program prompts the user for dimensions for a room, a door, two windows, a bookshelf and painting cost and carpeting cost.
 *            the program then takes these inputs and calculates paintable area and carpetable area, then calculates the cost to paint and to carpet the room.
 */
package ch.pkg2.ex.pkg18;
import java.util.*;
public class CH2EX18 
{
    static Scanner console = new Scanner(System.in);
    public static void main(String[] args)
    {
        double room_length;
        double room_width;
        double room_height;
        double wall_area;
        double carpet_area;
        //room dimensons
        double door_width;
        double door_height;
        double door_area;
        //door dimensions
        double window1_width;
        double window1_height;
        double window1_area;
        //window 1 dimensions
        double window2_width;
        double window2_height;
        double window2_area;
        //window 2 dimensions
        double shelf_width;
        double shelf_height;
        double shelf_area;
        //shelf dimensions
        double paint_cost;
        double paintable_area;
        double painted_cost;
        //cost to paint per sqft
        double carpet_cost;
        double carpeted_cost;       
        //cost to install carpet per sqft.
        double total_cost;
        //total cost
        
        System.out.println("Please enter in feet the length of the room");
        room_length = console.nextDouble();
        System.out.println("Please enter in feet the width of the room");
        room_width = console.nextDouble();
        System.out.println("Please enter in feet the height of the room");
        room_height = console.nextDouble();
        //input for room dimensions
        System.out.println("Please enter in feet the width of the door");
        door_width = console.nextDouble();
        System.out.println("Please enter in feet the height of the door");
        door_height = console.nextDouble();
        //input for door dimensions
        System.out.println("Please enter in feet the width of the first window");
        window1_width = console.nextDouble();
        System.out.println("Please enter in feet the height of the first window");
        window1_height = console.nextDouble();
        //input for the first window's dimensions
        System.out.println("Please enter in feet the width of the second window");
        window2_width = console.nextDouble();
        System.out.println("Please enter in feet the height of the second window");
        window2_height = console.nextDouble();
        //input for the second window's dimensions
        System.out.println("Please enter in feet the width of the bookshelf");
        shelf_width = console.nextDouble();
        System.out.println("Please enter in feet the height of the bookshelf");
        shelf_height = console.nextDouble();        
        //input for the bookshelf dimensions
        System.out.println("Please enter the cost, per square foot of painting the walls");
        paint_cost = console.nextDouble();
        //input for painting cost
        System.out.println("Please enter the cost, per square foot of installing the carpet");
        carpet_cost = console.nextDouble();
        //input for carpeting cost
        
        wall_area = ((2 * room_width * room_height)+(2 * room_length * room_height));//area of the four walls
        carpet_area  = (room_width * room_height);//area of the floor
        door_area = (door_width*door_height);//area of door
        window1_area = (window1_width * window1_height);//area of the first window
        window2_area = (window2_width * window2_height);//area of the second window
        shelf_area = (shelf_width * shelf_height);//area of the bookshelf
        paintable_area = (wall_area - door_area - window1_area - window2_area - shelf_area);//paintable area
        painted_cost = (paintable_area * paint_cost);//calculates cost for paint
        carpeted_cost = (carpet_area * carpet_cost);//calculates cost for carpet
        total_cost = (painted_cost + carpeted_cost);//calculates total cost
        //calculations
      
        System.out.println("The cost of painting the room is $" + painted_cost);
        System.out.println("The cost of carpeting the room is $" + carpeted_cost);
        System.out.println("The total cost paint and carpet is $" + total_cost);
    }
}
/*
run:
Please enter in feet the length of the room
10
Please enter in feet the width of the room
10
Please enter in feet the height of the room
10
Please enter in feet the width of the door
8
Please enter in feet the height of the door
4
Please enter in feet the width of the first window
3
Please enter in feet the height of the first window
3
Please enter in feet the width of the second window
3
Please enter in feet the height of the second window
3
Please enter in feet the width of the bookshelf
3
Please enter in feet the height of the bookshelf
3
Please enter the cost, per square foot of painting the walls
2
Please enter the cost, per square foot of installing the carpet
2
The cost of painting the room is $682.0
The cost of carpeting the room is $200.0
The total cost paint and carpet is $882.0
BUILD SUCCESSFUL (total time: 31 seconds)
*/