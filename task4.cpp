//labelled task 5 in manual, but actually task 4
#include <iostream>
using namespace std;

#define MAX 6

class BoardingQueue {
private:
    int front, rear;
    int a[MAX];

public:
    BoardingQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int passengerID) {
        if (isFull()) {
            cout << "Queue full! Cannot admit passenger " << passengerID << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        a[rear] = passengerID;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty!" << endl;
            return -1;
        }
        int item = a[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        return item;
    }

    void displayBoardingOrderAndIndices() {
        if (isEmpty()) {
            cout << "No passengers left in queue." << endl;
            return;
        }

        cout << "Final passengers in boarding order: ";
        int i = front;
        while (true) {
            cout << a[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << "\nFinal Front Position: " << front << endl;
        cout << "Final Rear Position: " << rear << endl;
    }
};

int main() {
    BoardingQueue q;

    // 1. Initial passengers enter: 101, 102, 103, 104, 105, 106
    int initial[] = {101, 102, 103, 104, 105, 106};
    for (int p : initial) q.enqueue(p);

    // 2. First 3 passengers board
    for (int i = 0; i < 3; i++) q.dequeue();

    // 3. Passengers 107, 108, 109 arrive
    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    // 4. 2 passengers board
    for (int i = 0; i < 2; i++) q.dequeue();

    // 5. Passenger 110 arrives
    q.enqueue(110);

    // 6. 1 passenger boards
    q.dequeue();

    // 7. Passengers 111 and 112 arrive
    q.enqueue(111);
    q.enqueue(112);

    // Display state
    q.displayBoardingOrderAndIndices();

    return 0;
}
