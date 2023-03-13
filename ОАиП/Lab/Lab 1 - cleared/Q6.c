#include <stdio.h>
#include <math.h>

int main(){
    //variables
    int a1, b1, c1; //Parabola
    int a2, b2; //line
    int desciminant;
    //--
    printf("Enter a1, b1, c1, a2, b2\n");
    scanf("%d %d %d %d %d", &a1, &b1, &c1, &a2, &b2);

    //formula = a1.x^2 + (b1 - a2)x + (c1 - b2).
    //desciminant = b^2 - 4 * a * c

    desciminant = pow((b1 - a2),2) - 4 * a1 * (c1 - b2);

    if(desciminant < 0)
        printf("NO");
    else if(desciminant > 0)
        printf("YES");
    else
        printf("The line is a tangent to the parabola");

    return 0;
}