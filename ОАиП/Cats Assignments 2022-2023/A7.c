#include <stdio.h>

int main(){
    FILE * myfile;
    int K,N;
    int page, line;

    myfile = fopen("a.in", "r");
    fscanf(myfile, "%d %d" ,&K,&N);
    fclose(myfile);

    if((K>=1 && K<=200) && (N>=1 && N<=20000)) {
        if (K >= N) {
            line = N;
            page = 1;
        } else {
            page = N / K;
            if(N%K == 0) {
                line = K;
            }else {
                page += 1;
                line = N % K;
            }
        }

        myfile = fopen("a.out", "w");
        fprintf(myfile, "%d %d",page,line);
    }

    return 0;
}