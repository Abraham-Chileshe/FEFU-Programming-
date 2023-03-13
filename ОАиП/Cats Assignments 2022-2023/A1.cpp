#include <iostream>
#include <fstream>

int main() {
    int A;
    int B;
    int st2 = 0, st5 = 0;

    std::ifstream in("input.txt");
    in >> A;
    in >> B;

    for (int i = 2; i < std::min(A, B); i++) {
        while (A % i == 0 && B % i == 0) {
            A /= i;
            B /= i;
        }
    }

    while (B % 2 == 0 || B % 5 == 0) {
        if (B % 2 == 0) {
            st2++;
            B /= 2;
        }
        
        if (B % 5 == 0) {
            st5++;
            B /= 5;
        }
    }
    
    std::ofstream out("output.txt");
    out << B << ' ' << std::max(st2, st5);
    out.close();

    return 0;
}