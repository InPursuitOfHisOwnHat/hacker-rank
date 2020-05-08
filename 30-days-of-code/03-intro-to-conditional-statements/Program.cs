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


namespace _03_intro_to_conditional_statements
{
    class Solution {

        static void Main(string[] args) {
            int N = Convert.ToInt32(Console.ReadLine());

            if (N % 2 == 0) {
                if ( N >= 2 & N <= 5) {
                    System.Console.WriteLine("Not Weird");
                }
                else if (N >= 6 & N <= 20) {
                    System.Console.WriteLine("Weird");
                }
                else {
                    System.Console.WriteLine("Not Weird");
                }
            }
            else {
                System.Console.WriteLine("Weird");
            }
        }

    }
}
