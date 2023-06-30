#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    unsigned long long n, k; fin >> n >> k;

    if (k < 3) { fout << n; return 0; }
    if (n == 1) { fout << 1; return 0; }
    if (n == k) { fout << 2; return 0; }

    int max_deg = log(n) / log(k);
    unsigned long long Antwort = 0;

    int* arr = new int[max_deg];
    unsigned long long* pows = new unsigned long long[max_deg + 2]; pows[0] = 1;
    
    for (int i = 0; n; i++) {
        arr[i] = n % k;
        n /= k;
        pows[i + 1] = pows[i] * 2;
    }

    bool cond = true;

    for (int i = max_deg; i >= 0; i--) {
        if (arr[i] > 1) cond = false;

        if (cond) Antwort += arr[i] * pows[i];
        else { 
            fout << Antwort + pows[i + 1] - 1;
            return 0;
        }
      
    }

    fout << Antwort;
}
