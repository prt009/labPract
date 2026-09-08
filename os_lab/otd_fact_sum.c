#include <iostream>
#include <pthread.h>
#include <cstdlib>
// #include <unistd.h>
// #include <sys/wait.h>
using namespace std;
int fac ;
int sum;
void *runner1(void *para);
void *runner2(void *para);
int main(int argc, char *argv[])
{

    pthread_t thread1;
    pthread_t thread2;
    pthread_attr_t attr;
    if(argc!=2){
        cerr<<" usage : a.out <integer value>"<<endl;
        return -1;
    }
    if(atoi(argv[1])<0){
        cerr<<" %d must be >= 0"<<endl<<atoi(argv[1])<<endl;
        return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&thread1, &attr, runner1, argv[1]);
    pthread_create(&thread2, &attr, runner2, argv[1]);

    pthread_join(thread1, NULL);
    pthread_join(thread2,NULL);

    cout << "Main function finished." << endl;

    return 0;
}
void *runner1(void *para){
    int i;
    int upper=atoi((char*)para);
    sum=0;
    for(i=1;i<=upper;i++){
        sum+=i;
    }
    cout<<"Sum is : "<<sum<<endl;
    pthread_exit(0);
}
void *runner2(void *para){
    int i;
    int upper=atoi((char*)para);
    fac=1;
    for(i=1;i<=upper;i++){
        fac*=i;
    }
    cout<<"Factorial is : "<<fac<<endl;
    pthread_exit(0);
}
