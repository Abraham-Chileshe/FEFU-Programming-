#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class MyStack {
private:
    T* data;
    int capacity;
    int size;

public:
    MyStack() {
        capacity = 10;
        data = new T[capacity];
        size = 0;
    }

    ~MyStack() {
        delete[] data;
    }

    void push(T value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void pop() {
        if (size > 0) {
            size--;
        }
    }

    T top() {
        if (size > 0) {
            return data[size - 1];
        } else {
            throw runtime_error("Stack is empty");
        }
    }

    bool empty() {
        return size == 0;
    }

    void resize() {
        T* newData = new T[capacity * 2];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity *= 2;
    }
};

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        output << "ERROR";
        return 0;
    }

    MyStack<int> s;
    vector<int> v;

    string line;
    while (getline(input, line)) {
        if (line.empty()) {
            break;
        }

        if (line[0] == '+') {
            int num = stoi(line.substr(1));
            s.push(num);
        } else if (line == "-") {
            if (s.empty()) {
                output << "ERROR";
                return 0;
            }
            s.pop();
        } else {
            output << "ERROR";
            return 0;
        }
    }

    if (s.empty()) {
        output << "EMPTY";
    } else {
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            output << v[i] << " ";
        }
    }

    return 0;
}
