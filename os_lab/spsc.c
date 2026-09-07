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

    printf("hello\n");
    execlp("ls","ls",NULL);
    return 0;

}