#include <iostream>

using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto cp1 = (xb - xa) * (yc - ya) - (yb - ya) * (xc - xa);
    auto cp2 = (xb - xa) * (yc - yb) - (yb - ya) * (xc - xb);

    if (cp1 > 0 && cp2 > 0) cout << "LEFT" << endl;
    else if (cp1 < 0 && cp2 < 0) cout << "RIGHT" << endl;
    else cout << "BOTH" << endl;

    return 0;
}
