#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    int N = graph.size();
    for (int neighbor = 0; neighbor < N; ++neighbor) {
        if (graph[node][neighbor] && !visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
    return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

bool can_reach_all_cities(const vector<vector<int>>& graph) {
    int N = graph.size();
    vector<bool> visited(N, false);
    return dfs(graph, visited, 0);
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> graph[i][j];
        }
    }

    if (can_reach_all_cities(graph)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
