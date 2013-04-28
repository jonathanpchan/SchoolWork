package mouseexample;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MouseExample extends JFrame implements MouseListener, MouseMotionListener
{
    private static int WIDTH = 350;
    private static int HEIGHT = 500;

         //GUI components
    private JLabel[] labelJL;

    public MouseExample()
    {
       setTitle("Mouse Events");
       Container pane  = getContentPane();
       setSize(WIDTH,HEIGHT);

       GridLayout gridMgr = new GridLayout(11, 1, 10, 10);
       pane.setLayout(gridMgr);

       labelJL = new JLabel[11];

       labelJL[0] = new JLabel("Mouse Clicked",SwingConstants.CENTER);
       labelJL[1] = new JLabel("Mouse Entered",SwingConstants.CENTER);
       labelJL[2] = new JLabel("Mouse Exited",SwingConstants.CENTER);
       labelJL[3] = new JLabel("Mouse Pressed",SwingConstants.CENTER);
       labelJL[4] = new JLabel("Mouse Released",SwingConstants.CENTER);
       labelJL[5] = new JLabel("Mouse Dragged",SwingConstants.CENTER);
       labelJL[6] = new JLabel("Mouse Moved",SwingConstants.CENTER);
       labelJL[7] = new JLabel("Key Pressed",SwingConstants.CENTER);
       labelJL[8] = new JLabel("Key Typed",SwingConstants.CENTER);
       labelJL[9] = new JLabel("Key Released",SwingConstants.CENTER);        
       labelJL[10] = new JLabel("",SwingConstants.CENTER);

       for (int i = 0; i < labelJL.length; i++)
       {
          labelJL[i].setForeground(Color.gray);
          pane.add(labelJL[i]);
       }

       pane.addMouseListener(this);
       pane.addMouseMotionListener(this);
       this.addKeyListener(new KeyAdapter()
       {
            public void keyPressed(KeyEvent e)
            {
                for (int i = 0; i < labelJL.length; i++)
                {
                    if (i == 7)
                    labelJL[i].setForeground(Color.ORANGE);
                    else
                    labelJL[i].setForeground(Color.gray);
                }
            }           
            public void keyReleased(KeyEvent e)
            {
                for (int i = 0; i < labelJL.length; i++)
                {
                    if (i == 8)
                    labelJL[i].setForeground(Color.black);
                    else
                    labelJL[i].setForeground(Color.gray);
                }
            }
            public void keyTyped(KeyEvent e)
            {
                for (int i = 0; i < labelJL.length; i++)
                {
                    if (i == 9)
                    labelJL[i].setForeground(Color.CYAN);
                    else
                    labelJL[i].setForeground(Color.gray);
                }
            }            

       });
       setVisible(true);
       setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public void mouseClicked(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
          if (i == 0)
             labelJL[i].setForeground(Color.yellow);
          else
             labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");

    }

    public void mouseEntered(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
           if (i == 1)
              labelJL[i].setForeground(Color.green);
           else
              labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");
    }

    public void mouseExited(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
           if (i == 2)
              labelJL[i].setForeground(Color.red);
           else
              labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");
    }

    public void mousePressed(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
           if (i == 3)
              labelJL[i].setForeground(Color.blue);
           else
              labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");
    }

    public void mouseReleased(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
           if (i == 4)
              labelJL[i].setForeground(Color.pink);
           else
              labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");
    }
    public void mouseDragged(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
           if (i == 5)
           {
              labelJL[i].setForeground(Color.black);
              labelJL[1].setForeground(Color.green);               
           }
           else
              labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");
   
    }
    public void mouseMoved(MouseEvent event)
    {
       for (int i = 0; i < labelJL.length; i++)
       {
           if (i == 6)
              labelJL[i].setForeground(Color.magenta);
           else
              labelJL[i].setForeground(Color.gray);
       }

       labelJL[10].setText("["+ event.getX() + "," + event.getY()+"]");
    }  
    public static void main(String[] args)
    {
        MouseExample flow = new MouseExample();
    }
}

