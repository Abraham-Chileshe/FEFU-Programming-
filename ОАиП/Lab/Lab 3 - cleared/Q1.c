#include <stdio.h>

int main(){
    int size;
    printf("Array size:");
    scanf("%d", &size);

    int arr[size];
    int sum = 0;
    int product = 1;

    for(int i = 0; i <size; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i <size; i++) {
        if (arr[i] > 0){
            sum += arr[i];
            product *= arr[i];
        }

    }

    printf("Sum of Positive values = %d \n", sum);
    printf("Product: %d", product);





    return 0;
}