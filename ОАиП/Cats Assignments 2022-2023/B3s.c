#include <stdio.h>

int main() {
    FILE *myfile;
    int N;
    int a;
    long long unsigned sum = 0;

    myfile = fopen("input.txt", "r");
    fscanf(myfile, "%d", &N);
    int arr[N];

    for (int i = 0; i < N; i++) {
        fscanf(myfile, "%d", &a);
        arr[i] = a;
        sum += a;

    }
    fclose(myfile);


    myfile = fopen("output.txt", "w");
    fprintf(myfile, "%llu", sum);
    fclose(myfile);

    
    return 0;
} 