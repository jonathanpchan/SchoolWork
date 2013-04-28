package ch9.ex11;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class CH9EX11 extends JFrame
{
    private JLabel[] hightempL, lowtempL;
    private static JTextField[] hightempTF, lowtempTF;
    private JButton calculateB, exitB;//declaring the JButtons
    private CalculateButtonHandler cbHandler;//declaring the Calculate button handler
    private ExitButtonHandler ebHandler;//declaring the exit button handler
    
    public static void main(String[] args)
    {
        CH9EX11 average_temperature = new CH9EX11();
    }
    public static class temperature
    {   
        private int month;
        private double hightemp, lowtemp, temp, highindex = 0, lowindex = 99999, highavg = 0, lowavg = 0;
        private double[][] temperature = new double[12][2];
        
        public void getData()
        {
            for(int i = 0; i < 12; i++)
            {
                temperature[i][0] = Double.parseDouble(hightempTF[i].getText());
                temperature[i][1] = Double.parseDouble(lowtempTF[i].getText());    
            }   
        }
        public double averageHigh()
        {
            for(int i = 0; i < 12; i++)
            {
                highavg += temperature[i][0];
            }
            highavg /= 12;
            return(highavg);
            
        }
        public double averageLow()
        {
            for(int i = 0; i < 12; i++)
            {
                lowavg += temperature[i][1];
            }
            lowavg /= 12;  
            return(lowavg);
            
        }
        public double indexHighTemp()
        {
            for(int i = 0; i < 12; i++)
            {
                if(highindex < temperature[i][0])
                {
                    highindex = temperature[i][0];
                    temp = i;
                }     
            }
            return(temp);
        }
        public double indexLowTemp()
        {
            for(int i = 0; i < 12; i++)
            {
                if(lowindex > temperature[i][1])
                {
                    lowindex = temperature[i][1];
                    temp = i;
                }     
            }
            return(temp); 
        }  
    }
    public  CH9EX11()
    {
        hightempL = new JLabel[12];
        lowtempL = new JLabel[12];
        hightempTF = new JTextField[12];
        lowtempTF = new JTextField[12];
        
        for(int i = 0; i < 12; i++)
        {
            hightempL[i] = new JLabel("Month " + (i+1) + " High Temperature: ", SwingConstants.RIGHT);
            lowtempL[i] = new JLabel("Month " + (i+1) + " Low Temperature: ", SwingConstants.RIGHT);
            hightempTF[i] = new JTextField(10);
            lowtempTF[i] = new JTextField(10);       
        }

        calculateB = new JButton("Calculate");//creating the calculate button
        cbHandler = new CalculateButtonHandler();//creating the button handler
        calculateB.addActionListener(cbHandler);//adding the action listener to the button
        
        exitB = new JButton("Exit");//creating the exit button
        ebHandler = new ExitButtonHandler();//creating the button handler
        exitB.addActionListener(ebHandler);//adding the action listener to the button
        
        Container pane;//creating the container
        pane = getContentPane();//using getContentPane method
        pane.setLayout(new GridLayout(13, 4));//setting the layout for the program        
        
        for(int i = 0; i < 12; i++)//using a for loop to add the arrays to the pane
        {
            pane.add(hightempL[i]);
            pane.add(hightempTF[i]);
            pane.add(lowtempL[i]);
            pane.add(lowtempTF[i]);              
        }
        pane.add(exitB);
        pane.add(calculateB);
        
        setSize(660, 600);//setting the size
        setVisible(true);//setting visibility
        setTitle("Temperatures Over A Year");//setting the title
        setDefaultCloseOperation(EXIT_ON_CLOSE);//setting the default close operation        
    }
    private class CalculateButtonHandler implements ActionListener //code for the Calculate button handler
    {
        public void actionPerformed(ActionEvent e)//for the button click
        {
            double avgH, avgL, indexH, indexL;
            temperature avgtemp = new temperature();
            avgtemp.getData();
            avgH = avgtemp.averageHigh();
            avgL = avgtemp.averageLow();
            indexH = avgtemp.indexHighTemp();
            indexL = avgtemp.indexLowTemp();
            JOptionPane.showMessageDialog(null,"Average High Temperature: " + String.format("%.3f", avgH) +
                    "\nAverage Low Temperature: " + String.format("%.3f", avgL) +
                    "\nIndex of Highest Temperature: " + indexH +
                    "\n Index of Lowest Temperature: " + indexL, "test", JOptionPane.INFORMATION_MESSAGE);     
        }
    }    
    private class ExitButtonHandler implements ActionListener//code for the exit button handler
    {
        @Override
        public void actionPerformed(ActionEvent e)//for the button click
        {
            System.exit(0);//shuts down program when exit button is pressed
        }
    }    
}
