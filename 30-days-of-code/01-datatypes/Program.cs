using System;
using System.Collections.Generic;
using System.IO;

namespace _01_datatypes {
    class Solution {
        static void Main(String[] args) {
            int i = 4;
            double d = 4.0;
            string s = "HackerRank ";

            
            // Declare second integer, double, and String variables.
            
            // Read and save an integer, double, and String to your variables.
            
            // Print the sum of both integer variables on a new line.
            
            // Print the sum of the double variables on a new line.
            
            // Concatenate and print the String variables on a new line
            // The 's' variable above should be printed first.

            int i2;
            double d2;
            string s2;

            Int32.TryParse(Console.ReadLine(), out i2);
            Double.TryParse(Console.ReadLine(), out d2);
            s2 = Console.ReadLine();

            Console.WriteLine(i + i2);
            Console.WriteLine(String.Format("{0:0.0}", d + d2));
            Console.WriteLine(s + s2);


        }
    }
}