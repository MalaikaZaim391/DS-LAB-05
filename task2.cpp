#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(const string& word) {
        undoStack.push(word);
        // Clear redo history when new typing occurs
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo." << endl;
            return;
        }
        string word = undoStack.top();
        undoStack.pop();
        redoStack.push(word);
    }

    void redo() {
        if (redoStack.empty()) {
            return; // Redo does nothing if no history exists
        }
        string word = redoStack.top();
        redoStack.pop();
        undoStack.push(word);
    }

    void print() {
        // Transfer to temp stack to iterate from bottom to top
        stack<string> temp = undoStack;
        stack<string> reverseStack;

        while (!temp.empty()) {
            reverseStack.push(temp.top());
            temp.pop();
        }

        cout << "Document state: \"";
        bool first = true;
        while (!reverseStack.empty()) {
            if (!first) cout << " ";
            cout << reverseStack.top();
            reverseStack.pop();
            first = false;
        }
        cout << "\"" << endl;
    }
};

int main() {
    TextEditor editor;

    editor.type("Hello");
    editor.print();

    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo(); // Should do nothing
    editor.print();

    return 0;
}
