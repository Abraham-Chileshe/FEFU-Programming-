#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deque {
public:
    void push_front(const string& val) {
        data_.insert(data_.begin(), val);
    }

    void push_back(const string& val) {
        data_.push_back(val);
    }

    void pop_front() {
        if (!empty()) {
            data_.erase(data_.begin());
        }
    }

    void pop_back() {
        if (!empty()) {
            data_.pop_back();
        }
    }

    string& front() {
        return data_.front();
    }

    string& back() {
        return data_.back();
    }

    bool empty() const {
        return data_.empty();
    }

    int size() const {
        return data_.size();
    }

    void clear() {
        data_.clear();
    }

private:
    vector<string> data_;
};

int main() {
    Deque d;
    string command;

    while (getline(cin, command)) {
        string cmd, arg;
        size_t pos = command.find(' ');
        if (pos != string::npos) {
            cmd = command.substr(0, pos);
            arg = command.substr(pos+1);
        } else {
            cmd = command;
        }

        if (cmd == "push_front") {
            d.push_front(arg);
            cout << "ok" << endl;
        } else if (cmd == "push_back") {
            d.push_back(arg);
            cout << "ok" << endl;
        } else if (cmd == "pop_front") {
            if (d.empty()) {
                cout << "error" << endl;
            } else {
                cout << d.front() << endl;
                d.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (d.empty()) {
                cout << "error" << endl;
            } else {
                cout << d.back() << endl;
                d.pop_back();
            }
        } else if (cmd == "front") {
            if (d.empty()) {
                cout << "error" << endl;
            } else {
                cout << d.front() << endl;
            }
        } else if (cmd == "back") {
            if (d.empty()) {
                cout << "error" << endl;
            } else {
                cout << d.back() << endl;
            }
        } else if (cmd == "size") {
            cout << d.size() << endl;
        } else if (cmd == "clear") {
            d.clear();
            cout << "ok" << endl;
        } else if (cmd == "exit") {
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}
