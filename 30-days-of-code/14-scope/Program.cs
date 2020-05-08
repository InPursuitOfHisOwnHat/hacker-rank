using System;

namespace scope
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] elements = {1,2,3,4,5};
            Difference d = new Difference(elements);
            d.computeDifference();
            Console.WriteLine("Largest difference: {0}", d.maximumDifference);
        }
    }
}
