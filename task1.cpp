#include <iostream>
using namespace std;

#define MAX_CAPACITY 8

class OperationStack {
private:
    int top;
    int stack[MAX_CAPACITY];

public:
    OperationStack() {
        top = -1;
    }

    bool isFull() {
        return top >= MAX_CAPACITY - 1;
    }

    bool isEmpty() {
        return top < 0;
    }

    void performOperation(int opCode) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot store operation " << opCode << endl;
            return;
        }
        stack[++top] = opCode;
        cout << "Performed operation: " << opCode << " | Current Top: " << peek() << endl;
    }

    void undo() {
        if (isEmpty()) {
            cout << "Undo failed: Stack is empty! No operations to undo." << endl;
            return;
        }
        int undoneOp = stack[top--];
        cout << "Undone operation: " << undoneOp;
        if (!isEmpty()) {
            cout << " | Current Top: " << peek() << endl;
        } else {
            cout << " | Stack is now empty." << endl;
        }
    }

    int peek() {
        if (isEmpty()) return -1;
        return stack[top];
    }

    void displayRemaining() {
        if (isEmpty()) {
            cout << "\nNo remaining operations in stack." << endl;
            return;
        }
        cout << "\nRemaining operations in stack (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    OperationStack editor;

    // Performing operations: 12, 25, 17, 31, 44, 19
    int initialOps[] = {12, 25, 17, 31, 44, 19};
    for (int op : initialOps) {
        editor.performOperation(op);
    }

    // Press Undo 3 times
    cout << "\n--- User presses Undo 3 times ---" << endl;
    editor.undo();
    editor.undo();
    editor.undo();

    // Perform new operation 52
    cout << "\n--- User performs new operation 52 ---" << endl;
    editor.performOperation(52);

    // Press Undo 2 times
    cout << "\n--- User presses Undo 2 times ---" << endl;
    editor.undo();
    editor.undo();

    // Display remaining operations
    editor.displayRemaining();

    return 0;
}
