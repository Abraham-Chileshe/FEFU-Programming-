#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))

int main() {

    FILE * IN = fopen("input.txt", "r");
    FILE * OUT = fopen("output.txt", "w");

    long long N, R;
    long long middle;
    long long Zero = 0;
    long long * Spiral_line_arr;

    fscanf(IN, "%lld", &N);
    fscanf(IN, "%lld", &R);

    //Assignment operation
    Spiral_line_arr = (long long *) calloc(  N , sizeof (long long));
    middle = N / 2 + N % 2;
    //--------

    if (R <= middle){
        Spiral_line_arr[R - 1] = (N - (R - 1) * 2) * (N - (R - 1) * 2);
        for (long long i = max(Zero, R - 2); i <= N - R; i++)
            Spiral_line_arr[i] = Spiral_line_arr[R - 1] + (R - i - 1);
    }else{
        Spiral_line_arr[R - 1] = ((N - (R - 1) * 2 - 1) * (N - (R - 1) * 2 - 1) + 1);
        for (long long i = R - 2; i >= N - R; i--)
            Spiral_line_arr[i] = Spiral_line_arr[R - 1] - R + i + 1;
    }

    for (long long i = 0; i < middle; i++){
        if (Spiral_line_arr[i] != 0)
            break;
        else
            Spiral_line_arr[i] = (N - i * 2) * (N - i * 2) - ((N - i * 2) - 1) * 4 + R - 1 - i;
    }

    for (long long i = 0; i < middle; i++){
        if (Spiral_line_arr[N - 1 - i] != 0)
            break;
        else
            Spiral_line_arr[N - 1 - i] = (N - i * 2) * (N - i * 2) - (N - i * 2) - R + i + 2;
    }

    for (long long i = 0; i < N; i++)
        fprintf(OUT, "%lld ", Spiral_line_arr[i]);

    
    return 0;
}