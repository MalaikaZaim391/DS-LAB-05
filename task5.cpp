//labelled task 6 in manual, but actually task 5
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    void enqueue(int x) {
        inStack.push(x);
    }

    int dequeue() {
        if (outStack.empty()) {
            if (inStack.empty()) {
                cout << "Queue Underflow!" << endl;
                return -1;
            }
            // Pour all elements from inStack to outStack to reverse order
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int val = outStack.top();
        outStack.pop();
        return val;
    }
};

int main() {
    MyQueue q;

    // Enqueue 'A' (65), 'B' (66)
    q.enqueue('A');
    q.enqueue('B');

    // Dequeue (Returns A)
    cout << "Dequeued: " << (char)q.dequeue() << endl;

    // Enqueue 'C' (67)
    q.enqueue('C');

    // Dequeue (Returns B)
    cout << "Dequeued: " << (char)q.dequeue() << endl;

    // Dequeue (Returns C)
    cout << "Dequeued: " << (char)q.dequeue() << endl;

    return 0;
}
