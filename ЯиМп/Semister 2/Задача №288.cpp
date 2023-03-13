#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int intersect(const Point& p1, const Point& p2, const Point& p) {
    // Check if the horizontal ray intersects with the edge (p1,p2)
    if ((p1.y > p.y) != (p2.y > p.y)) {
        // Compute the x-coordinate of the intersection
        double x = (double)(p2.x - p1.x) * (double)(p.y - p1.y) / (double)(p2.y - p1.y) + p1.x;
        // Count the intersection if it's to the right of the point
        if (x > p.x) return 1;
    }
    return 0;
}

bool isInside(const vector<Point>& polygon, const Point& p) {
    int count = 0;
    for (int i = 0, j = polygon.size() - 1; i < polygon.size(); j = i++) {
        count += intersect(polygon[j], polygon[i], p);
    }
    return count % 2 == 1;
}

int main() {
    int n, px, py;
    cin >> n >> px >> py;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    bool inside = isInside(polygon, {px, py});

    if (inside) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
