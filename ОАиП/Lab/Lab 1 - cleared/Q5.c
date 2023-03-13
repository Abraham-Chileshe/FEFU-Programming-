#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;

    printf(" Input a, b, c: \n");
    scanf("%d %d %d", &a,&b,&c);

    int Discriminant = pow(b, 2)- 4 * a * c;
    int x1, x2;

    if (Discriminant > 0) {
        x1 = (-b + sqrt(Discriminant)) / (2 * a);
        x2 = (-b - sqrt(Discriminant)) / (2 * a);

        printf("x1 = %d \nx2 = %d", x1, x2);
    }
    else if (Discriminant==0) {
        x1 = (-b + sqrt(Discriminant)) / (2 * a);

        printf("x1, x2 = %d", x1);

    }else
        printf("Not root");

    return 0;
}
