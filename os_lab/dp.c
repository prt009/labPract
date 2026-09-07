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
        sleep(2);
    }
    else{
        printf("parent process\n");
        wait(NULL);
        printf("child's pid: %d\n",pid);
    }
    
    return 0;

}