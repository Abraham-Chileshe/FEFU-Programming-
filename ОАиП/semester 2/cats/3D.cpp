
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <fstream>

using namespace std;


template<typename K, typename V>
class HashTable {
private:
    std::vector<std::vector<std::pair<K, V>>> data_;
    std::hash<K> hasher_;

public:
    HashTable(std::size_t size = 100) : data_(size) {}

    void insert(const K& key, const V& value) {
        std::size_t bucket = hasher_(key) % data_.size();
        auto& kvp_list = data_[bucket];
        auto it = std::find_if(kvp_list.begin(), kvp_list.end(),
                               [&](const std::pair<K, V>& kvp) { return kvp.first == key; });
        if (it != kvp_list.end()) {
            it->second = value;
        } else {
            kvp_list.push_back(std::make_pair(key, value));
        }
    }

    V& operator[](const K& key) {
        std::size_t bucket = hasher_(key) % data_.size();
        auto& kvp_list = data_[bucket];
        auto it = std::find_if(kvp_list.begin(), kvp_list.end(),
                               [&](const std::pair<K, V>& kvp) { return kvp.first == key; });
        if (it != kvp_list.end()) {
            return it->second;
        } else {
            kvp_list.emplace_back(key, V());
            return kvp_list.back().second;
        }
    }

    const V& operator[](const K& key) const {
        std::size_t bucket = hasher_(key) % data_.size();
        auto& kvp_list = data_[bucket];
        auto it = std::find_if(kvp_list.begin(), kvp_list.end(),
                               [&](const std::pair<K, V>& kvp) { return kvp.first == key; });
        if (it != kvp_list.end()) {
            return it->second;
        } else {
            throw std::out_of_range("key not found");
        }
    }

    std::vector<std::pair<K, V>> get_data() const {
        std::vector<std::pair<K, V>> result;
        for (const auto& kvp_list : data_) {
            for (const auto& kvp : kvp_list) {
                result.push_back(kvp);
            }
        }
        return result;
    }
};

int main() {
    HashTable<std::string, int> schools;

    std::ifstream fin("schools.in");
    std::ofstream fout("schools.out");

    int n;
    fin >> n;
    fin.ignore();

    for (int i = 0; i < n; i++) {
        std::string name;
        std::getline(fin, name);

        std::string number;
        for (char ch : name) {
            if (isdigit(ch)) {
                number += ch;
            } else if (!number.empty()) {
                break;
            }
        }

        if (!number.empty()) {
            schools[number]++;
        }
    }

    int m = 0;
    for (auto it : schools.get_data()) {
        if (it.second >= 1 && it.second <= 5) {
            m++;
        }
    }

    fout << m << std::endl;
    for (auto it : schools.get_data()) {
        if (it.second >= 1 && it.second <= 5) {
            fout << it.first << std::endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
