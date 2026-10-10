#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<string> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) {
        return;
    }

    stack<string> s;

    // 1. Dequeue first k elements and push onto stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // 2. Pop from stack and enqueue back to queue (reverses them)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // 3. Move the remaining (size - k) elements to the back of the queue
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<string> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<string> q;
    q.push("J1");
    q.push("J2");
    q.push("J3");
    q.push("J4");
    q.push("J5");
    q.push("J6");
    q.push("J7");

    cout << "Original Queue: ";
    printQueue(q);

    int k = 3;
    reverseFirstK(q, k);

    cout << "After reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}
