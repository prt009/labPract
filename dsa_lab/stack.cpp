#include <iostream>
using namespace std;

template <typename E>
class LinkedList;

template <typename E>
class Node {
private:
    E elem;
    Node<E>* next;

    friend class LinkedList<E>;
};

template <typename E>
class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
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

    void addFront(const E& e) {
        Node<E>* v = new Node<E>;
        v->elem = e;
        v->next = head;
        head = v;
    }

    void removeFront() {
        if (empty())
            return;

        Node<E>* old = head;
        head = head->next;
        delete old;
    }

    void print() const {
        Node<E>* current = head;

        while (current != NULL) {
            cout << current->elem << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node<E>* head;
};

template <typename E>
class Stack {
public:
    bool empty() const {
        return list.empty();
    }

    void push(const E& e) {
        list.addFront(e);
    }

    void pop() {
        if (empty()) {
            cout << "Stack is empty\n";
            return;
        }

        list.removeFront();
    }

    const E& top() const {
        return list.front();
    }

    void print() const {
        list.print();
    }

private:
    LinkedList<E> list;
};

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.print();

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "After pop: ";
    s.print();

    return 0;
}