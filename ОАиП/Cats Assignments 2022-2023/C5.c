#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    FILE * IN = fopen("input.txt", "r");
    FILE * OUT = fopen("output.txt", "w");
    
    int K;
    float N;
    int Flag = 0;
    int SqrtBuff, SqrtN;
    float NBuff;
    float * Otv = (float *)malloc(sizeof (float ));
    
    fscanf(IN, "%f", &N); //цена
    fscanf(IN, "%d", &K);
    
    SqrtN = floor(sqrt(N));
    
    while (SqrtN > 0){ 
        NBuff = N;
        NBuff = NBuff - SqrtN  * SqrtN;
        Otv[0] = SqrtN; 
        
        if (NBuff != 0){
            for (int i = 1; i < K; i++){
                SqrtBuff = floor(sqrt(NBuff));
                NBuff = NBuff - SqrtBuff * SqrtBuff; 
                Otv = (float *) realloc(Otv, sizeof(float ));
                Otv[i] = SqrtBuff;
                if (NBuff == 0){
                    K = i + 1;
                    Flag = 1;
                    break;
                }
            }
        }else{
            Flag = 1;
            K = 1;
        }
        SqrtN --;
        if (Flag == 1)
            break;
    }
    
    if (Flag != 0){
        fprintf(OUT,   "YES\n");
        
        for (int i = 0; i < K; i++)
            fprintf(OUT, "%d ", (int)Otv[i]);
    }
    
    if (Flag == 0)
        fprintf(OUT,  "NO\n");
    
    
    return 0;
}