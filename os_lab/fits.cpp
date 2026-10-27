#include <iostream>
#include <vector>
using namespace std;

void firstfit(vector<int> blocks, vector<int> procs){
   int n= blocks.size();
   int m= procs.size();
   vector<int> alloc(m,-1);

   for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
         if(blocks[j]>=procs[i]){
            alloc[i]=j;
            blocks[j]-=procs[i];
            break;
         }
      }
   }

   cout<<"\nFirst fit alloc:";
   cout<<"\nProcess\tSize\tBlock\n";

   for (int i =0; i<m; i++) {
      cout<<i+1<<"\t"<<procs[i]<<"\t";
      if (alloc[i]!=-1){
         cout<<alloc[i]+1;
      }else{
         cout<<"not allocated";
      }
      cout<<endl;
   }

}

void bestfit(vector<int> blocks, vector<int> procs){
   int n= blocks.size();
   int m= procs.size();
   vector<int> alloc(m,-1);

   for(int i=0;i<m;i++){
      int best=-1;
      for(int j=0;j<n;j++){
         if(blocks[j]>=procs[i]){
            if(best==-1||blocks[j]<blocks[best]) best=j;
         }
      }
      if(best!=-1){
         alloc[i]=best;
         blocks[best]-=procs[i];
      }  
      
   }

   cout<<"\nBest fit alloc:";
   cout<<"\nProcess\tSize\tBlock\n";

   for (int i =0; i<m; i++) {
      cout<<i+1<<"\t"<<procs[i]<<"\t";
      if (alloc[i]!=-1){
         cout<<alloc[i]+1;
      }else{
         cout<<"not allocated";
      }
      cout<<endl;
   }

}

void worstfit(vector<int> blocks, vector<int> procs){
   int n= blocks.size();
   int m= procs.size();
   vector<int> alloc(m,-1);

   for(int i=0;i<m;i++){
      int worst=-1;
      for(int j=0;j<n;j++){
         if(blocks[j]>=procs[i]){
            if(worst==-1||blocks[j]>blocks[worst]) worst=j;
         }
      }
      if(worst!=-1){
         alloc[i]=worst;
         blocks[worst]-=procs[i];
      }  
      
   }

   cout<<"\nWorst fit alloc:";
   cout<<"\nProcess\tSize\tBlock\n";

   for (int i =0; i<m; i++) {
      cout<<i+1<<"\t"<<procs[i]<<"\t";
      if (alloc[i]!=-1){
         cout<<alloc[i]+1;
      }else{
         cout<<"not allocated";
      }
      cout<<endl;
   }

}


int main(){
   vector<int> p={212,417,112,426};
   vector<int> b={100,500,200,300,600};
   firstfit(b, p);
   bestfit(b, p);
   worstfit(b, p);

   return 0;
}
