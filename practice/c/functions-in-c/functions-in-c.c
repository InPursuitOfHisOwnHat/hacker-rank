#include <stdio.h>

int max_of_four(int a, int b, int c, int d) {

    int maxl, maxr;

    if ( a > b ) {
        maxl = a;
    }
    else {
        maxl = b;
    }

    if (c > d) {
        maxr = c;
    }
    else {
        maxr = d;
    }

    if (maxl > maxr) {
        return maxl;
    }
    else {
        return maxr;
    }
}


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
