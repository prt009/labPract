#include <iostream>
using namespace std;

typedef string E;
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
   Node* cursor;
   public:
   CLL(){
      cursor=nullptr;
   }
   ~CLL(){while (!empty()) {
      remove();
   }}
   bool empty(){
      return cursor==nullptr;
   }
   const E& front() const;
   const E& back() const;
   void advance();
   void add(const E& e);
   void remove();
   const int count() const;
};

const int CLL::count() const{
   if (cursor==nullptr){
      return 0;
   }
   Node* temp= cursor->next;
   int c=1;
   while(temp!=cursor){
      c++;
      temp=temp->next;
   }
   return c;
}

const E& CLL::back() const{
   return cursor->data;
}

const E& CLL::front() const{
   return cursor->next->data;
}

void CLL::advance(){
   cursor=cursor->next;
}

void CLL::add(const E& e){
   Node* v=new Node(e);
   if (cursor==nullptr){
      v->next=v;
      cursor=v;
   }else{
      v->next=cursor->next;
      cursor->next=v;
   }
}

void CLL::remove(){
   Node* old=cursor->next;
   if (old==cursor){
      cursor=nullptr;
   }else{
      cursor->next=old->next;
   }
   delete old;
}

int main(){
   CLL plist;
   plist.add("staying alive");
   plist.add("loser");
   plist.add("lovesong");
   cout<<plist.front();
   plist.advance();
   cout<<plist.front();
   plist.remove();
   cout<<plist.count();
   return 0;
}