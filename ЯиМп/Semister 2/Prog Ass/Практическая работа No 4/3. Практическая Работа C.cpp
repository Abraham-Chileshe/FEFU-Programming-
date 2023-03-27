#include <iostream>
#include <math.h>
#define line cout<<"\n-------------------------\n";

using namespace std;
typedef double (*fun)(double x);


double fB(double x){
    return x * x - 4 * cos(x);
}


double f1B(double x){
    return 4 * cos(x);
}

double f2B(double x){
    return x * x;
}


void interval(double &l, double &r, fun f){

    const double  eps = 0.00001;
    short int n;
    double delta, a, b, c;
    n = 0;
    a = -100;
    while (a <= 100){
        while ((f(a) * f(a + 0.1) > 0) && (a <= 100)) a = a + 0.1;
        if (f(a) * f(a + 0.1) < 0){
            b = a + 0.1;
            delta = 2 * eps;
            while (b - a > delta){
                c = (a + b) / 2;
                if (f(a) * f(c) <= 0)   b = c;
                else a = c;
            }
            if (n == 0)  l = (a + b) / 2; else r = (a + b) / 2;
        }
        a = a + 0.1;
        n = n + 1;
    }
}


int main(){

    double x, S, h, a, b;

    cout << "Trapezoid method";
    std::line;
    interval(a, b, fB);
    S = 0; x = a; h = 0.01;

    while (x < b){
        S = S + f1B(x) - f2B(x) + f1B(x + h) - f2B(x + h);
        x = x + h;
    }

    S = h * S / 2;
    printf("Area: %0.3f", S);
    std::line;


    return 0;
}
