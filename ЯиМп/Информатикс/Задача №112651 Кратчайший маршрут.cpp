#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

std::pair<int, std::vector<int>> dijkstra(const std::vector<std::vector<int>>& graph, int start, int end) {
    int num_cities = graph.size();
    std::vector<int> distances(num_cities, std::numeric_limits<int>::max());
    std::vector<bool> visited(num_cities, false);
    std::vector<int> path(num_cities, -1);

    distances[start] = 0;

    for (int _ = 0; _ < num_cities; ++_) {
        int min_dist = std::numeric_limits<int>::max();
        int min_dist_city = -1;

        for (int i = 0; i < num_cities; ++i) {
            if (!visited[i] && distances[i] < min_dist) {
                min_dist = distances[i];
                min_dist_city = i;
            }
        }

        if (min_dist_city == -1) {
            break;
        }

        visited[min_dist_city] = true;

        for (int i = 0; i < num_cities; ++i) {
            if (!visited[i] && graph[min_dist_city][i] > 0 && distances[min_dist_city] + graph[min_dist_city][i] < distances[i]) {
                distances[i] = distances[min_dist_city] + graph[min_dist_city][i];
                path[i] = min_dist_city;
            }
        }
    }

    if (distances[end] == std::numeric_limits<int>::max()) {
        return {0, {}};
    }

    std::vector<int> shortest_path;
    int city = end;

    while (city != -1) {
        shortest_path.push_back(city);
        city = path[city];
    }

    std::reverse(shortest_path.begin(), shortest_path.end());

    return {distances[end], shortest_path};
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }

    int start, end;
    std::cin >> start >> end;
    --start;
    --end;

    auto result = dijkstra(graph, start, end);

    std::cout << result.first << std::endl;
    if (result.first != 0) {
        for (int city : result.second) {
            std::cout << city + 1 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
