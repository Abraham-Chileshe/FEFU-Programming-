#include <stdio.h>

void swap(short int *x, short int *y){
    short int tmp = *x;
    *x = *y;
    *y = tmp;
}
void Sort(short int a[], int lt, int rt);


int main(){
    int N;
    short int a[1000000];
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");
    
    fscanf(IN, "%d", &N);
    for(int i = 0; i < N; i++)
        fscanf(IN, "%hd", &a[i]);
    
    Sort(a, 0, N - 1);
    short int curr_el = a[0];
    int count = 1;


    for(int i = 1; i < N; i++){
        if(a[i] == curr_el)
            count++;
        else{
            fprintf(OUT, "%d %d\n", curr_el, count);
            curr_el = a[i];
            count = 1;
        }
    }

    fprintf(OUT, "%d %d\n", curr_el, count);

}


void Sort(short int a[], int lt, int rt){
    int i = lt, j = rt;
    short int pivot = a[(lt + rt) / 2];
    while(i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    if(lt < j) Sort(a, lt, j);
    if(i < rt) Sort(a, i, rt);
}