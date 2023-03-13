#include <stdio.h>

FILE *myfile;
// Function to print the output
void printTheArray(int arr[], int n){

    myfile = fopen ("output.txt","a+");
    for (int i = 0; i < n; i++)
    fprintf(myfile, "%d",arr[i]);
    fprintf(myfile,"\n");
    fclose (myfile);


}

// Function to generate all binary strings
void generateAllBinaryStrings(int n, int arr[], int i)
{
    if (i == n) {
        printTheArray(arr, n);
        return;
    }

    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);

    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}

int main(){

    int n;
    myfile = fopen("input.txt", "r");
    fscanf(myfile, "%d", &n);
    int arr[n];

    // Print all binary strings

    generateAllBinaryStrings(n, arr, 0);

    return 0;
}