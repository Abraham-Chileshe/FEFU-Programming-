#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int polygonX[n], polygonY[n];
    for(int i=0; i<n; i++) {
        cin >> polygonX[i] >> polygonY[i];
    }
    bool inside = false;
    for(int i=0, j=n-1; i<n; j=i++) {
        if(((polygonY[i] > y) != (polygonY[j] > y)) && (x < (polygonX[j] - polygonX[i]) * (y - polygonY[i]) / (polygonY[j] - polygonY[i]) + polygonX[i])) {
            inside = !inside;
        }
    }
    if(inside) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
