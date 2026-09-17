#include <iostream>
using namespace std;

template<typename E>
class CLL{
   class Node{
      E data;
      Node* next;
      Node(E data){
         this->data=data;
         this->next=nullptr;
      }
      friend class CLL;
   };
   Node* head;
   Node* tail;
   public:
   CLL(){
      head=nullptr;
      tail=nullptr;
   }
   ~CLL(){clear();}
   bool empty(){
      return head==nullptr;
   }
   void insertFront(E data);
   void insertBack(E data);
   void insertAfter(E x, E y);

   void removeFront();
   void removeBack();
   void remove(E data);

   Node* search(E data);

   void display();
   void clear();
};

template<typename E>
void CLL<E>::insertFront(const E& data){
   
}


int main() {

    CLL<int> list;

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    list.display();

    list.insertFront(5);
    list.display();

    list.insertAfter(25, 20);
    list.display();

    list.removeFront();
    list.display();

    list.removeBack();
    list.display();

    list.remove(20);
    list.display();

    if (list.search(25) != nullptr)
        cout << "25 found\n";
    else
        cout << "25 not found\n";

    return 0;
}