#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char pwd[200];
void *runner(void *param);


int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);

    printf("working directory= %d\n",pwd);

    return 0;
}

void *runner( void *param){
    getcwd(pwd,sizeof(pwd));

    pthread_exit(0);
}


