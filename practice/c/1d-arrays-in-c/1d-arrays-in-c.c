#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int number_of_items;
    scanf("%d",&number_of_items);
    int* arr = (int*)malloc(number_of_items * sizeof(int));

    for(int i=0; i<number_of_items; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    for(int j=0; j<number_of_items; j++) {
        sum += arr[j];
    }

    printf("%d", sum);
    return 0;
}
