#include <stdio.h>
#include <string.h>

int N;
char s[5];
int main(){

    FILE *IN = fopen("function.in", "r");
    FILE *OUT =fopen("function.out", "w");

    fscanf(IN,"%d\n", &N);
    fscanf(IN,"%s", s);

    if (!strcmp(s, "0000"))
         fprintf(OUT,"No solution");

    else if(s[3] == '1'){
        for(int i = 0; i < N; i++)
             fprintf(OUT,"1");
    }

    else if(!strcmp(s, "0010")){
         fprintf(OUT,"1");
        for(int i = 0; i < N - 1; i++)
             fprintf(OUT,"0");
    }
    else if (s[0] == '0' && s[1] == '1'){
        if (N % 2 == 0){
            for(int i = 1; i < N - 1; i++)
                 fprintf(OUT,"1");
             fprintf(OUT,"01");
        }
        else
            for(int i = 0; i < N; i++)
                 fprintf(OUT,"1");
    }
    else if(s[0] == '1' && s[1] == '0'){
        for(int i = 0; i < N - 1; i++)
             fprintf(OUT,"1");
         fprintf(OUT,"0");
    }
    else if (s[0] == '1' && s[1] == '1'){

        if (N % 2 == 0){
            fprintf(OUT,"0");
            for(int i = 0; i < N - 1; i++)
                fprintf(OUT,"1");
        }
        else {
            for (int i = 0; i < N; i++)
                fprintf(OUT,"1");
        }
    }

    return 0;
}