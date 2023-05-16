#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool isConvex(vector<Point>& polygon) {
    int n = polygon.size();
    if (n < 3) return false;

    int prev_orientation = orientation(polygon[n-2], polygon[n-1], polygon[0]);
    for (int i = 0; i < n; i++) {
        int curr_orientation = orientation(polygon[i], polygon[(i+1)%n], polygon[(i+2)%n]);
        if (curr_orientation != 0 && curr_orientation != prev_orientation)
            return false;
        prev_orientation = curr_orientation;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++)
        cin >> polygon[i].x >> polygon[i].y;

    if (isConvex(polygon))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
