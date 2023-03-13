#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    std::ifstream in;
    std::ofstream out;
    string sequence;

    in.open("input.txt", std::ios::in);
    while (getline(in, sequence));

    bool all_small = true;
    bool all_large = false;


    for (char c : sequence) {
        if (c >= 'a' && c <= 'z') { // check if it's a small letter
            if (!all_small) {
                out.open ("output.txt", std::ios::out);
                out<<"NO";
                out.close();
                return 0;
            }
        } else { // it's a large letter
            if (all_small) {
                all_small = false;
                all_large = true;
            } else if (!all_large) {
                out.open ("output.txt", std::ios::out);
                out<<"NO";
                out.close();
                return 0;
            }
        }
    }

    out.open ("output.txt", std::ios::out);
    out<<"YES";
    out.close();
    return 0;
}
