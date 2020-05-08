#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 1000

int main() {

    int freq[9];
    for(int j=0; j<=9; j++) {
        freq[j] =0;
    }

    char number[MAX_LEN];
    scanf("%s", number);
    int number_len = strlen(number);
    
    int freq_index;
    for(int i=0; i<number_len; i++) {
        if (number[i] >= '0' && number[i] <= '9') {
            freq_index = ((int)number[i]) - (int)'0';
            freq[freq_index]++;
        } 
    }

    for(int k=0; k<=9; k++) {
        printf("%d ", freq[k]);
    }
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
