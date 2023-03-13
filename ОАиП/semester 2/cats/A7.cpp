#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 4 // maximum length of each word (including null terminator)

int partition(char **words, int low, int high) {
    char *pivot = words[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (strcmp(words[j], pivot) <= 0) {
            i++;
            char *temp = words[i];
            words[i] = words[j];
            words[j] = temp;
        }
    }
    char *temp = words[i+1];
    words[i+1] = words[high];
    words[high] = temp;
    return i+1;
}

void quickSort(char **words, int low, int high) {
    if (low < high) {
        int pi = partition(words, low, high);
        quickSort(words, low, pi-1);
        quickSort(words, pi+1, high);
    }
}

int main() {
    FILE *input_file, *output_file;
    int n;

    // Open input and output files
    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    // Read in the number of words
    fscanf(input_file, "%d", &n);

    // Read in the words and store them in a dynamically allocated array
    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *)malloc(MAX_LEN * sizeof(char));
        fscanf(input_file, "%s", words[i]);
    }

    // Sort the array in lexicographical order using Quick Sort
    quickSort(words, 0, n-1);

    // Output the sorted sequence to the output file
    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%s\n", words[i]);
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
