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

namespace _29_bitwise_and
{
    class Solution {

        static void Main(string[] args) {
            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++) {
                string[] nk = Console.ReadLine().Split(' ');

                int n = Convert.ToInt32(nk[0]);

                int k = Convert.ToInt32(nk[1]);

                int currValue = 0;
                int maxPossValue = 0;
                for (int i=1; i<=n; i++) {
                    currValue = 0;
                    for (int j=i+1; j<=n; j++) {
                        currValue = i & j;
                        //Console.WriteLine("AND {0} & {1} = {2}",i, j, i & j);
                        //Console.WriteLine("CURR: {0}", currValue);
                        if ((currValue > maxPossValue) && currValue < k) {
                            //Console.WriteLine("{0} greater than {1}", currValue, maxPossValue);
                            maxPossValue = currValue;
                        }
                    }
                }
                Console.WriteLine("{0}", maxPossValue);
            }
        }
    }
}
