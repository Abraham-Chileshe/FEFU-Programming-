#include <stdio.h>
#include <limits.h>

int main(){
    int N;
    int begin = INT_MIN;
    int end = INT_MAX;
    int sum = 0;

    printf("Size of Array:");
    scanf("%d", &N);
    int arr[N];

    printf("Enter Elements:");
    for(int i =0; i<N; i++)
        scanf("%d", &arr[i]);


    for(int i = 0; i <N; i++){
        if(arr[i] == 0) {
            begin = i;
            break;
        }
    }

    if(begin != INT_MIN) {
        for (int j = begin + 1; j < N; j++) {
            if (arr[j] == 0) {
                end = j;
                break;
            }
        }
        if(end != INT_MAX) {
            for(int i = begin; i<=end; i++){
                sum += arr[i];
            }
            printf("\nSome between first two zeros = %d\n", sum);
        }else
            printf("\nOnly one Zero Found. Sum = %d\n", sum);
    }else
        printf("\nNo Zero found in array. Sum = %d\n", sum);


    return 0;
}