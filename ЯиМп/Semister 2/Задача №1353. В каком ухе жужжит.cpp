#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    int cp1 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    int cp2 = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);

    if (cp1 > 0 && cp2 > 0) {
        cout << "LEFT" << endl;
    } else if (cp1 < 0 && cp2 < 0) {
        cout << "RIGHT" << endl;
    } else {
        cout << "BOTH" << endl;
    }

    return 0;
}
