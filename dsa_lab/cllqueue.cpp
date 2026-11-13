
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename E>
class LinkedQueue {

    struct Node {
        E elem;
        Node* next;

        Node(const E& e) : elem(e), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int n;

public:

    LinkedQueue() : head(NULL), tail(NULL), n(0) {}

    ~LinkedQueue() {
        while (!empty()) {
            dequeue();
        }
    }

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    const E& front() const {
        if (empty())
            throw runtime_error("Queue is empty");

        return head->elem;
    }

    const E& back() const {
        if (empty())
            throw runtime_error("Queue is empty");

        return tail->elem;
    }

    void enqueue(const E& e) {

        Node* v = new Node(e);

        if (empty()) {
            head = tail = v;
        }
        else {
            tail->next = v;
            tail = v;
        }

        n++;
    }

    void dequeue() {

        if (empty())
            throw runtime_error("Queue is empty");

        Node* old = head;

        head = head->next;

        delete old;

        n--;

        if (empty())
            tail = NULL;
    }

    void display() const {

        if (empty()) {
            cout << "Empty\n";
            return;
        }

        Node* curr = head;

        while (curr != NULL) {
            cout << curr->elem << " ";
            curr = curr->next;
        }

        cout << endl;
    }
};

int main() {

    LinkedQueue<int> Q;

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);

    Q.display();

    Q.dequeue();

    cout << "Front: " << Q.front() << endl;
    cout << "Back: " << Q.back() << endl;

    Q.enqueue(40);

    Q.display();

    return 0;
}
