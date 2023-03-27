#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float fC(float x){
    if (fabs(x) > 2) return (0);
    else return (sqrt((1 - (x * x) / (2 * 2)) * 3 * 3));
}

int main(){

    float L0 = M_PI * (3 * (2 + 3) - sqrt((3 * 2 + 3) * (2 + 3 * 3)));
    float a = -2, b = 2, h = 2, x, y1, y2, L;

    do {
        L = 0;
        x = a;
        h /= 2;
        while (x < b) {
            y1 = fC(x);
            y2 = fC(x + h);
            L += sqrt(h * h + (y2 - y1) * (y2 - y1));
            x += h;
        }
        L *= 2;
    } while (fabs((L0 - L) / L0) >= 0.001);

    cout << "Curve length: " << fixed << setprecision(3) << L << endl;
    

    return 0;

}
