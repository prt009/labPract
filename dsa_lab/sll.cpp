#include <iostream>

using namespace std;

template <typename E>
class Node{
   E data;
   Node<E>* next;
   Node(E data){
      this->data=data;
      this->next=nullptr;
   }
   template<typename U>
   friend class SLL;
};

template<typename E>
class SLL{
   Node<E>* head;
   public:
   SLL(){
      head=nullptr;
   }
   ~SLL(){
      while(head!=nullptr){
         removeHead();
      }
   }
   void insertHead(E data){
      Node<E>* newNode=new Node(data);
      newNode->next=head;
      head=newNode;
      cout<<"inserted "<<data<<" at the head\n";
   }
   void insertTail(E data){
      Node<E>* cursor=head;
      while(cursor->next!=nullptr){
         cursor=cursor->next;
      }
      Node<E>* newNode=new Node(data);
      cursor->next=newNode;
      cout<<"inserted "<<data<<" at the tail\n";
   }
   void insertAt(E data, int idx){
      Node<E>* cursor=head;
      for(int i=0;i<idx-1;i++){
         cursor=cursor->next;
      }
      Node<E>* newNode=new Node(data);
      newNode->next = cursor->next;
      cursor->next = newNode;
      cout<<"inserted "<<data<<" at the index "<<idx<<"\n";
   }
   void removeHead(){
      Node<E>* cursor=head;
      head=cursor->next;
      delete cursor;
   }
   void print(){
      Node<E>* cursor=head;
      while(cursor!=nullptr){
         cout<<cursor->data<<" ";
         cursor=cursor->next;
      }
   }   
};

int main(){

  SLL<int> list;

  list.insertHead(9);
  list.insertHead(8);
  list.insertHead(7);
  list.insertHead(5);
  
  list.insertTail(10);
  
  list.insertAt(6, 1);
  

  
  list.print();
  std::cout<<std::endl;
  
  
  return 0;
}
