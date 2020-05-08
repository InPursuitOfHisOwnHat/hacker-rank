using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Solution {

    static void Main(String[] args) {
        string S = Console.ReadLine();
        try {
            int i = System.Convert.ToInt32(S);
            Console.WriteLine(i);
        }
        catch(Exception) {
            Console.WriteLine("Bad String");
        }

    }
}
