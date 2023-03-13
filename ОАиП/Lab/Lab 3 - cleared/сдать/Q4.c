#include <stdio.h>

int main() {
    int N;
    int count = 0;

    printf("Enter size of Array: ");
    scanf("%d", &N);
    int A[N];

    //INPUTING ARRAY
    printf("Enter elements: ");
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);

    printf("\n---------------------------------");
    //INPUTING ARRAY



    int i = 0;
    while (i < N && i + count < N) {
        if (A[i] == 0) {
            if (A[i + count] != 0) {
                A[i] = A[i + count];
                A[i + count] = 0;
                i++;
            } else
                count++;
        } else
            i++;
    }




    // OUTPUTTING FILE
    printf("\nNew Array: ");
    for(int i = 0; i<N; i++)
        printf("%d, ", A[i]);
    //OUTPUNG FILE;

    return 0;
}