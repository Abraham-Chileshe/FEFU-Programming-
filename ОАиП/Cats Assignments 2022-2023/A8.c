#include <stdio.h>

int largestValue(int arr[], int n){
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main(){
    int N;
    scanf("%d",&N);

    if(N>=1 && N<=35){
        int arr[N];

        for(int i=0; i<N; i++){
            scanf("%d",&arr[i]);
        }

        printf("%d", largestValue(arr, N));
    }
    
    return 0;
}