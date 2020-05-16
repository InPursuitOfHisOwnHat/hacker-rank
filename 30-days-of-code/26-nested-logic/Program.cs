    using System;
    using System.Collections.Generic;
    using System.IO;

namespace _26_nested_logic
{

    class Solution {
        static void Main(String[] args) {
            /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */

            int fine = 0;

            String[] returnDateStr = Console.ReadLine().Split(' ');
            String[] dueDateStr = Console.ReadLine().Split(' ');

            DateTime returnDate = new DateTime(Convert.ToInt32(returnDateStr[2]), 
                                                Convert.ToInt32(returnDateStr[1]), 
                                                Convert.ToInt32(returnDateStr[0]));

            DateTime dueDate = new DateTime(Convert.ToInt32(dueDateStr[2]), 
                                                Convert.ToInt32(dueDateStr[1]), 
                                                Convert.ToInt32(dueDateStr[0]));

            int daysDifference = (int)(returnDate-dueDate).TotalDays;

            if (daysDifference > 0) {

                if (returnDate.Month == dueDate.Month & returnDate.Year == dueDate.Year) {
                    fine = 15 * daysDifference;
                }
                else if (returnDate.Month > dueDate.Month & returnDate.Year == dueDate.Year) {
                    int monthsLate = ((returnDate.Year - dueDate.Year) * 12) + returnDate.Month - dueDate.Month;
                    fine = 500 * monthsLate;
                }
                else if (returnDate.Year > dueDate.Year) {
                    fine = 10000;
                }
            }
            else {
                fine = 0;
            }
            Console.WriteLine("{0}", fine);
        }
    }
}
