#include <stdio.h>

int main(){
    int size;
    printf("Size of Array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in the array:\n",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);

    int sum = 0;

    //Print smallest even number
    printf("The sum of negative numbers: ");
    for(int i=0; i<size; i++){
        if(arr[i] < 0) {
            sum += arr[i];
        }
    }
    printf("%d ", sum);



    return 0;
}