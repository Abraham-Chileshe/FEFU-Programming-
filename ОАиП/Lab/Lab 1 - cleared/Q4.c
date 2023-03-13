#include <stdio.h>

int main(){
    //variables
    char s;
    int a,b;
    int result;
    //--

    scanf("%d %c %d", &a, &s, &b); //Input values

    switch(s){
        case '+': //addition
            result = a + b;
            printf("%d %c %d = %d", a,s,b,result);
            break;

        case '-': //subtraction
            result = a - b;
            printf("%d %c %d = %d", a,s,b,result);
            break;

        case '*': //multiplication
            result = a * b;
            printf("%d %c %d = %d", a,s,b,result);
            break;

        case '/': //division
            if(b == 0) {
                printf("Division by Zero is not possible");
                break;
            }else{
                result = a / b;
                printf("%d %c %d = %d", a,s,b,result);
                break;
            }

        default: printf("Sign not recognised");
    }

    return 0;
}


