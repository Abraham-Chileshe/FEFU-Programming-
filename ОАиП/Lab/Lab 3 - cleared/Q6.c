#include <stdio.h>
#define line printf("-----------------------------\n");

int binarysearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarysearch(arr, l, mid - 1, x);

        return binarysearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int main(){
    int size;
    int value;
    printf("Enter the size of the array");
    scanf("%d", &size);

    int arr[size];
    printf("Enter Array elements");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to check:");
    scanf("%d",&value);
    line;
    if(binarysearch(arr,0,size,value) != -1)
        printf("%d is on index number = %d\n", value, binarysearch(arr,0,size,value));
    else
        printf("Value does not exist in array\n");
    line;



    return 0 ;
}