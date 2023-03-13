#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int Max_sum = 0;
    int IndexL;
    int IndexM;
    int IndexR;
    int *ArrPollen;
    
    FILE* IN = fopen("InPut.txt", "r");
    FILE* OUT = fopen("OutPut.txt", "w");

    fscanf(IN, "%d", &N);
    ArrPollen = (int*)malloc(sizeof (int)*N);
    
    for (int i = 0; i < N; ++i)
        fscanf(IN, "%d", &ArrPollen[i]);
    
    for (int i = 0; i < N - 1; i++) {
        int R = i;
        int M = i;

        int MSumma = ArrPollen[i];
        int RSumma = 0;

        while (R < N) {
            if (RSumma > MSumma) {
                M++;
                MSumma += ArrPollen[M];
                RSumma -= ArrPollen[M];
            } else {
                R++;
                RSumma += ArrPollen[R];
            }
            
            if (MSumma == RSumma && MSumma > Max_sum) {
                Max_sum = MSumma;
                IndexL = i + 1;
                IndexM = M + 1;
                IndexR = R + 1;
            }
        }
    }

    if (Max_sum != 0) 
        fprintf(OUT,"%d %d %d", IndexL, IndexM, IndexR);
    else
        fprintf(OUT, "%i", -1);
    
    
    return 0;
}