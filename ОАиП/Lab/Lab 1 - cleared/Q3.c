#include <stdio.h>
#include <math.h>

int main(){
    int N, k;
    int result = 0;

    printf("Enter N, k\n");
    scanf("%d", &N); //getting N
    scanf("%d", &k); //getting k

    for(int i = 1; i<=N; i++)
        result += pow(i,k);

    printf("%d", result);

    return 0;
}