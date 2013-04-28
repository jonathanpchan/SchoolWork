/*Name: Jonathan Chan
 *Exercise: Chapter-6 Exercise-6
 *Description:  Inputs for this program include a string from the user
 *              outputs for this program include a converted string where lowercase letters are uppercase and vice versa
 *              The program is a GUI. It takes astring from the user and using a Char Ch to temporarily hold
 *              each char in a string so they can be converted seperately. The program checks if its lowercase
 *              if it is it changes the char to upper case and adds it to the string and vice versa
 *              if the character is something else it does nothing to it and just adds it to the end of the string
 */        
        
package ch.pkg6.ex.pkg6;

import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class CH6EX6 extends JFrame//creating the JFrame
 {
    private JLabel StrL, convertedL;//declaring JLabels
    
    private JTextField StrTF, convertedTF;//declaring the JTextfields
    
    private JButton convertB, exitB;//declaring the JButtons
    private ConvertButtonHandler cbHandler;//declaring the Convert Button Handler
    private ExitButtonHandler ebHandler;//declaring the Exit BUtton Handler
    
    public CH6EX6()
    {
        StrL = new JLabel("Please a string to be converted: ", SwingConstants.RIGHT);
        convertedL = new JLabel("This is your converted string: ", SwingConstants.RIGHT);
        //creating the JLabels        
        StrTF = new JTextField(10);
        convertedTF = new JTextField(10);
        //creating the JTextField        
        convertB = new JButton("Convert");//creating the Convert Button
        cbHandler = new ConvertButtonHandler();//creating the Convert Button Handler
        convertB.addActionListener(cbHandler);//adding a action listener to the Convert Button
        
        exitB = new JButton("Exit");//creating the Exit Button
        ebHandler = new ExitButtonHandler();//creating the Exit Button Handler
        exitB.addActionListener(ebHandler);//adding the action listener to the exit button
        
        Container pane;//creating the container
        pane = getContentPane();//using the getContentPane method
        pane.setLayout(new GridLayout(3,2));//setting the layout of the container
        
        pane.add(StrL);
        pane.add(StrTF);
        pane.add(convertedL);
        pane.add(convertedTF);
        //adding the lable and textfields to the pane
        
        pane.add(exitB);
        pane.add(convertB);
        //ading the buttons the container
        
        setDefaultCloseOperation(EXIT_ON_CLOSE);//setting the default close operation
        setSize(600, 150);//setting the size of the window
        setTitle("Convert Lowercase Characters In A String To Uppercase Characters And Vice Versa");//setting the title
        setVisible(true);//making everything visible
    }
    
    private class ConvertButtonHandler implements ActionListener//Code for the Convert Button Handler
    {
        @Override
        public void actionPerformed(ActionEvent e)//for when the button is pressed
        {
            char Ch;//Char to hold each char of the string in the loop
            String Str;//str for the user's input
            String Str_Converted = "";//string for the output
            
            Str = StrTF.getText();//getting the string from the user
            
            for(int i=0; i<Str.length(); i++)//loop to convert everything
            {
                Ch = Str.charAt(i);//used to handle each single char for the whole string
                if(Character.isLowerCase(Ch))//checks if the char is lower case
                {
                    Ch = Character.toUpperCase(Ch);//if it's lower case its made to upper case
                    Str_Converted = Str_Converted + Ch;//adds the converted character to the string
                }
                else if(Character.isUpperCase(Ch))//check if the char is uppercase
                {
                    Ch = Character.toLowerCase(Ch);//if its uppercase it makes the char lowercase
                    Str_Converted = Str_Converted + Ch;//adds the conveted char to the string
                }
                else//for all other characters
                {
                    Str_Converted = Str_Converted + Ch;//this adds the other characters to the string
                }				        
            }  
            convertedTF.setText("" + Str_Converted);//adding the full converted string to the text box
        }        
    }
    
    private class ExitButtonHandler implements ActionListener//Code for the Exit Button Handler
    {
        public void actionPerformed(ActionEvent e)//for when the button is pressed
        {
            System.exit(0);//exits when the button is pressed
        }
    }
    
    public static void main(String[] args)
    {
        CH6EX6 string_conversion = new CH6EX6();//creating the program
    }
}
