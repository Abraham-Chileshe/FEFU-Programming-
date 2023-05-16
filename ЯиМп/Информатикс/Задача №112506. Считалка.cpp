#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int* circle = new int[n];
    for (int i = 0; i < n; i++) {
        circle[i] = i + 1;
    }
    int pos = 0;  
    
    while (n > 1) {
        pos = (pos + k - 1) % n;
        cout << circle[pos] << " ";
        for (int i = pos; i < n - 1; i++) {
            circle[i] = circle[i + 1];
        }
        n--;
    }
    cout << circle[0];  

    delete[] circle;

    return 0;
}
