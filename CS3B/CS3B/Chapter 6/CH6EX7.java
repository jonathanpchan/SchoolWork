/*Name: Jonathan Chan
 *Exercise: Chapter-6 Exercise-7
 *Description:  Inputs for this program include a deposited amount, the number of year and the interest rate
 *              outputs for this program are the value of the certificate of deposit after the alloted time
 *              This program uses a gui to help calculate the value of a CD after the time inputted from the user
 *              It takes and uses the formula deposited*(1+rate/100)^years to calculate the vale of the CD after maturity
 *              after this it outputs the calculation to the user in another textfield.
 */  
package ch.pkg6.ex.pkg7;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class CH6EX7 extends JFrame
{
    private JLabel depositedL, yearsL, interest_rateL, CofDL;
    //declaring the JLabels
    private JTextField depositedTF, yearsTF, interest_rateTF, CofDTF;
    //declaring the JTextFields
    
    private JButton calculateB, exitB;//declaring the JButtons
    private CalculateButtonHandler cbHandler;//declaring the Calculate BUtton Handler
    private ExitButtonHandler ebHandler;//declaring the ExitBUtton Handler
        
    public CH6EX7()
    {
        depositedL = new JLabel("Please enter the amount deposited: ", SwingConstants.RIGHT);
        yearsL = new JLabel("Please enter the number of years: ", SwingConstants.RIGHT);
        interest_rateL = new JLabel("Please enter the interest rate: ", SwingConstants.RIGHT);
        CofDL = new JLabel("Amount of the Certificate of Deposit on Maturity: ", SwingConstants.RIGHT);
        //creating the JLables
        depositedTF = new JTextField(10);
        yearsTF = new JTextField(10);
        interest_rateTF = new JTextField(10);
        CofDTF = new JTextField(10);
        //creating the JTextFields
        
        calculateB = new JButton("Calculate");//creating Calculate Button   
        cbHandler = new CalculateButtonHandler();//creating the Calculate Button Handler
        calculateB.addActionListener(cbHandler);//adding the action listener for the button
        
        exitB = new JButton("Exit");//creating the exit button
        ebHandler = new ExitButtonHandler();//creaing the Exit BUtton Handler
        exitB.addActionListener(ebHandler);//adding the action listener for the exit button
        
        Container pane;//creating the container
        pane = getContentPane();//using getContentPane method
        pane.setLayout(new GridLayout(5,2));//setting the layout
        
        pane.add(depositedL);
        pane.add(depositedTF);
        pane.add(yearsL);
        pane.add(yearsTF);
        pane.add(interest_rateL);
        pane.add(interest_rateTF);
        pane.add(CofDL);
        pane.add(CofDTF);    
        //adding JLabels and JTextfields for the user's input and final output
        pane.add(exitB);
        pane.add(calculateB);
        //adding the buttons
                
        setTitle("Calculates The Amount Of A Certificate Of Deposit On Maturity");//setting the title
        setSize(600, 300);//setting the size
        setVisible(true);//making the program visible
        setDefaultCloseOperation(EXIT_ON_CLOSE);//setting default close operation
    }
    
    private class CalculateButtonHandler implements ActionListener//code for the Calculate Button Handler
    {
        public void actionPerformed(ActionEvent e)//for button click
        {
            double deposited, years, interest_rate, cofd;//variables to store inputted information
            
            deposited = Double.parseDouble(depositedTF.getText());//getting the amount depoisted
            years = Double.parseDouble(yearsTF.getText());//getting the number of years
            interest_rate = Double.parseDouble(interest_rateTF.getText());//getting the interest rate
            
            cofd = (float)(deposited * Math.pow(1 + (interest_rate/100),years));//calculating the CD after maturity
            CofDTF.setText("$" + cofd);//setting the calculated information intot he remaining textfield
        }          
    }
    private class ExitButtonHandler implements ActionListener//code for the exit button
    {
        public void actionPerformed(ActionEvent e)//for the button press
        {
            System.exit(0);//ends program when button is pressed
        }             
    }
    public static void main(String[] args)
    {
        CH6EX7 CoD = new CH6EX7();//creates the program
    }
}
