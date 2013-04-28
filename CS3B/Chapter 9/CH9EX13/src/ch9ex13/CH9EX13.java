/*Name: Jonathan Chan
 *Program: Chapter-9 Exercise-13
 *Description:  This program creates an array of a class and prints out the data.
 */  
package ch9ex13;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Locale;
import java.util.Scanner;


public class CH9EX13
{
    public static void main(String[] args) throws FileNotFoundException
    {
        String firstN, lastN;
        double[] tests = new double[5];
        StudentGrades[] experiment = new StudentGrades[10];
        
        Scanner inFile = new Scanner(new FileReader("ch9_Ex13Data.txt"));
        while(inFile.hasNext())
        {
            for(int i = 0; i<10; i++)
            {
                firstN = inFile.next();
                lastN = inFile.next();
                for(int j=0; j<5; j++)
                {
                    tests[j] = inFile.nextDouble();
                }
                experiment[i] = new StudentGrades(firstN, lastN, tests);
            }             
        }
        inFile.close();
        System.out.println("First_Name  Last_Name   Test1  Test2  Test3  Test4  Test5  Average Grade");
        for(int i = 0; i<experiment.length; i++)
        {
            System.out.println(experiment[i]);
        }
    }
    public static class StudentGrades
    {
        private String first_name, last_name;
        private double average, test_scores[];
        private char grade;
        
        public StudentGrades()
        {
            first_name = "";
            last_name = "";
            average = 0;
            test_scores = new double[5];
            grade = '*';
        }
        public StudentGrades(String firstN, String lastN, double tests[])
        {
            first_name = firstN;
            last_name = lastN;
            test_scores = new double[5];
            for(int i=0; i<5; i++)
            {
                test_scores[i] = tests[i];
            }
            grade = studentsGrade(test_scores);
        }
         public void getScores(String firstN, String lastN, double tests[])
        {
            first_name = firstN;
            last_name = lastN;
            test_scores = new double[5];
            for(int i=0; i<5; i++)
            {
                test_scores[i] = tests[i];
            }
        }       
        private char studentsGrade(double test_scores[])
        {
            double sum = 0;
            
            for(int i=0; i < 5; i++)
            {
                sum += test_scores[i]; 
            }
            average = sum/5;
            
            if(average >= 90)
            {
                return('A');
            }
            else if(average >=80)
            {
                return('B');
            }
            else if(average >=70)
            {
                return('C');
            }                  
            else if(average >=60)
            {
                return('D');
            }
            else
            {
                return('F');
            }       
        }
        public String toString()
        {
            String str;
            
            str = String.format("%-11s %-10s", first_name, last_name);
            for(int i = 0; i < test_scores.length; i++)
            {
                str = str + String.format("%7.2f",test_scores[i]);
            }
            str = str + String.format("  %.2f",average);
            str = str + "     " + grade;

            return str;
        }
    }

}
