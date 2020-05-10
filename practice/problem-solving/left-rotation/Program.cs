using System;
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

namespace left_rotation
{

    // Works but needs speeding up,a according to HR!
    class Solution {

        static void Main(string[] args) {
            string[] nd = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nd[0]);

            int d = Convert.ToInt32(nd[1]);

            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp))
            ;

            // My Code
            int temp;
            int aLen = a.Length;
            for (int i=0; i<d; i++) {
                temp = a[0];
                for (int j=0; j<aLen-1; j++) {
                    a[j] = a[j+1];
                }
                a[aLen-1] = temp;
            }

            Console.WriteLine(string.Join(" ", a));

            // for(int k=0; k<aLen; k++) {
            //     Console.Write("{0} ", a[k]);
            // }
        }
    }


}
