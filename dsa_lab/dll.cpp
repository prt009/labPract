#include <iostream>

using namespace std;

template<typename E>
class DLL{
   class Node{
      E data;
      Node* next;
      Node* prev;
      Node(E data){
         this->data=data;
         this->next=nullptr;
         this->prev=nullptr;
      }
      friend class DLL;
   };
   Node* head;
   Node* tail;
   public:
   DLL(){
      head=new Node(E{});
      tail=new Node(E{});
      head->next=tail;
      tail->prev=head;
   }
   ~DLL(){
      while(!empty()){
         removeFront();
      }
      delete head;
      delete tail;
   }
   bool empty(){
      return head->next==tail;
   }
   void addFront(E data){
      Node* newNode=new Node(data);
      newNode->next=head->next;
      newNode->prev=head;

      head->next->prev=newNode;
      head->next=newNode;
   }
   void addBack(E data){
      Node* newNode=new Node(data);
      newNode->prev=tail->prev;
      newNode->next=tail;

      tail->prev->next=newNode;
      tail->prev=newNode;
   }
   void displayForward(){
      Node* cursor=head->next;
      while(cursor!=tail){
         cout<<cursor->data<<" ";
         cursor=cursor->next;
      }
      cout<<endl;
   }
   void displayBackward(){
      Node* cursor=tail->prev;
      while(cursor!=head){
         cout<<cursor->data<<" ";
         cursor=cursor->prev;
      }
      cout<<endl;
   }
   void removeBack(){
      if(empty())return;
      Node* temp=tail->prev;
      temp->prev->next=tail;
      tail->prev=temp->prev;
      delete temp;
   }
   void removeFront(){
      if(empty())return;
      Node* temp=head->next;
      temp->next->prev=head;
      head->next=temp->next;
      delete temp;
   }
};

int main()
{
    DLL<string> strlist;
    strlist.addFront("hello");
    strlist.addBack("world");
    strlist.addBack("i");
    strlist.addBack("am");
    strlist.addBack("ready");
    strlist.addFront("heyy");
   //  strlist.addatpos("23", 100);
    strlist.removeFront();
    strlist.removeBack();
   //  strlist.removeatpos(2);
    strlist.displayForward();

    DLL<int> intlist;

    intlist.addFront(30);
    intlist.addFront(20);
    intlist.addFront(10);

    intlist.addBack(40);
    intlist.addBack(50);

    cout << "Forward: ";
    intlist.displayForward();

    cout << "Backward: ";
    intlist.displayBackward();

    intlist.removeFront();
    intlist.removeBack();

    cout << "After deletion:\n";

    cout << "Forward: ";
    intlist.displayForward();

    cout << "Backward: ";
    intlist.displayBackward();

    return 0;
}

