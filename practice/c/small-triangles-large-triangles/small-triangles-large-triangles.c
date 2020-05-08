#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

//Ugh. It was the 2.0 converting everything to int - of course it was!
double volume(triangle tr) {
    double p = (tr.a + tr.b + tr.c) / 2.0f;
    double s = p * (p-tr.a) * (p-tr.b) * (p-tr.c);
    return sqrt(s);
}

void sort_by_area(triangle* tr, int n) {
    triangle temp;
    int a_index;
    int sorted = 0;

    while(sorted == 0) {
        sorted = 1;
        for (a_index=0; a_index<n-1; a_index++) {
            if (volume(tr[a_index]) > volume(tr[a_index+1])) {
                temp = tr[a_index+1];
                tr[a_index+1] = tr[a_index];
                tr[a_index] = temp;
                sorted = 0;
            }
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}