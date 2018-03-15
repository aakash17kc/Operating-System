#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
void *gd(void *tf);
int a=1;
int main()
{
    pthread_h h1;
    pthread_create(&th1,NULL,tf,a);
    pthread_join(th1,NULL);
}