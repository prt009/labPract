#include <iostream>
#include <vector>
using namespace std;

struct Process{
    int pid,at,bt;
    int ct,tat,wt;
};

int main(){
    vector<Process> p = {
        {1, 2, 6},
        {2, 5, 3},
        {3, 1, 4}
    };
 
    int n=p.size();
    int comp=0;
    vector<bool> done(n,false);
    int time=0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";

    while (comp<n){
        int shortest=9999;
        int idx=-1;
        for(int i=0;i<n;i++){
            if (!done[i] && p[i].at<=time){
                if (p[i].bt < shortest) {
                    shortest = p[i].bt;
                    idx = i;
                }
            }
        }
        if (idx== -1){
            time++;
            continue;
        }
        done[idx]=true;
        comp++;
        Process &x=p[idx];
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