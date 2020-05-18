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


namespace _28_regex_patterns_and_intro_to_databases
{

    class Solution {

        static string gmailRegex = @"[a-z]@gmail\.com";
        static bool hasGmailAccount( string email) {
            Console.WriteLine("Checking {0}", email);
            Match match = Regex.Match(email, gmailRegex);
            Console.WriteLine("Match.Success:{0}", match.Success);
            return match.Success;
        }

        static void Main(string[] args) {
            int N = Convert.ToInt32(Console.ReadLine());

            ArrayList gmailAccounts = new ArrayList();

            for (int NItr = 0; NItr < N; NItr++) {
                string[] firstNameEmailID = Console.ReadLine().Split(' ');

                string firstName = firstNameEmailID[0];

                string emailID = firstNameEmailID[1];

                if (hasGmailAccount(emailID)) {
                    gmailAccounts.Add(firstName);
                }
            }

            gmailAccounts.Sort();
            foreach (string name in gmailAccounts) {
                Console.WriteLine("{0}", name);
            }
        }
    }
}
