#include <iostream>

double f(double x) {
    return x * x;
}

double area(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * f(a);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    sum += 0.5 * f(b);
    return h * sum;
}

int main() {
    double a = 0.0; // lower limit of integration
    double b = 10.0; // upper limit of integration
    int n = 10000; // number of intervals
    double result = area(a, b, n);
    std::cout << "The area is " << result << std::endl;
    return 0;
}
