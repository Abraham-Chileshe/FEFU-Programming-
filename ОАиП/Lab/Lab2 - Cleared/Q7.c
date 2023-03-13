#include <stdio.h>

// Function that pushes all the zeros to the start and ones
// to the end of an array
void reorder_array(int arr[], int n)
{

    int count1 = 0; //non zero elements
    for (int i = 0; i < n; i++)
        if (arr[i] != 1)
            arr[count1++] = arr[i];

    // Now all non-ones elements have been shifted to front
    // and 'count1' is set as index of first 1. Make all
    // elements 1 from count to end.
    while (count1 < n)
        arr[count1++] = 1;
    // Initialize lastNonBinary position to zero
    int lastNonOne = 0;

    // Traverse the array and pull non-zero elements to the
    // required indices
    for (int i = n - 1; i >= 0; i--) {
        // Ignore the 1's
        if (arr[i] == 1)
            continue;
        // Mark the position Of last NonBinary integer
        if (!lastNonOne)
            lastNonOne = i;
        // Place non-zero element to their required indices
        if (arr[i] != 0)
            arr[lastNonOne--] = arr[i];
    }

    // Put zeros to start of array
    while (lastNonOne >= 0)
        arr[lastNonOne--] = 0;
}

int main(){
    int size;
    printf("Size of Array:");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements in the array:\n",size);
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);


    int n = sizeof(arr) / sizeof(arr[0]);
    reorder_array(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); //print new array


    return 0;
}
