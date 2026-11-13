
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename E>
class ArrayQueue {
    E* Q;
    int capacity;
    int front;
    int rear;
    int n;

public:
    ArrayQueue(int cap = 100)
        : capacity(cap), front(0), rear(0), n(0) {
        Q = new E[capacity];
    }

    ~ArrayQueue() {
        delete[] Q;
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    const E& frontElement() const {
        if (empty())
            throw runtime_error("Queue is empty");

        return Q[front];
    }

    const E& back() const {
        if (empty())
            throw runtime_error("Queue is empty");

        return Q[(rear - 1 + capacity) % capacity];
    }

    void enqueue(const E& e) {
        if (n == capacity)
            throw runtime_error("Queue is full");

        Q[rear] = e;
        rear = (rear + 1) % capacity;
        n++;
    }

    void dequeue() {
        if (empty())
            throw runtime_error("Queue is empty");

        front = (front + 1) % capacity;
        n--;
    }

    void display() const {
        if (empty()) {
            cout << "Empty\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << Q[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayQueue<int> Q(5);

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);

    Q.display();

    Q.dequeue();

    cout << "Front: " << Q.frontElement() << endl;
    cout << "Rear: " << Q.back() << endl;

    Q.enqueue(50);
    Q.enqueue(60);

    Q.display();

    return 0;
}
