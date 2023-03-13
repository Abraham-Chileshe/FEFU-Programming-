#include <stdio.h>

int a[1000005];
int p_sum[1000005];

int main(){
    int N, k;
    p_sum[0] = 0;

    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");


    fscanf(IN, "%d", &N);
    for(int i = 1; i <= N; i++){
        fscanf(IN, "%d", &a[i]);
        p_sum[i] = p_sum[i-1] + a[i];
    }



    fscanf(IN, "%d", &k);
    for(int i = 0; i < k; i++){
        int l, r;
        fscanf(IN, "%d %d", &l, &r);
        fprintf(OUT, "%d ", p_sum[r] - p_sum[l-1]);
    }
}