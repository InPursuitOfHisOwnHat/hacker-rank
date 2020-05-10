using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace _20_sorting
{
    class Solution {

        static void Main(String[] args) {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] a_temp = Console.ReadLine().Split(' ');
            int[] a = Array.ConvertAll(a_temp,Int32.Parse);

            // Write Your Code Here

            int numberOfSwaps;
            int totalNumberOfSwaps = 0;
            int temp;

            do {
                numberOfSwaps = 0;
                for(int i=0; i<a.Length-1; i++) {
                    if (a[i] > a[i+1]) {
                        temp = a[i];
                        a[i] = a[i+1];
                        a[i+1] = temp;
                        numberOfSwaps++;
                    }
                }
                totalNumberOfSwaps+=numberOfSwaps;
            } while(numberOfSwaps > 0);

            Console.WriteLine("Array is sorted in {0} swaps.",totalNumberOfSwaps);
            Console.WriteLine("First Element: {0}", a[0]);
            Console.WriteLine("Last Element: {0}", a[a.Length-1]);
        }
    }
}
