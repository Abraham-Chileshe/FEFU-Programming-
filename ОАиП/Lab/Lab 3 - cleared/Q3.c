#include <stdio.h>

int main(){
    int size, b;
    int b_occurs = 0;
    int max, min;

    printf("Size of array:");
    scanf("%d", &size);

    printf("Enter array elements:");
    int arr[size];
    for(int i = 0; i<size; i++)
        scanf("%d", &arr[i]);

    printf("Enter b:");
    scanf("%d", &b);

    for(int i = 0; i<size; i++){
        if(arr[i] == b) {
            b_occurs++;
        }
    }

    for(int i=size-1; i>=0; --i){
        if(arr[i] == b) {
            max = i;
            break;
        }
    }

    for(int i=0; i<size; i++){
        if(arr[i] == b) {
            min = i;
            break;
        }
    }

    printf("result (m, i1, i2) = (%d, %d, %d)\n",b_occurs, min, max);

    return 0;
}

