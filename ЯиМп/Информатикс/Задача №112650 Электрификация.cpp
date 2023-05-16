#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>> findMinimalNetwork(vector<vector<int>>& graph) {
    int numHouses = graph.size();
    vector<bool> selected(numHouses, false);
    vector<pair<int, int>> network;

    // Select the first house as the starting point
    selected[0] = true;

    while (network.size() < numHouses - 1) {
        int minDistance = INT_MAX;
        int minHouse1 = -1;
        int minHouse2 = -1;

        for (int i = 0; i < numHouses; i++) {
            if (selected[i]) {
                for (int j = 0; j < numHouses; j++) {
                    if (!selected[j] && graph[i][j] > 0 && graph[i][j] < minDistance) {
                        minDistance = graph[i][j];
                        minHouse1 = i;
                        minHouse2 = j;
                    }
                }
            }
        }

        if (minHouse1 != -1 && minHouse2 != -1) {
            network.push_back(make_pair(min(minHouse1, minHouse2), max(minHouse1, minHouse2)));
            selected[minHouse2] = true;
        }
    }

    return network;
}

int main() {
    int numHouses;
    cin >> numHouses;

    vector<vector<int>> graph(numHouses, vector<int>(numHouses));

    for (int i = 0; i < numHouses; i++) {
        for (int j = 0; j < numHouses; j++) {
            cin >> graph[i][j];
        }
    }

    vector<pair<int, int>> result = findMinimalNetwork(graph);

    sort(result.begin(), result.end());

    for (auto& edge : result) {
        cout << edge.first + 1 << " " << edge.second + 1 << endl;
    }

    return 0;
}
