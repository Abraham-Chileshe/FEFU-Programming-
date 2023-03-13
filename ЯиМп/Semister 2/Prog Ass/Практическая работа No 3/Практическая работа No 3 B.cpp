#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.8; // ускорение свободного падения

double fB(double x, double v0, double alfa) {
    double t = (v0 == 0) ? 0 : x / (v0 * cos(alfa));
    return v0 * t * sin(alfa) - 0.5 * g * t * t;
}

int main() {
    double a = 0, b = 10, h = 0.01;
    double x = a;
    double alfa1 = 35.5;
    double v01 = 12;
    double L1 = 0;

    while (x < b) {
        double y1 = fB(x, v01, alfa1);
        double y2 = fB(x + h, v01, alfa1);
        L1 += sqrt(h * h + (y2 - y1) * (y2 - y1));
        x += h;
    }
    cout << "Length of Parabola under angle " << alfa1 << ": " << L1 << endl;


    //Second  Test.

    x = a;
    double alfa2 = 65.8;
    double v02 = 12;
    double L2 = 0;

    while (x < b) {
        double y1 = fB(x, v02, alfa2);
        double y2 = fB(x + h, v02, alfa2);
        L2 += sqrt(h * h + (y2 - y1) * (y2 - y1));
        x += h;
    }
    cout << "Length of Parabola under angle " << alfa2 << ": " << L2 << endl;

    //----------------

    return 0;
}
