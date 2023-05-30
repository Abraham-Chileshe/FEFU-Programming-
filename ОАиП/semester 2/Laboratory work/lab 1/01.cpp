#include <stdio.h>

void linearSort(int arr[], int n, int* comparisons, int* swaps) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;

        for (j = i+1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i) {
            (*swaps)++;
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i, comparisons = 0, swaps = 0;

    printf("Enter the number of elements in the array (N >= 6): ");
    scanf("%d", &n);

    if (n < 6) {
        printf("The number of elements must be greater than or equal to 6.\n");
        return 0;
    }

    int arr[n];

    printf("Enter array elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nSource array: ");
    printArray(arr, n);

    linearSort(arr, n, &comparisons, &swaps);

    printf("Sorted array (ascending): ");
    printArray(arr, n);

    printf("\nNumber of comparison iterations: %d\n", comparisons);
    printf("Number of exchange iterations: %d\n", swaps);

    return 0;
}
