#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool dfs(int node, int parent, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adjacencyList[node]) {
        if (neighbor == parent) {
            continue; // Skip the parent node
        }

        if (visited[neighbor]) {
            return false; // Cycle detected
        }

        if (!dfs(neighbor, node, adjacencyList, visited)) {
            return false; // Cycle detected
        }
    }

    return true;
}

bool isTree(int n, int m, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjacencyList(n + 1);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);

    // Check if the graph is acyclic and connected using DFS
    bool isAcyclic = dfs(1, -1, adjacencyList, visited);

    // Check if all nodes are visited
    bool isConnected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            isConnected = false;
            break;
        }
    }

    return isAcyclic && isConnected;
}


int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n, m;
    inputFile >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;
        edges[i] = make_pair(u, v);
    }

    bool result = isTree(n, m, edges);
    outputFile << (result ? "YES" : "NO") << endl;

    return 0;
}
