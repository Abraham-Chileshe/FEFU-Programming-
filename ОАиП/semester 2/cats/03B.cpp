#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool areSubstringsEqual(const string& s, int a, int b, int c, int d) {
    string sub1 = s.substr(a - 1, b - a + 1);
    string sub2 = s.substr(c - 1, d - c + 1);
    return sub1 == sub2;
}

int main() {
    string s;
    cin >> s;

    int M;
    cin >> M;

    vector<int> results;
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool result = areSubstringsEqual(s, a, b, c, d);
        results.push_back(result);
    }

    for (int result : results) {
        cout << (result ? "Yes" : "No") << endl;
    }

    return 0;
}
