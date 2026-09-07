#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    pid=fork();

    if(pid<0){
        printf("forking failed.");
        exit(1);
    }

    if (pid==0){
        printf("child.\n");
        execlp("./ptd.out","ptd.out","10",NULL);
    }
    else{
        printf("parent process\n");
        printf("child's pid: %d\n",pid);
        wait(NULL);
        printf("complete.\n");
    }
    
    return 0;

}