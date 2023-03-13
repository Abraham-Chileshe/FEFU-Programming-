#include <stdio.h>
#include <limits.h>

int main(){
    //variables
    int max= INT_MIN;
    int min = INT_MAX;
    int N, remainder;
    //--
    printf("Enter N:");
    scanf("%d", &N); //getting N;

    while(N > 0){
        remainder = N % 10;

        if(remainder > max)
            max = remainder; //gets the largest value

        if(remainder < min)
            min = remainder; //gets the smallest value;

        N /=10;
    }
    printf("Max: %d \nMin: %d", max,min);

    return 0;
}