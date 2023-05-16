#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<int> stack;

public:
    void push(int x) {
        stack.push_back(x);
        cout << "ok" << endl;
    }

    void pop() {
        if (stack.empty()) {
            cout << "error" << endl;
        } else {
            cout << stack.back() << endl;
            stack.pop_back();
        }
    }

    void back() {
        if (stack.empty()) {
            cout << "error" << endl;
        } else {
            cout << stack.back() << endl;
        }
    }

    int size() {
        return stack.size();
    }

    void clear() {
        stack.clear();
        cout << "ok" << endl;
    }
};

int main() {
    Stack st;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "push") {
            int n;
            cin >> n;
            st.push(n);
        } else if (cmd == "pop") {
            st.pop();
        } else if (cmd == "back") {
            st.back();
        } else if (cmd == "size") {
            cout << st.size() << endl;
        } else if (cmd == "clear") {
            st.clear();
        } else if (cmd == "exit") {
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}
