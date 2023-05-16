#include <iostream>

int main() {
    int xa, ya, xb, yb, xc, yc;
    std::cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int cp1 = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);
    int cp2 = (xb - xa) * (yc - yb) - (yb - ya) * (xc - xb);

    if (cp1 > 0 && cp2 > 0) {
        std::cout << "LEFT\n";
    } else if (cp1 < 0 && cp2 < 0) {
        std::cout << "RIGHT\n";
    } else {
        std::cout << "BOTH\n";
    }

    return 0;
}
