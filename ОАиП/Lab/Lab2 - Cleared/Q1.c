#include <stdio.h>

int main(){
    int size;
    printf("Size of Array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in the array:\n",size);

    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);

    int min = arr[0]; //first element of array
    int max = arr[0]; //first element of array


    //Print smallest even number
    printf("Smallest even number:");
    for(int i=0; i<size; i++){
        if(arr[i]%2==0) {
            if (min >= arr[i])
                min = arr[i];
        }
    }
    printf("%d ", min);


    //print largest odd number
    printf("\nLargest Odd number: ");
    for(int j=0; j<size; j++){
        if(arr[j] % 2 == 1) {
            if (max <= arr[j])
                max = arr[j];
        }
    }
    printf("%d ", max);

    return 0;
}