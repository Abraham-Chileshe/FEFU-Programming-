#include <iostream>
#include <vector>
using namespace std;

int sign(double x) {
    return (x > 0) ? 1 : ((x < 0) ? -1 : 0);
}

void intersection(double a1, double b1, double c1, double a2, double b2, double c2, double& x, double& y) {
    double det = a1 * b2 - a2 * b1;
    x = (c2 * b1 - c1 * b2) / det;
    y = (a1 * c2 - a2 * c1) / det;
}

int main() {
    double x, y;
    int n, count = 0;
    cin >> x >> y >> n;
    
    if (x == y && x > 0 && y > 0) {
        count++;
    }
    
    for (int i = 0; i < n; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        
        if (a == 0) {
            double x1 = -c / b;
            if (x1 > 0 && x1 < x) {
                count++;
            }
        } else if (b == 0) {
            double y1 = -c / a;
            if (y1 > 0 && y1 < y) {
                count++;
            }
        } else {
           
            double x1, x2, y1, y2;
            intersection(a, b, c, 0, 1, 0, x1, y1);
            intersection(a, b, c, 0, 1, y, x2, y2);
            if (sign(x1) == sign(x2) && sign(y1) != sign(y2)) {
                count++;
            }
            intersection(a, b, c, 1, 0, 0, x1, y1);
            intersection(a, b, c, 1, 0, x, x2, y2);
            if (sign(y1) == sign(y2) && sign(x1) != sign(x2)) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
