#include <stdio.h>
#include <stdlib.h>

int main(){
    int N1;
    int N2;
    int N3;
    int count = 0;
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");
    
   fscanf(IN,"%d", &N1);
   fscanf(IN,"%d", &N2);
   fscanf(IN,"%d", &N3);


    int *a1 = (int *)malloc(N1 * sizeof(int));
    int *a2 = (int *)malloc(N2 * sizeof(int));
    int *a3 = (int *)malloc(N3 * sizeof(int));
    
    for (int i = 0; i < N1; i++)
       fscanf(IN,"%d", &a1[i]);
    
    for (int i = 0; i < N2; i++)
       fscanf(IN,"%d", &a2[i]);
    
    for (int i = 0; i < N3; i++)
       fscanf(IN,"%d", &a3[i]);


    int i = 0, j = 0, k = 0;
    while (i < N1 && j < N2 && k < N3)
    {
        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            count++;
            i++;
            j++;
            k++;
        }
        else if (a1[i] < a2[j])
            i++;
        else if (a2[j] < a3[k])
            j++;
        else
            k++;
    }

    fprintf(OUT,"%d", count);
    return 0;
}