using System;
using System.Linq;

class Difference {
    private int[] elements;
    public int maximumDifference;

    public Difference(int[] elements) {
        this.elements = elements;
        maximumDifference = 0;
    }

    public void computeDifference() {
        
        int arr_len = elements.Length;
        int curr_diff;

        for (int i=0; i<elements.Length; i++) {
            for (int j=0; j<elements.Length; j++) {
                curr_diff = Math.Abs(elements[i]-elements[j]);
                if (curr_diff > maximumDifference) {
                    maximumDifference = curr_diff;
                }
            }
        }

    }

} // End of Difference Class