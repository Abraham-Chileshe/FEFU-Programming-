#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000

int cmp_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, L;
    int a[MAX_N];
    FILE *in, *out;
    int i;

    in = fopen("input.txt", "r");
    if (in == NULL) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    fscanf(in, "%d %d", &n, &L);
    for (i = 0; i < n; i++) {
        fscanf(in, "%d", &a[i]);
    }
    fclose(in);

    /* Sort a in increasing order */
    qsort(a, n, sizeof(int), cmp_int);

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < a[i]) {
            time = a[i];
        }
        time += L;
    }


    out = fopen("output.txt", "w");
    if (out == NULL) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    fprintf(out, "%d\n", time);
    fclose(out);

    return 0;
}
