#include <stdio.h>

int main() {
    int N;
    int count;
    printf("Enter m:");
    scanf("%d", &N);

    for(int i =1; i<=N; i++){
        for(int j =2; j<i; j++){
            if(i%j == 0){
                count++;
                break;
            }
        }
        if(count ==0 && i != 1)
            printf("%d  ", i);
        count = 0;
    }


    return 0;

}
