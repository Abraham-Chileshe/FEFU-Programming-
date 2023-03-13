#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return (*(long long *) a - *(long long *) b);
}

int main(){
    long long n, k;
    FILE *IN = fopen("game.in", "r");
    FILE *OUT = fopen("game.out", "w");

    fscanf(IN,"%llu %llu", &n, &k);
    long long *x = (long long *)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++)
        fscanf(IN,"%llu", &x[i]);

    qsort(x, n, sizeof(long long), comp);

    long long l = 1;
    for (; l < n && x[l] == x[l - 1]; l++);
    long long count = 0;
    for (long long number = x[0], unique = 0, doubles = 0, r = l, counta = l; l < n;) {
        long long upper_limit = number * k;
        for (; r < n && x[r] <= upper_limit; r++) {
            if (x[r] != x[r - 1])
                unique++;
            else if (x[r] != x[r - 2])
                doubles++;
        }

        count += unique * (unique - 1) * 3;
        count += doubles * 3;
        if (counta >= 2) {
            count += unique * 3;
            if (counta >= 3)
                count++;

        }

        number = x[l];
        for (l++, counta = 1; l < n && x[l] == x[l - 1]; l++, counta++);
        if (counta >= 2) {
            doubles--;
        }
        unique--;
    }
    if (x[n - 1] == x[n - 2] && x[n - 1] == x[n - 3])
        count++;

    fprintf(OUT,"%llu", count);

    return 0;
}