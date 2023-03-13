#include <stdio.h>

int check_array(int arr[], int size){
    int n = size;

    if (n == 1 || n == 0)
        return 1;

    if(arr[n - 1] < arr[n-2])
        return 0;

    return check_array(arr, n - 1);
}

int main(){
    int size;
    printf("Size of array:");
    scanf("%d", &size);

    printf("Enter array elements:");
    int arr[size];
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    if(check_array(arr, size)) // if function returns 1
        printf("Yes");
    else
        printf("No"); // if function returns 0;

    return 0;
}

