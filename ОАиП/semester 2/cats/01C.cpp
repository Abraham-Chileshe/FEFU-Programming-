#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    std::ifstream in;
    std::ofstream out("output.txt");

    in.open("input.txt", std::ios::in);
    int n, m;
    in>>n>>m;

    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }

    for (int i = 0; i <m; i++) {
        int num, val;
        in >> num >> val;
        a[num - 1] += val;

        int max_productivity = a[0];
        for (int j = 1; j < n; j++) {
            if (a[j] > max_productivity) {
                max_productivity = a[j];
            }
        }
        out << max_productivity << endl;
    }

    delete[] a;

    return 0;
}
