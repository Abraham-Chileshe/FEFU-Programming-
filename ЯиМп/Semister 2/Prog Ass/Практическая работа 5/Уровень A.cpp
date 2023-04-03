#include <iostream>
#include <cmath>
#include <iomanip>
#define line cout<<"\n------------------------\n";

using namespace std;

double f(double x);
double goldenSectionSearch(double a, double b, double epsilon, double (*f)(double));

int main() {
    double a, b, epsilon;
    std::cout<<"Enter Intervals [a, b]:";
    std::cin>>a>>b;

    std::cout<<"Enter epsilon:";
    std::cin>>epsilon;

    std::line;
    double xmax = goldenSectionSearch(a, b, epsilon, [](double x) {return -f(x);}); // поиск максимума функции
    double fmax = f(xmax); // значение функции в точке максимума
    cout << "max:(" << fixed << setprecision(3)<<xmax << ", " << fmax <<")"<<std::endl;

    double xmin = goldenSectionSearch(a, b, epsilon, f); // поиск минимума функции
    double fmin = f(xmin); // значение функции в точке минимума
    cout << "min:(" << xmin << ", " << fmin <<")"<< endl;


    return 0;
}

double f(double x) {
    return pow(x, 3) + 2 * pow(x, 2) - 6* x - 5 + sin(x) + cos(x);
    //return pow(x, 3) - 8 * x + 1 - 5*sin(x);
}

double goldenSectionSearch(double a, double b, double epsilon, double (*f)(double)) {
    const double phi = (1 + sqrt(5)) / 2; // коэффициент "золотого сечения"
    double x1 = b - (b - a) / phi; // вычисление первой пробной точки
    double x2 = a + (b - a) / phi; // вычисление второй пробной точки
    double fx1 = f(x1); // вычисление значения функции в первой пробной точке
    double fx2 = f(x2); // вычисление значения функции во второй пробной точке
    while (abs(b - a) > epsilon) {
        if (fx1 < fx2) {
            b = x2;
            x2 = x1;
            fx2 = fx1;
            x1 = b - (b - a) / phi;
            fx1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            fx1 = fx2;
            x2 = a + (b - a) / phi;
            fx2 = f(x2);
        }
    }
    return (a + b) / 2;
}
