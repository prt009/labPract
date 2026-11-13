#include <iostream>
using namespace std;

void insert(int arra[],int &len,int capacity,int pos, int value){
    if(len ==capacity||pos<0||pos>len){
        return;
    }
    for(int i =len;i>pos;i--){
        arra[i]=arra[i-1];
    }
    arra[pos]=value;
    len++;
}

int main(){
    const int s=200;
    int n=5;
    int arr[s]={1,2,3,4,5};

    insert(arr, n, s, 2, 6);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    
    return 0;
}