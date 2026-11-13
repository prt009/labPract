
#include <iostream>
using namespace std;

template <typename T>
class Deque {
    T arr[5];
    int frontIndex, count;
    const int capacity = 5;

public:
    Deque(){
        frontIndex = 0;
        count = 0;
    }

    bool empty(){
        return count == 0;
    }

    bool full(){
        return count == capacity;
    }

    void insertFront(T x){
        if (full()){
            cout << "Deque Overflow\n";
            return;
        }

        if (empty()){
            frontIndex = 0;
        }else{
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        arr[frontIndex] = x;
        count++;

        cout << x << " inserted at front\n";
    }

    void insertRear(T x){
        if (full()){
            cout << "Deque Overflow\n";
            return;
        }

        int rearIndex = (frontIndex + count) % capacity;
        arr[rearIndex] = x;
        count++;

        cout << x << " inserted at rear\n";
    }

    void deleteFront(){
        if (empty()){
            cout << "Deque Underflow\n";
            return;
        }

        cout << arr[frontIndex] << " deleted from front\n";
        frontIndex = (frontIndex + 1) % capacity;
        count--;

        if (empty())
            frontIndex = 0;
    }

    void deleteRear(){
        if (empty()){
            cout << "Deque Underflow\n";
            return;
        }

        int rearIndex = (frontIndex + count - 1) % capacity;
        cout << arr[rearIndex] << " deleted from rear\n";
        count--;
    }

    void display(){
        if (empty()){
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main(){
    Deque<int> d;
    int choice, x;

    do {
        cout << "\n1. Insert Front\n2. Insert Rear\n";
        cout << "3. Delete Front\n4. Delete Rear\n";
        cout << "5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter element: ";
                cin >> x;
                d.insertFront(x);
                break;

            case 2:
                cout << "Enter element: ";
                cin >> x;
                d.insertRear(x);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.deleteRear();
                break;

            case 5:
                d.display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
