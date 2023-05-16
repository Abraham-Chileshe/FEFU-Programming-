#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x): data(x), next(nullptr) {}
};

struct Queue {
    Node* front;
    Node* rear;
    int size;
    Queue(): front(nullptr), rear(nullptr), size(0) {}
    void push(int x) {
        Node* temp = new Node(x);
        size++;
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void pop() {
        if (front == nullptr) {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
    }
    int frontValue() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }
    int getSize() {
        return size;
    }
    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
    }
};

int main() {
    Queue q;
    string command;
    int n;
    while (cin >> command) {
        if (command == "push") {
            cin >> n;
            q.push(n);
            cout << "ok" << endl;
        } else if (command == "pop") {
            if (q.getSize() == 0) {
                cout << "error" << endl;
            } else {
                cout << q.frontValue() << endl;
                q.pop();
            }
        } else if (command == "front") {
            if (q.getSize() == 0) {
                cout << "error" << endl;
            } else {
                cout << q.frontValue() << endl;
            }
        } else if (command == "size") {
            cout << q.getSize() << endl;
        } else if (command == "clear") {
            q.clear();
            cout << "ok" << endl;
        } else if (command == "exit") {
            cout << "bye" << endl;
            break;
        }
    }
    return 0;
}
