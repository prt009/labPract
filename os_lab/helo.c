#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int fac;
int sum;
void *factorial(void *para);
void *summer(void *para);

int main(int argc, char *argv[]){
  pthread_t tid1;
  pthread_t tid2;
  pthread_attr_t attr;

}
