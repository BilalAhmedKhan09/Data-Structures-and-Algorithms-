#include <iostream>

using namespace std;
#define MAX_SIZE 5

struct Call {
    string callerName;
    string phoneNumber;
    int callDuration;
};

class CallStack {
    Call calls[MAX_SIZE];
    int currentTop;
public:
    CallStack() { currentTop = -1; }

    bool isEmpty() { return currentTop == -1; }

    void push(string name, string number, int duration) {
        if (currentTop == MAX_SIZE - 1) {
            cout << "Stack is full, cannot add more calls.\n";
            return;
        }
        calls[++currentTop] = {name, number, duration};
    }

    void pop() {
        if (isEmpty()) {
            cout << "No calls to pop.\n";
            return;
        }
        currentTop--;
    }

    void showTop() {
        if (isEmpty()) {
            cout << "No calls in the stack.\n";
            return;
        }
        cout << "Top call: " << calls[currentTop].callerName << " " << calls[currentTop].phoneNumber << " " << calls[currentTop].callDuration << " mins\n";
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "No calls in the stack.\n";
        } else {
            cout << "Calls in the stack:\n";
            for (int i = currentTop; i >= 0; i--) {
                cout << calls[i].callerName << " " << calls[i].phoneNumber << " " << calls[i].callDuration << " mins\n";
            }
        }
    }
};

int main() {
    CallStack stack;
    
    stack.push("Luckky", "100", 5);
    stack.push("Bilal", "500", 3);
    stack.displayAll();
    stack.showTop();
    stack.pop();
    stack.displayAll();
}
