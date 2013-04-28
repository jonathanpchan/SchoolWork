/*Name: Jonathan Chan
 *Exercise: Chapter 6 Exercise 1
 *Description:  Inputs for this project include 4 test scores and the respecetive weights from textfields
 *              Outputs for this exercise is the weighted average from the 4 test scores and their respective weights
 *              This project is a GUI based weighed average calculator. It has labels to inform the user where to input the
 *              information. Then by pressing the calculate button it takes in the information in the textfields
 *              does the calculations and then places the results in another textfield.    
 */        
package ch.pkg6.ex.pkg1;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH6EX1 extends JFrame//creating the JFrame
{
    private JLabel[] testL, weightL;//declaring JLabel arrays
    private JLabel weighted_averageL; //declaring the other JLabel
    
    private JTextField[] testTF, weightTF;//declaring the JTextField arrays
    private JTextField weighted_averageTF;//declaring the other JTextField
            
    private JButton calculateB, exitB;//declaring the JButtons
    
    private CalculateButtonHandler cbHandler;//declaring the Calculate button handler
    private ExitButtonHandler ebHandler;//declaring the exit button handler
    
    public CH6EX1()
    {
        testL = new JLabel[4];
        weightL = new JLabel[4];
        //creating the JLabel arrays
        testTF = new JTextField[4];
        weightTF = new JTextField[4];
        //creating the JTextField arrays
        for(int i = 0; i<4; i++)//loop to create the individual JLabels and JTextFields
        {
            testL[i] = new JLabel("Enter Test Score " + (i+1) + ": ", SwingConstants.RIGHT);
            weightL[i] = new JLabel("Enter Weight " + (i+1) + ": ", SwingConstants.RIGHT);
            testTF[i] = new JTextField(10);
            weightTF[i] = new JTextField(10);            
        }
        weighted_averageL = new JLabel("Weighted Average: ",SwingConstants.RIGHT);
        weighted_averageTF = new JTextField(10);
        //creating the other Jlabel and JTextField
        
        calculateB = new JButton("Calculate");//creating the calculate button
        cbHandler = new CalculateButtonHandler();//creating the button handler
        calculateB.addActionListener(cbHandler);//adding the action listener to the button
        
        exitB = new JButton("Exit");//creating the exit button
        ebHandler = new ExitButtonHandler();//creating the button handler
        exitB.addActionListener(ebHandler);//adding the action listener to the button
        
        Container pane;//creating the container
        pane = getContentPane();//using getContentPane method
        pane.setLayout(new GridLayout(5, 4));//setting the layout for the program
        
        for(int i = 0; i < 4; i++)//using a for loop to add the arrays to the pane
        {
            pane.add(testL[i]);
            pane.add(testTF[i]);
            pane.add(weightL[i]);
            pane.add(weightTF[i]);              
        }            
        pane.add(exitB);
        pane.add(calculateB);
        //adding the buttons to the pane
        pane.add(weighted_averageL);
        pane.add(weighted_averageTF);
        //adding the last two fields to the pane
               
        setSize(600, 270);//setting the size
        setVisible(true);//setting visibility
        setTitle("Calculate The Weight Of Four Test Scores");//setting the title
        setDefaultCloseOperation(EXIT_ON_CLOSE);//setting the default close operation
    }
    private class CalculateButtonHandler implements ActionListener //code for the Calculate button handler
    {
        public void actionPerformed(ActionEvent e)//for the button click
        {
            double[] test, weight, average;//arrays to hold the inputted information
            double weighted_average = 0;//variable to hold information
            
            test = new double[4];
            weight = new double[4];
            average = new double[4];
            //creating the arrays to hold the information
            for(int i=0; i < 4; i++)//loop to calculate the information
            {
                test[i] = Double.parseDouble(testTF[i].getText());//parsing the test information
                weight[i] = Double.parseDouble(weightTF[i].getText());//parsing the weight information
                average[i] = test[i] * weight[i];//calculating the individual averages
                weighted_average += average[i];   //adding the averages together to get the weighted average
            }
            weighted_averageTF.setText("" + weighted_average + "%");//setting the information in the last pane
        }
    }
    private class ExitButtonHandler implements ActionListener//code for the exit button handler
    {
        public void actionPerformed(ActionEvent e)//for the button click
        {
            System.exit(0);//shuts down program when exit button is pressed
        }
    }      
    public static void main(String[] args)
    {
        CH6EX1 weighted_average = new CH6EX1();//creating the program
    }
}