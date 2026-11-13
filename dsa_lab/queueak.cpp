
#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T arr[5];
    int frontIndex, rearIndex, count;
    const int capacity = 5;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool empty() {
        return count == 0;
    }

    bool full() {
        return count == capacity;
    }

    void enqueue(T x) {
        if (full()) {
            cout << "Queue Overflow\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;

        cout << x << " inserted\n";
    }

    void dequeue() {
        if (empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[frontIndex] << " deleted\n";
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    T front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return T();
        }
        return arr[frontIndex];
    }

    void display() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q;
    int choice, x;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n";
        cout << "3. Front\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                q.enqueue(x);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                if (!q.empty())
                    cout << "Front element: " << q.front() << endl;
                else
                    cout << "Queue is empty\n";
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
