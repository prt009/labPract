#include <iostream>
#include <vector>
using namespace std;
struct Process{
    int pid,at,bt,pr;
    int ct,tat,wt;
};
int main(){
    vector <Process> p = {
        {1,0,4,2},
        {2,2,2,3},
        {3,2,6,3}
    };
    int time=0;
    int comp=0;
    int n = p.size();
    vector<bool> done(n,false);
    while(comp<n){
        int highest=9999;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(!done[i] && p[i].at<=time){
                if(p[i].pr<highest || (p[i].pr==highest && p[i].at<p[idx].at)){
                    highest=p[i].pr;
                    idx=i;
                }
            }
        }
        if(idx==-1){
            time++;
            continue;
        }
        done[idx]=true;
        comp++;
        Process &x = p[idx];
        time+=x.bt;
        x.ct=time;
        x.tat = x.ct - x.at;
        x.wt = x.tat - x.bt;
    
    }
    
}