using System;
using System.Collections.Generic;
using System.IO;

namespace _08_dictionaries_and_maps
{

    class Solution {
        static void Main(String[] args) {

            IDictionary<string, int> phonebook = new Dictionary<string, int>();
        
            int numberOfEntries = int.Parse(Console.ReadLine());

            for (int i=0; i<numberOfEntries; i++) {
                string[] entry = Console.ReadLine().Split(' ');
                phonebook.Add(new KeyValuePair<string,int>(entry[0], int.Parse(entry[1])));
            }

            string name;
            int result;
            while((name = Console.ReadLine()) != null) {
                if (phonebook.TryGetValue(name, out result)) {
                    Console.WriteLine("{0}={1}", name, result);
                }
                else {
                    Console.WriteLine("Not found");
                }
            }

        }
    }

}
