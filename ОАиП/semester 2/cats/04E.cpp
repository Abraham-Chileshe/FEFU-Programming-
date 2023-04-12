#include <fstream>
#include <algorithm>
#include <vector>

using namespace std; 
int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    vector<vector<double>> times(4, vector<double>(4));
    vector<int> idx = {0, 1, 2, 3};
    vector<int> result(4);
    double minimum_time = 1e9;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            in >> times[i][j];
        }
    }
    
    do {
        double currentTime = times[0][idx[0]] + times[1][idx[1]] + times[2][idx[2]] + times[3][idx[3]];
        if (currentTime < minimum_time) {
            minimum_time = currentTime;
            result = idx;
        }
    } while (next_permutation(idx.begin(), idx.end()));
    
    
    for (int x: result) {
        out << x + 1 << ' ';
    }
    out << endl;
    
    
    
    return 0;
}
