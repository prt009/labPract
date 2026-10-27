#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process{
    int pid,at,bt;
    int ct,tat,wt;
};

void sorrt(vector<Process> p, int i = 0){
    if (i==p.size()) return;
    for (int j= i+1;j<p.size();j++){
        if (p[j].at>p[i].at){
            swap(p[i],p[j]);
        }
    }
    sorrt(p, i+1);
}

int main(){
    vector<Process> p={
        {1,0,5},
        {2,2,3},
        {3,1,4}
    };
    // sort(
    //     p.begin(),
    //     p.end(),
    //     [](Process a, Process b) {
    //         return a.at < b.at;
    //     }
    // );
    sorrt(p, 3);
    
    int time=0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<p.size();i++){
        Process &x = p[i];
        if(time<x.at)time=x.at;
        time+=x.bt;
        x.ct=time;
        x.tat=x.ct-x.at;
        x.wt=x.tat-x.bt;
        cout<<"p"<<x.pid<<"\t"<<x.at<<"\t"<<x.bt<<"\t"<<x.ct<<"\t"<<x.tat<<"\t"<<x.wt<<"\n";
    }

    int tot_wait=0;
    int tot_tat=0;
    for(auto &x: p){
        tot_wait+=x.wt;
        tot_tat+=x.tat;
    }

    cout<<"avg waiting time:"<<tot_wait/p.size()<<endl;
    cout<<"avg turnaround time:"<<tot_tat/p.size()<<endl;


}
