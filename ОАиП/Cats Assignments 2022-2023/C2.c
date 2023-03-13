#include <stdio.h>

int min(int, int);
int max(int, int);

int main(){
    int N;
    int arr[105], arr1[105];

    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");

    fscanf(IN, "%d", &N);
    for(int i = 1; i <= N; i++){
        fscanf(IN, "%d", &arr[i]);
        arr1[i] = arr[i];
    }

    arr[N + 1] = 0;
    arr1[N + 1] = 0;
    arr[0] = 0;
    arr1[0] = 0;
    int first_sum = 0;

    for(int i = 2; i <= N; i+=2){
        int val = max(arr[i - 1], arr[i + 1]) + 1;
        first_sum += max(0, val - arr[i]);
        arr1[i] = arr[i] + max(0, val - arr[i]);
    }
    int second_sum = 0;


    for(int i = 1; i <= N; i+=2){
        int val = max(arr[i - 1], arr[i + 1]) + 1;
        second_sum += max(0, val - arr[i]);
        arr[i] = arr[i] + max(0, val - arr[i]);
    }

    if(first_sum < second_sum){
        for(int i = 1; i <= N; i++){
            fprintf(OUT, "%d ", arr1[i]);
        }
    }
    else{
        for(int i = 1; i <= N; i++){
            fprintf(OUT, "%d ", arr[i]);
        }
    }

}


int min(int a, int b){
    if(a < b){
        return a;
    }
    return b;
}
int max (int a, int b){
    if(a > b){
        return a;
    }
    return b;
}