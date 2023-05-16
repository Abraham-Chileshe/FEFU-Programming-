#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для проверки, содержится ли карта в колоде
bool contains(const vector<string>& deck, const string& card) {
    return find(deck.begin(), deck.end(), card) != deck.end();
}

int main() {
    vector<string> deck;  // Инициализируем пустую колоду

    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    string line;
    while (getline(infile, line)) {
        char command = line[0];  // Получаем команду из первого символа строки

        if (command == '+') {
            string card = line.substr(1);  // Получаем карту из оставшейся части строки
            if (contains(deck, card)) {
                outfile << "ERROR" << endl;
            } else {
                deck.push_back(card);
            }
        } else if (command == '^') {
            if (deck.empty()) {
                outfile << "ERROR" << endl;
            } else {
                deck.pop_back();
            }
        } else if (command == '#') {
            string card = line.substr(1);
            if (contains(deck, card)) {
                outfile << "ERROR" << endl;
            } else {
                deck.insert(deck.begin(), card);
            }
        } else if (command == '/') {
            if (deck.empty()) {
                outfile << "ERROR" << endl;
            } else {
                deck.erase(deck.begin());
            }
        }
    }

    if (deck.empty()) {
        outfile << "EMPTY" << endl;
    } else {
        for (auto it = deck.rbegin(); it != deck.rend(); ++it) {
            outfile << *it << " ";
        }
        outfile << endl;
    }

    return 0;
}
