#include <stdio.h>

int factorial(int, int);

int main(){

    int x;
    int result = 1;
    printf("Enter x: ");
    scanf("%d", &x);

    if(x <= 10 )
        printf("%d! = %d", x, factorial(x,result));
    else
        printf("Error");

    return 0;
}

int factorial(int n, int result) {
    if (n == 1)
        return result;
    else if(n == 0)
        return 1;
    else
        return factorial(n-1,result *= n);
}