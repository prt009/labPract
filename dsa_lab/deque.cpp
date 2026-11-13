#include <iostream>
using namespace std;

template <typename E>
class Deque;

template <typename E>
class DNode {
private:
    E elem;
    DNode<E>* prev;
    DNode<E>* next;

    friend class Deque<E>;
};

template <typename E>
class Deque {
public:
    Deque() {
        head = NULL;
        tail = NULL;
    }

    ~Deque() {
        while (!empty()) {
            removeFront();
        }
    }

    bool empty() const {
        return head == NULL;
    }

    const E& front() const {
        return head->elem;
    }

    const E& back() const {
        return tail->elem;
    }

    void addFront(const E& e) {
        DNode<E>* v = new DNode<E>;
        v->elem = e;
        v->prev = NULL;
        v->next = head;

        if (empty()) {
            tail = v;
        } else {
            head->prev = v;
        }

        head = v;
    }

    void addBack(const E& e) {
        DNode<E>* v = new DNode<E>;
        v->elem = e;
        v->next = NULL;
        v->prev = tail;

        if (empty()) {
            head = v;
        } else {
            tail->next = v;
        }

        tail = v;
    }

    void removeFront() {
        if (empty())
            return;

        DNode<E>* old = head;
        head = head->next;

        if (head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }

        delete old;
    }

    void removeBack() {
        if (empty())
            return;

        DNode<E>* old = tail;
        tail = tail->prev;

        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }

        delete old;
    }

    void print() const {
        DNode<E>* current = head;

        while (current != NULL) {
            cout << current->elem << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    DNode<E>* head;
    DNode<E>* tail;
};

int main() {
    Deque<int> d;

    d.addFront(20);
    d.addFront(10);
    d.addBack(30);
    d.addBack(40);

    cout << "Deque: ";
    d.print();

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    d.removeFront();

    cout << "After removing front: ";
    d.print();

    d.removeBack();

    cout << "After removing back: ";
    d.print();

    return 0;
}
