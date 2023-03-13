#include <stdio.h>

int main(){
    int N;

    printf("Size of Array:");
    scanf("%d", &N);
    int arr[N];

    printf("Enter Elements:");
    for(int i =0; i<N; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal = ");
    for(int i =0; i<N; i++)
        printf("%d ", arr[i]);

    int temp;
    int j;

    for(int i=0; i<=N/2; i++) {
        temp = arr[i];
        j = i+1;
        arr[i] = arr[N - j];
        arr[N-j] = temp;
    }

    printf("\nSwapped = ");
    for(int i =0; i<N; i++)
        printf("%d ", arr[i]);


    return 0;
}