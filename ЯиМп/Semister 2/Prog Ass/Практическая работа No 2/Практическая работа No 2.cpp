#include <iostream>
#include <cmath>
#include <iomanip>
#define line cout<<"----------------------------------------\n";
using namespace std;

int variant;
double g(double x);
double h(double x);

//Overall Equation
double f(double x) {
    return g(x) - h(x);
}

// Using the Bisection method
void bisection(double a, double b, double eps) {
    double c = (a + b) / 2;

    while (abs(b - a) > eps) {
        if (f(c) == 0) {
            cout << "Root: " << c << endl;
            return;
        }
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
        c = (a + b) / 2;
    }
    cout << std::fixed <<std::setprecision(3) << "Root: " << c << endl;
}
// Using the Bisection method


int main() {
    std::cout<<"Enter variant Number: ";
    std::cin>>variant;

    std::line;
    double a = -5;
    double b = 5;
    double eps = 0.001;
    double step = 0.1;
    double x1 = a, x2 = a + step;
    bool foundRoot = false;

    while (x2 <= b) {
        if (f(x1) * f(x2) < 0) {
            cout << "root on interval [" << x1 << ", " << x2 << "]" << endl;
            bisection(x1, x2, eps);
            foundRoot = true;
            std::line
        }
        x1 += step;
        x2 += step;
    }
    if (!foundRoot)
        cout << "on interval [" << a << ", " << b << "] there is no root" << endl;


    
    return 0;
}

double g(double x) {
    double y;

    switch(variant){
        case 1:  y = pow(x, 3) - 8 * x + 1; break;
        case 2:  y = pow(x, 3) - 8 * x + 1; break;
        case 3:  y = pow(x, 3) - 8 * x + 1; break;
        case 4:  y = pow(x, 3) - 8 * x + 1; break;
        case 5:  y = pow(x, 3) - 8 * x + 1; break;
            //----------------------------------------------------------------
        case 6:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 7:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 8:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 9:  y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
        case 10: y = pow(x, 3) + 2 * pow(x,2) - 8 * x + 1; break;
            //----------------------------------------------------------------
        case 11: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 5; break;
        case 12: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 20; break;
        case 13: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 5; break;
        case 14: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 5; break;
        case 15: y = pow(x, 3) + 3 * pow(x,2) - 9 * x - 20; break;
            //----------------------------------------------------------------
        case 16 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 17 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 18 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 19 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;
        case 20 : y = pow(x, 3) + 2 * pow(x, 2) - 6 * x - 5; break;

        default: NAN;
    }
    return y;
}

double h(double x) {
    double y;
    switch(variant){
        case 1: y = 5 * sin(x); break;
        case 2: y = -2 * sin(x) - 10 * cos(x); break;
        case 3: y = -12 * sin(x) - 10 * cos(x); break;
        case 4: y = 5 * sin(x) + 12 * cos(x); break;
        case 5: y = -5 * sin(x) + 12 * cos(x); break;
            //--------------------------------------------------------------
        case 6: y = -2 * sin(x) - 15 * cos(x); break;
        case 7: y = -2 * sin(x) + 5 * cos(x); break;
        case 8: y = -12 * sin(x) + 8 * cos(x); break;
        case 9: y = 5 * sin(x) + 12 * cos(x); break;
        case 10: y = -5 * sin(x) + 12 * cos(x); break;
            //---------------------------------------------------------------
        case 11: y = -cos(x); break;
        case 12: y = -8 * sin(x) + 8 * cos(x); break;
        case 13: y = -5 * sin(x) + 5 * cos(x); break;
        case 14: y = -10 * sin(x) + 10 * cos(x); break;
        case 15: y = -18 * sin(x) + 25 * cos(x); break;
            //---------------------------------------------------------------
        case 16: y = -sin(x) - cos(x); break;
        case 17: y = -sin(x) - 15 * cos(x); break;
        case 18: y = -10 * sin(x) - 20 * cos(x); break;
        case 19: y = -10 * sin(x) + 10 * cos(x); break;
        case 20: y = -18 * sin(x) + 25 * cos(x); break;
        default: NAN;
    }
    return y;
}
