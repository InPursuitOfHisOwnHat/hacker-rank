using System;
using System.Collections.Generic;
using System.IO;

namespace _25_running_time_and_complexity
{
    class Solution {
    
        static bool isPrime(int n) {
            //Console.WriteLine("Checking {0}", n);

            if (n == 2) {
                return true;
            }

            if (n == 1 || n % 2 == 0) {
                return false;
            }

            for (int i=2; i*i<=n; i++) {
                if ( n % i == 0) {
                    return false;
                }
            }

            return true;
        }
  
        static List<int> loadInputFromFile(String filename) {
            
            List<int> numbers = new List<int>();

            foreach (string line in File.ReadLines(filename))
            {
                numbers.Add(Convert.ToInt32(line));
            }

            return numbers;
        }

        static void Main(String[] args) {
            
            //List<int> numbers = loadInputFromFile(@"./failing_test_input");
            //int n = numbers.Count;

            int n = Convert.ToInt32(Console.ReadLine());

            List<int> numbers = new List<int>();

            for (int i=0; i<n; i++) {
                numbers.Add(Convert.ToInt32(Console.ReadLine()));
            }

            bool prime = true;
            for(int i=0; i<n; i++) {
                if (isPrime(numbers[i])) {
                    Console.WriteLine("Prime");
                }
                else {
                    Console.WriteLine("Not prime");
                }
            }
        }
    }
}



