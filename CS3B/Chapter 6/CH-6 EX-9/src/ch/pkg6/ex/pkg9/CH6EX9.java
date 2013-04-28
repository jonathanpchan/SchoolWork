/*Name: Jonathan Chan
 *Ex: Chapter-6 Exercise-9
 *Description:  inputs from the user include a number, the base that number is in and a base to convert it to
 *              outputs for this program is the converted number from the base the number was in to the base the user wants it in.
 *              this program uses a GUI. It takes a positive number from a user and the base that number is in and a base he wants the number converted to
 *              this program parses the numbers from the program into an array and using calculations from the book converts it once
 *              then using that number it does secondary operations to get the converted base and adds it to a string to be outputted to the user.             
 */        
        
package ch.pkg6.ex.pkg9;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CH6EX9 extends JFrame//creating the JFrame
{
    private JLabel numberL, base1L, base2L, answerL;//declaring the JLabels
    private JTextField numberTF, base1TF, base2TF, answerTF;//declaring the JTextFields
    private JButton calculateB, exitB;//declaring the JButtons    
    private CalculateButtonHandler cbHandler;//declaring the Calculate Button Handler
    private ExitButtonHandler ebHandler;//delcaring the Exit Button Handler
    
    public CH6EX9()
    {
        numberL = new JLabel("Please enter a positive number: ", SwingConstants.RIGHT);
        base1L = new JLabel("Enter the base of that number(2-10): ", SwingConstants.RIGHT);
        base2L = new JLabel("Enter the base that you want the number in(2-10): ", SwingConstants.RIGHT);
        answerL = new JLabel("The converted number is : ", SwingConstants.RIGHT);
        //creating the JLabels
        numberTF = new JTextField(10);
        base1TF = new JTextField(10);
        base2TF = new JTextField(10);
        answerTF = new JTextField(10);
        answerTF.setEditable(false);
        //creating the JTextFields
        calculateB = new JButton("Calculate");//creating the Calculate Button
        cbHandler = new CalculateButtonHandler();//creating the Calculate Button Handler
        calculateB.addActionListener(cbHandler);//adding the action listener to the button
        
        exitB = new JButton("Exit");//creating the exit button
        ebHandler = new ExitButtonHandler();//creating the exit button handler
        exitB.addActionListener(ebHandler);//adding the action listener to the button
        
        Container pane;//creating the container
        pane = getContentPane();//using get contentpane method
        pane.setLayout(new GridLayout(5,2));//setting the layout of the program
        
        pane.add(numberL);
        pane.add(numberTF);
        pane.add(base1L);
        pane.add(base1TF);
        pane.add(base2L);
        pane.add(base2TF);
        pane.add(answerL);
        pane.add(answerTF);
        pane.add(calculateB);
        pane.add(exitB);
        //creating the layout of the program        
        setTitle("Convert Numbers From One Base To Another");//setting the title
        setSize(650,300);//setting the size of the window
        setVisible(true);//setting visibility 
        setDefaultCloseOperation(EXIT_ON_CLOSE);//setting default close operation
    }
    private class CalculateButtonHandler implements ActionListener//code for the calculate button
    {
        public void actionPerformed(ActionEvent e)//calculates when button is pressed
        {
            int number, length, second_conversion;//number is for the input from the user length is for the length of the number string and second conversion is for the final conversion
            int[] parsed_numbers;//an array for the parsed numbers
            double base1, base2, first_conversion = 0;//base1 is for the base the number is in, base2 is the base the user wants it converted to, first conversion is for the first conversion.
            String converted="";//strings for the length of the number input from the user and the final output.
            String number_length, base1str, base2str;
            boolean  numberbool, base1bool, base2bool;
            char Ch;
            
           
            number_length = (numberTF.getText());//parsing the number as a string so I can get the length
            numberbool = is_numeric(number_length);
            base1str = (base1TF.getText());
            base1bool = is_numeric(base1str);
            base2str = (base2TF.getText());
            base2bool = is_numeric(base2str);
                    
            length = number_length.length();//setting the length of the number
            parsed_numbers = new int[length];//creating the array for parsed numbers
            
  
            if(numberbool == false || base1bool == false || base2bool == false)
            {
                JOptionPane.showMessageDialog(null,"Error Text Entered. The Entry fields must be positive numbers.", "ERROR",JOptionPane.ERROR_MESSAGE);                
            }  
            else
            {
                number = Integer.parseInt(numberTF.getText());//paring the number to an an integer
                base1 = Integer.parseInt(base1TF.getText());//parsing the base the number is in
                base2 = Integer.parseInt(base2TF.getText());//parsing the base the user wants the number converted to
                
                if(number < 0 || base1 <=1 || base2 <= 1 || base1 >10 || base2 > 10)
                {
                    JOptionPane.showMessageDialog(null,"Error In Input. The Number Entered Must Be postive. The Bases Must be 2-10", "ERROR",JOptionPane.ERROR_MESSAGE);                    
                }
                else
                {
                    for(int i=0; i < length; i++)//loop to parse the numbers
                    {
                        parsed_numbers[i] = (number % 10);//numbers are parsed starting with the 1's digit
                        number = number / 10;//number is divided by 10 to reduce it
                    }
                    for(int i=0; i < length; i++)
                    {
                        first_conversion = first_conversion + (parsed_numbers[i]*Math.pow(base1, i));//using calulations from the book does an original conversion               
                    }
                    while(first_conversion > 0)//for the second conversion
                    {
                        second_conversion = (int)(first_conversion % base2);//calculations from the book to convert it to the next base
                        first_conversion = (int)(first_conversion / base2);//to keep up with the calculatings
                        converted = Integer.toString(second_conversion) + converted;//numbers are found backwards so string is used and characters are added to the start of the string.
                    }    
                    answerTF.setText("" + converted);
                }
            }
        }
    }
    private class ExitButtonHandler implements ActionListener//code for the exit button
    {
        public void actionPerformed(ActionEvent e)//for when button is clicked
        {
            System.exit(0);//exits the program when the button is pressed
        }
    }
    public static boolean is_numeric(String Str)
    {
        char Ch;
        for(int i = 0; i < Str.length(); i++)
        {    
            Ch = Str.charAt(i);
            if(!Character.isDigit(Ch))
            {
                return false;
            }
        }
        return true;
    }
            
    public static void main(String[] args)
    {
        CH6EX9 change_of_base = new CH6EX9();//creates the program    
    }
}