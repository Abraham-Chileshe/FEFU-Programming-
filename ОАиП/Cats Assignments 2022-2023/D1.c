#include <stdio.h>
#include <math.h>

int main(){
    FILE *IN = fopen("input.txt", "r");
    FILE *OUT = fopen("output.txt", "w");
    double Xa, Ya;
    double Xb, Yb;
    double Xo, Yo;
    double Xa1, Ya1;
    double Xb1, Yb1;
    double beta;

    fscanf(IN, "%lf %lf", &Xa, &Ya);
    fscanf(IN, "%lf %lf", &Xb, &Yb);
    fscanf(IN, "%lf %lf", &Xo, &Yo);
    fscanf(IN, "%lf %lf", &beta);

    beta = beta * M_PI / 180;

    Xa1 = (Xa - Xo) * cos(beta) - (Ya - Yo) * sin(beta) + Xo;
    Ya1 = (Xa - Xo) * sin(beta) + (Ya - Yo) * cos(beta) + Yo;
    Xb1 = (Xb - Xo) * cos(beta) - (Yb - Yo) * sin(beta) + Xo;
    Yb1 = (Xb - Xo) * sin(beta) + (Yb - Yo) * cos(beta) + Yo;

    fprintf(OUT, "%.3lf %.3lf %.3lf %.3lf", Xa1, Ya1, Xb1, Yb1);
    return 0;
}