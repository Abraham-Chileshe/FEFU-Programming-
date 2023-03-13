#include <stdio.h>
#include <math.h>

int main(){
    int size;
    printf("Size of Array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in the array:\n",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);

    int minVal = arr[0];

    //Print smallest even number
    printf("Smallest values ");
    for(int i=0; i<size; i++){
        if(abs(arr[i]) < abs(minVal) ) {
            minVal = abs(arr[i]);
        }
    }
    printf("%d ", minVal);

    
    return 0;
}