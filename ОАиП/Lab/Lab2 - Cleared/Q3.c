#include <stdio.h>

int main(){
    int size;
    printf("Size of Array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in the array:\n",size);

    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
    int product = 1;

    //print largest odd number
    printf("\nProduct: ");
    for(int j=0; j<size; j++){
        if(arr[j] % 2 == 1) {
            product *= arr[j];
        }
    }
    printf("%d ", product);

    return 0;
}