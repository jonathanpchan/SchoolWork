/*______________________________________________________________________________
-
Programmer(s)  : David Murray, Ce Hui Li, Jon Chan
Project        : Chapter 9 Exercise 15 Extra Credit
Class          : CS 3B
Due            : 06/11/12
Description    : Demonstrate Java knowledge by making a checkers game
________________________________________________________________________________            
*/

package Aasds;

//import some nice stuff
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Aasds 
{

    public static void main(String[] args) 
    {
        //make gui
        checkGui goo = new checkGui();
    }
    
    //gui to handle game functions
    public static class checkGui extends JFrame
    {
        //member varibles
        private JButton[][] b;
        private buttonHandler h;
        
        
        checkGui()
        {
            
            //instantiate some objects
            h = new buttonHandler();

            b = new JButton[8][8];
            for(int i = 0; i < 8; i++)
                for(int j = 0; j < 8; j++)
                {
                    b[i][j] = new JButton();
                    b[i][j].addActionListener(h);
                    b[i][j].setOpaque(true);
                    b[i][j].setBorderPainted(false);
                }
            
            //color buttons
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j += 2)
                    b[i][j].setBackground(Color.black);
                for(int j = 1; j < 8; j += 2)
                    b[i][j].setBackground(Color.green);
                i++;
                for(int j = 0; j < 8; j += 2)
                    b[i][j].setBackground(Color.green);
                for(int j = 1; j < 8; j += 2)
                    b[i][j].setBackground(Color.black);
            }
            
            //set up the pane
            Container pane = getContentPane();
            pane.setLayout(new GridLayout(8, 8));
            for(int i = 0; i < 8; i++)
                for(int j = 0; j < 8; j++)
                    pane.add(b[i][j]);
            
           //add title to windoww    
            setTitle("Checkers for Computer Scientists v.7.0");                             
            setSize(600,600);                           //set window size
            setDefaultCloseOperation(EXIT_ON_CLOSE);    //give window a duration
            setVisible(true);                           //make it visible, lol
            setLocationRelativeTo(null);                //set it to center
             
        }
        
        //cool dude to handle button stuff
        private class buttonHandler implements ActionListener
        {
            //this is goint to be hard.
            public void actionPerformed(ActionEvent e)
            {
                
                ((JButton)e.getSource()).setBackground(Color.blue);
                //paint(getGraphics());
                repaint();
            }
        }
    }
}
