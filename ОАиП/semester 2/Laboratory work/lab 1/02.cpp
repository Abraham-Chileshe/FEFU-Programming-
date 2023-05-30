/*
Заполнить числовой массив, содержащий N () элементов, с клавиатуры. Осуществить упорядочение числового массива по возрастанию и убыванию *методом подсчёта*.
Программа должна обеспечить вывод исходного массива на экран, сортировку массива, вывод результата сортировки на экран. Оценить асимптотику и объяснить.
*/

#include <stdio.h>

void countingSortAsc(int arr[], int n) {
    int max = arr[0], i;

    // Find the maximum element in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max+1], sortedArr[n];

    // Initialize the counters to zero
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Calculate the positions of elements in the sorted array
    for (i = 1; i <= max; i++) {
        count[i] += count[i-1];
    }

    // Distribute the elements in the sorted array
    for (i = n-1; i >= 0; i--) {
        sortedArr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array back to the original array
    for (i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }
}

void countingSortDesc(int arr[], int n) {
    int max = arr[0], i;

    // Find the maximum element in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max+1], sortedArr[n];

    // Initialize the counters to zero
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Calculate the positions of elements in the sorted array
    for (i = max-1; i >= 0; i--) {
        count[i] += count[i+1];
    }

    // Distribute the elements in the sorted array
    for (i = 0; i < n; i++) {
        sortedArr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array back to the original array
    for (i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
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

    countingSortAsc(arr, n);

    printf("Array sorted in ascending order: ");
    printArray(arr, n);

    countingSortDesc(arr, n);

    printf("Array sorted in descending order: ");
    printArray(arr, n);
    
    return 0;

}
