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

class Solution {



    static void Main(string[] args) {
        int[][] arr = new int[6][];

        for (int i = 0; i < 6; i++) {
            arr[i] = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
        }

        int arrLen = arr.Length;
        int topEdgeSum = 0;
        int bottomEdgeSum = 0;
        int middlePoint = 0;

        int currHourglassTotal = 0;

        // Uggh. Didn't read the question properly! Setting this to zero originally meant it didn't update with any negative numbers.
        //Instead constrainst say greater than -9.
        int currHourglassMax = int.MinValue;

        for( int y=0; y<arrLen; y++) {
            for (int x=0; x<arrLen; x++) {
                if ( arrLen - x >= 3 & arrLen - y >= 3) {
                    // We can build an array box in this space

                    //Console.WriteLine("Top Edge Coords: ({0},{1}), ({2},{3}), ({4},{5})", x,y, x+1, y, x+2, y);
                    topEdgeSum = (arr[y][x] + arr[y][x+1] + arr[y][x+2]);
                    //Console.WriteLine("Top Edge Sum: {0}", topEdgeSum);

                    bottomEdgeSum = (arr[y+2][x] + arr[y+2][x+1] + arr[y+2][x+2]);
                    //Console.WriteLine("Bottom Edge Sum: {0}", bottomEdgeSum);

                    middlePoint = arr[y+1][x+1];
                    //Console.WriteLine("Midpoint: {0}", middlePoint);

                    currHourglassTotal = topEdgeSum + bottomEdgeSum + middlePoint;
                    //Console.WriteLine("Total: {0}", currHourglassTotal);
                    if (currHourglassTotal > currHourglassMax) {
                        currHourglassMax = currHourglassTotal;
                    }

                }
            }
        }
        Console.WriteLine("{0}", currHourglassMax);
    }
}
  
