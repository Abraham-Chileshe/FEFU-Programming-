#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  
    ifstream input("input.txt");
    
    if (!input) {
        cout << "Unable to open input file" << endl;
        return 1;
    }
    
    ofstream output("output.txt");
    
    if (!output) {
        cout << "Unable to open output file" << endl;
        return 1;
    }
    
    map<string, int> freq;
    
    string word;
    while (input >> word) {
        freq[word]++;
    }
    
    vector<pair<string, int>> word_freq;
    for (auto& entry : freq) {
        word_freq.push_back(entry);
    }
    sort(word_freq.begin(), word_freq.end(), [](auto& a, auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    });
    
    for (auto& entry : word_freq) {
        output << entry.first << " " << entry.second << endl;
    }
    
    input.close();
    output.close();

    return 0;
}
