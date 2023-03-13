#include <stdio.h>
#include <stdlib.h>

void merge(int **shelters, int l, int m, int r);
void mergeSort(int **shelters, int l, int r);

int main(){
    int m,n;
    FILE *IN = fopen("shelter.in", "r");
    FILE *OUT = fopen("shelter.out", "w");
    
    fscanf(IN, "%d", &n);

    int *cities = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        fscanf(IN, "%d", &cities[i]);


    fscanf(IN, "%d", &m);
    int *shelterss = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        fscanf(IN, "%d", &shelterss[i]);

    fclose(IN);

    int **shelters = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++){
        shelters[i] = (int *)malloc(2 * sizeof(int));
        shelters[i][0] = i + 1;
        shelters[i][1] = shelterss[i];
    }
    
    mergeSort(shelters, 0, m - 1);
    int *resList = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        if (cities[i] < shelters[0][1])
            resList[i] = shelters[0][0];
        else if (cities[i] > shelters[m - 1][1])
            resList[i] = shelters[m - 1][0];
        else{
            int l = 0;
            int r = m - 1;
            while (r - l > 1){
                int m = (r + l) / 2;
                if (shelters[m][1] < cities[i])
                    l = m;
                else
                    r = m;
            }

            if (cities[i] - shelters[l][1] < shelters[r][1] - cities[i])
                resList[i] = shelters[l][0];
            else
                resList[i] = shelters[r][0];
        }
    }
    
    for (int i = 0; i < n; i++)
        fprintf(OUT, "%d ", resList[i]);
    fclose(OUT);
    
    free(cities);
    free(shelterss);
    free(resList);
    
    for (int i = 0; i < m; i++)
        free(shelters[i]);
    free(shelters);
    
    
    return 0;
}

void merge(int **shelters, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int **L = (int **)malloc(n1 * sizeof(int *));
    int **R = (int **)malloc(n2 * sizeof(int *));
    for (i = 0; i < n1; i++)
    {
        L[i] = (int *)malloc(2 * sizeof(int));
        L[i][0] = shelters[l + i][0];
        L[i][1] = shelters[l + i][1];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = (int *)malloc(2 * sizeof(int));
        R[j][0] = shelters[m + 1 + j][0];
        R[j][1] = shelters[m + 1 + j][1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][1] <= R[j][1])
        {
            shelters[k][0] = L[i][0];
            shelters[k][1] = L[i][1];
            i++;
        }
        else
        {
            shelters[k][0] = R[j][0];
            shelters[k][1] = R[j][1];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        shelters[k][0] = L[i][0];
        shelters[k][1] = L[i][1];
        i++;
        k++;
    }
    while (j < n2)
    {
        shelters[k][0] = R[j][0];
        shelters[k][1] = R[j][1];
        j++;
        k++;
    }
}
void mergeSort(int **shelters, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(shelters, l, m);
        mergeSort(shelters, m + 1, r);
        merge(shelters, l, m, r);
    }
}