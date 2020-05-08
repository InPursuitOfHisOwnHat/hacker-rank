using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

namespace _10_binary_numbers
{
    class Solution {
        static void Main(string[] args) {
            int n = Convert.ToInt32(Console.ReadLine());

            string binary_n = Convert.ToString(n, 2);

            int curr_consecutive_ones = 0;
            int max_consecutive_ones = 0;
            for (int i=0; i<binary_n.Length; i++) {
                if (binary_n[i].Equals('1')) {
                    curr_consecutive_ones++;
                    if (curr_consecutive_ones > max_consecutive_ones) {
                        max_consecutive_ones = curr_consecutive_ones;
                        }
                }
                else {
                    curr_consecutive_ones = 0;
                }
            }
            Console.WriteLine(max_consecutive_ones);
        }
    }

}
