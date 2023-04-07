#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

struct Rectangle {
    int x, y;
};

bool compare(const Rectangle& left, const Rectangle& right) {
    return left.y > right.y;
}

int main() {
    std::ifstream input("power.in");
    std::ofstream output("power.out");

    int n, k;
    input >> n >> k;

    std::vector<Rectangle> rectangles(n);
    for (int i = 0; i < n; ++i) {
        input >> rectangles[i].x >> rectangles[i].y;
    }

    std::sort(rectangles.begin(), rectangles.end(), compare);

    std::priority_queue<int, std::vector<int>, std::greater<>> xs;
    long long max_area = 0;

    for (const auto& r : rectangles) {
        xs.push(r.x);

        if (xs.size() > k) {
            xs.pop();
        }

        if (xs.size() == k) {
            max_area = std::max(max_area, 1LL * r.y * xs.top());
        }
    }

    output << max_area << '\n';
}
