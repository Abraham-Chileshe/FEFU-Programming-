/*
Заполнить числовой массив, содержащий N () элементов, с клавиатуры. Осуществить упорядочение числового массива по возрастанию и убыванию *методом карманной сортировки* (а или б).
Программа должна обеспечить вывод исходного массива на экран, сортировку массива, вывод результата сортировки на экран. Оценить асимптотику и объяснить.
*/
#include <stdio.h>

void bucketSortAsc(int arr[], int n) {
    int max = arr[0], min = arr[0], i, j;

    // Find the maximum and minimum elements in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int bucketSize = max - min + 1;
    int buckets[bucketSize];

    // Initialize the buckets to zero
    for (i = 0; i < bucketSize; i++) {
        buckets[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (i = 0; i < n; i++) {
        buckets[arr[i] - min]++;
    }

    // Copy the elements back to the original array in sorted order
    int index = 0;
    for (i = 0; i < bucketSize; i++) {
        for (j = 0; j < buckets[i]; j++) {
            arr[index++] = i + min;
        }
    }
}

void bucketSortDesc(int arr[], int n) {
    int max = arr[0], min = arr[0], i, j;

    // Find the maximum and minimum elements in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int bucketSize = max - min + 1;
    int buckets[bucketSize];

    // Initialize the buckets to zero
    for (i = 0; i < bucketSize; i++) {
        buckets[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (i = 0; i < n; i++) {
        buckets[arr[i] - min]++;
    }

    // Copy the elements back to the original array in sorted order
    int index = 0;
    for (i = bucketSize - 1; i >= 0; i--) {
        for (j = 0; j < buckets[i]; j++) {
            arr[index++] = i + min;
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
    int n, i;

    printf("Enter the number of elements in the array (N >= 6): ");
    scanf("%d", &n);

    if (n < 6) {
        printf("The number of elements should be greater than or equal to 6.\n");
        return 0;
    }

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    printArray(arr, n);

    bucketSortAsc(arr, n);

    printf("Array sorted in ascending order: ");
    printArray(arr, n);

    bucketSortDesc(arr, n);

    printf("Array sorted in descending order: ");
    printArray(arr, n);

    return 0;
}
