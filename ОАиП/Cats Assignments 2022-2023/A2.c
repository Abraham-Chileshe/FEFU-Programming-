#include <stdio.h>
#include <math.h>

int main() {
    int num;
    int A[100];
    int sum=0, Flag=0;

    FILE *file;
    file = fopen("input.txt", "r");
    fscanf(file, "%d", &num);
    fclose(file);

    if (num>100 ) {
        sum += num/100-1;
        num = num - 100 * (num / 100)+100;
    }else if(num < -100){
        sum += -num/100-1;
        num = num + 100 * (-num / 100)-100;
    }
    A[0] = num;

    for(int i = 1; i<50; i++){
        sum++;
        num = abs(num-100);
        for(int j=0; j<i; j++){
            if(A[j]==num){
                Flag = 1;
                break;
            }
        }
        if (Flag==1) {
            file = fopen("output.txt", "w");
            fprintf_s(file, "%d", sum);
            fclose(file);
            break;
        }
        A[i]=num;
    }

    return 0;
}