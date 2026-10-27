

#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid, at, bt, pr, ct, wt, tat;
};

int main() {
    vector<Process> p = {
        {1, 0, 4, 2},
        {2, 3, 2, 3},
        {3, 2, 6, 3}
    };

    int n = p.size(), time = 0, done = 0;

    while(done<n){
        int idx = -1;
        for (int i =0;i<n;i++)
            if(p[i].ct==0&&p[i].at<=time&&(idx==-1||p[i].pr<p[idx].pr ||(p[i].pr==p[idx].pr&& p[i].at<p[idx].at)))
                idx=i;
        
        if (idx==-1){
            time++;
            continue;
        }
        Process &x = p[idx];
        time+=x.bt;
        x.ct=time;
        x.tat=x.ct-x.at;
        x.wt=x.tat-x.bt;
        done++;
    }

    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto x : p)
        cout << x.pid<<'\t'<<x.at<<'\t'<<x.bt << '\t' << x.ct << '\t'
             << x.tat << '\t' << x.wt << '\n';
}
