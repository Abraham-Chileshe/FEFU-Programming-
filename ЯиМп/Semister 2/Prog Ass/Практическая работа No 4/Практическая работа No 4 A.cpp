#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x;
}

int main() {
    double a = 0, b = 10, h = 0.01, x = a, S = 0;

    while (x < b) {
        S += h * f(x + h / 2);
        x += h;
    }
    cout << "Area: " << S << endl;

    return 0;
}
