
package checkers.v2;

import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class CheckersV2 
{
    public static void main(String[] args) 
    {
        // TODO code application logic here
        CheckGui test = new CheckGui();
    }
    
    public static class Piece
    {
        //member variables
        private Boolean pawn, king;
        private String color;
        private int direction;
        
        //constructor
        public Piece()
        {
            //set some default values
            pawn = false;
            king = false;
            direction = 0;
            color = "";
        }
        
        //copy constructor
        public Piece(Piece other)
        {
            copyPiece(other);
        }
        
        //copy a piece
        public void copyPiece(Piece other)
        {
            //set to other
            pawn = other.pawn;
            king = other.king;
            direction = other.direction;
            color = other.color;
        }
        
        public void killPiece()
        {
            
            //set some default values
            pawn = false;
            king = false;
            direction = 0;
            color = "";
        }
        
        //set color from string
        public void setColor(String x)
        {
            color = x;
        }
        
        //return value
        public Boolean isPawn()
        {
            return pawn;
        }
        
        //sets king to false
        public void setPawn()
        {
            pawn = true;
        }
        
        //returns king
        public Boolean isKing()
        {
            return king;
        }
        
        //set king to true
        public void setKing()
        {
            king = true;
        }
        
        //return direction
        public int getDirection()
        {
            return direction;
        }
        
        //set direction to given value
        public void setDirection(int x)
        {
            direction = x;
        }
        
        public Boolean isPiece()
        {
            return pawn || king;
        }
    }
    
    public static class Board
    {
        //member variables
        public Piece checkerBoard[][];
        private double timer;
        private final int INDEX1 = 8, INDEX2 = 8;
        
        //default constructor
        public Board()
        {
            //instantiate checker board
            checkerBoard = new Piece[INDEX1][INDEX2];
            for(int i = 0; i < INDEX1; i++)
                for(int j = 0; j < INDEX2; j++)
                    checkerBoard[i][j] = new Piece();
            
            //set timer to zero
            timer = 0;
            
            checkerBoard[0][1].setPawn();
            checkerBoard[0][3].setPawn();
            checkerBoard[0][5].setPawn();
            checkerBoard[0][7].setPawn();
            checkerBoard[1][0].setPawn();
            checkerBoard[1][2].setPawn();
            checkerBoard[1][4].setPawn();
            checkerBoard[1][6].setPawn();
            checkerBoard[2][1].setPawn();
            checkerBoard[2][3].setPawn();
            checkerBoard[2][5].setPawn();
            checkerBoard[2][7].setPawn();
            
            checkerBoard[0][1].setDirection(1);
            checkerBoard[0][3].setDirection(1);
            checkerBoard[0][5].setDirection(1);
            checkerBoard[0][7].setDirection(1);
            checkerBoard[1][0].setDirection(1);
            checkerBoard[1][2].setDirection(1);
            checkerBoard[1][4].setDirection(1);
            checkerBoard[1][6].setDirection(1);
            checkerBoard[2][1].setDirection(1);
            checkerBoard[2][3].setDirection(1);
            checkerBoard[2][5].setDirection(1);
            checkerBoard[2][7].setDirection(1);

            checkerBoard[5][0].setPawn();
            checkerBoard[5][2].setPawn();
            checkerBoard[5][4].setPawn();
            checkerBoard[5][6].setPawn();
            checkerBoard[6][1].setPawn();
            checkerBoard[6][3].setPawn();
            checkerBoard[6][5].setPawn();
            checkerBoard[6][7].setPawn();
            checkerBoard[7][0].setPawn();
            checkerBoard[7][2].setPawn();
            checkerBoard[7][4].setPawn();
            checkerBoard[7][6].setPawn();
            
            checkerBoard[5][0].setDirection(0);
            checkerBoard[5][2].setDirection(0);
            checkerBoard[5][4].setDirection(0);
            checkerBoard[5][6].setDirection(0);
            checkerBoard[6][1].setDirection(0);
            checkerBoard[6][3].setDirection(0);
            checkerBoard[6][5].setDirection(0);
            checkerBoard[6][7].setDirection(0);
            checkerBoard[7][0].setDirection(0);
            checkerBoard[7][2].setDirection(0);
            checkerBoard[7][4].setDirection(0);
            checkerBoard[7][6].setDirection(0);
        }
        
        //copy constructor
        public Board(Board other)
        {
            //go through and copy from other array
            for(int i = 0; i < INDEX1; i++)
                for(int j = 0; j < INDEX2; j++)
                    checkerBoard[i][j] = other.checkerBoard[i][j];
        }
        
        //retrieve time from timer
        public double getTime()
        {
            return timer;
        }
        
        //update timer
        public void updateTimer()
        {
            timer++;
        }
        
        //is a move valid
        public Boolean isValidMove(int x1, int y1, int x2, int y2)
        {
            if(checkerBoard[x1][y1].isPiece())
                if(checkerBoard[x1][y1].isPawn())
                {
                    if(checkerBoard[x1][y1].getDirection() == 1)
                    {
                        if(x1 < x2)
                        {
                            if(((x2 - x1) == 1) 
                                    && !checkerBoard[x2][y2].isPiece())
                                return true;
                            if(y1 > y2)
                                if(((x2 - x1) == 2)
                                    && checkerBoard[x2--][y2--].isPiece() 
                                    && !checkerBoard[x2][y2].isPiece())
                                return true;
                            if(y1 < y2)
                                if(((x2 - x1) == 2)
                                    && checkerBoard[x2--][y2++].isPiece() 
                                    && !checkerBoard[x2][y2].isPiece())
                                return true;
                        }
                    }
                    else if(checkerBoard[x1][y1].getDirection() == 0)
                    {
                        if(x1 > x2)
                        {
                            if(((x1 - x2) == 1) 
                                    && !checkerBoard[x2][y2].isPiece())
                                return true;
                            if(y1 > y2)
                                if(((x1 - x2) == 2)
                                    && checkerBoard[x2--][y2--].isPiece() 
                                    && !checkerBoard[x2][y2].isPiece())
                                return true;
                            if(y1 > y2)
                                if(((x1 - x2) == 2)
                                    && checkerBoard[x2--][y2++].isPiece() 
                                    && !checkerBoard[x2][y2].isPiece())
                                return true;
                        }
                    } 
                        
                }
                        else
                            return false;
            
                          
            return false;
        }
        
        //move piece
        public void movePiece(int x1, int y1, int x2, int y2)
        {
            checkerBoard[x2][y2].copyPiece(checkerBoard[x1][y1]);
            checkerBoard[x1][y1].killPiece();
        }
        
        //print board, for debugging
        public String printBoard()
        {
            String foo = "";
            for(int i = 0; i < INDEX1; i++)
            {
                for(int j = 0; j < INDEX2; j++)
                {
                    foo += checkerBoard[i][j].isPiece() + "   ";
                }
                foo += '\n';
            }
            return foo;
        }
    }
    
    public static class Player
    {
        //member variables
        private String name;
        private double score;
        private Boolean turn;
        
        //constructor
        public Player()
        {
            //set values to null esque
            name = "";
            score = 0;
            turn = false;
        }
        
        //copy constructor
        public Player(Player other)
        {
            //set to other values
            name = other.name;
            score = other.score;
            turn = other.turn;
        }
        
        //get name of player
        public String getName()
        {
            return name;
        }
        
        //set name
        public void setName(String x)
        {
            name = x;
        }
        
        //get score
        public double getScore()
        {
            return score;
        }
        
        //increment score
        public void incScore()
        {
            score++;
        }
        
        //add to score
        public void scorePlus(double x)
        {
            score += x;
        }
        
        //set turn
        public void setTurn(Boolean x)
        {
            turn = x;
        }
    }
    
    //gui to handle game functions
    public static class CheckGui extends JFrame
    {
        //member varibles
        private JButton[][] b;
        private buttonHandler h;
        private Boolean click;
        private int index[];
        private Board board;
        
        
        CheckGui()
        {
            
            //instantiate some objects
            h = new buttonHandler();
            click = false;
            index = new int[2];
            board = new Board();

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
            fillBoard();
             
        }
        
        public void fillBoard()
        {
            b[0][1].setText("red");
            b[0][3].setText("red");
            b[0][5].setText("red");
            b[0][7].setText("red");
            b[1][0].setText("red");
            b[1][2].setText("red");
            b[1][4].setText("red");
            b[1][6].setText("red");
            b[2][1].setText("red");
            b[2][3].setText("red");
            b[2][5].setText("red");
            b[2][7].setText("red");
            
            b[5][0].setText("black");
            b[5][2].setText("black");
            b[5][4].setText("black");
            b[5][6].setText("black");
            b[6][1].setText("black");
            b[6][3].setText("black");
            b[6][5].setText("black");
            b[6][7].setText("black");
            b[7][0].setText("black");
            b[7][2].setText("black");
            b[7][4].setText("black");
            b[7][6].setText("black");
            
            
            
            
        }
        
        //cool dude to handle button stuff
        private class buttonHandler implements ActionListener
        {
            //this is goint to be hard.
            public void actionPerformed(ActionEvent e)
            {
                Object foo = e.getSource();
                if(click)
                {
                    for(int i = 0; i < 8; i++)
                        for(int j = 0; j < 8; j++)
                            if(b[i][j] == foo)
                            {
                                if(board.isValidMove(index[0], index[1], i, j))
                                {
                                    board.movePiece(index[0], index[1], i, j);
                                    b[i][j].setText(b[index[0]][index[1]].getText());
                                    b[index[0]][index[1]].setText("");
                                    
                                }
                            }
                    ;
                    click = false;
                }
                else
                {
                    for(int i = 0; i < 8; i++)
                        for(int j = 0; j < 8; j++)
                            if(b[i][j] == foo)
                            {
                                index[0] = i;
                                index[1] = j;
                            }
                    click = true;
                }
                            
                System.out.println(board.printBoard());
                //((JButton)e.getSource()).setBackground(Color.blue);
                //paint(getGraphics());
                repaint();
            }
        }
    }
}

/*
 * 
 */