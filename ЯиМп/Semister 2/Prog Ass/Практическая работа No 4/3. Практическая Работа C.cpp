#include <iostream>
#include <math.h>

using namespace std;
typedef double (*fun)(double x);

double f1C(double x){
    if (fabs(x) > 2) return 0;
    else return sqrt((1 - (x * x) / (2 * 2)) * 3 * 3);
}
double f2C(double x){
    if (fabs(x) > 2) return 0;
    else return -sqrt((1 - (x * x) / (2 * 2)) * 3 * 3);
}

int main(){

    double x, S,S0, h, a, b;

    S0 = M_PI * 2 * 3;

    a = -2; b = 2; h = 2;
    do {
        S = 0; x = a; h = h / 2;
        while (x < b){
            S = S + f1C(x) - f2C(x) + f1C(x + h) - f2C(x + h);
            x = x + h;
        }
        S = h * S / 2;
    }

    while (fabs(S0 - S) / S0 > 0.000001);
    cout << "Area: " << S << endl;


    return 0;
}
