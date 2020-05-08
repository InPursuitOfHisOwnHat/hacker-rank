using System;
using System.Collections.Generic;
using System.IO;

namespace _06_lets_review
{
    class Solution {
        static void Main(String[] args) {

            int numberOfTestCases = int.Parse(Console.ReadLine());
            for(int i=0; i<numberOfTestCases; i++) {
                string nextString = Console.ReadLine();
                for (int j=0; j<nextString.Length; j++) {
                    if (j % 2 == 0) {
                        Console.Write(nextString[j]);
                    }
                }
                Console.Write(" ");

                for (int k=0; k<nextString.Length; k++) {
                    if (k % 2 != 0) {
                        Console.Write(nextString[k]);
                    }
                }
                Console.WriteLine();
            }
        }
    }

}
