#include <iostream>

using namespace std;

int main() {

    int xa, ya, xb, yb, xc, yc;
    double k;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> k;

    double xb_new = xa + k * (xb - xa); // Coordinate x point B
    double yb_new = ya + k * (yb - ya); // Coordinate Y point B
    double xc_new = xa + k * (xc - xa); // Coordinate x point C
    double yc_new = ya + k * (yc - ya); // Coordinate Y point C


    cout <<  xb_new << " " << yb_new << endl;
    cout << xc_new << " " << yc_new << endl;

    return 0;
}