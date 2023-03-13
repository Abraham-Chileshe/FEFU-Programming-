#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float f(float x) {
    return x * x; // уравнение параболы
}

int main() {
    float a = 0.0; // левая граница интервала
    float b = 10.0; // правая граница интервала
    float h = 0.01; // шаг

    float x = a;
    float L = 0;

    while (x < b) {
        float y1 = f(x);
        float y2 = f(x + h);
        L += sqrt(h * h + (y2 - y1) * (y2 - y1));
        x += h;
    }
    cout << "Parabola length y = x^2 on Interval [" << a << ", " << b << "] : ";
    cout << fixed << setw(5) << setprecision(3) << L << endl;
    return 0;
}
