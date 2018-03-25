#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
int student[]={0,1,2,3,4,5,6,7,8,9};
int faculty[]={0,1,2,3,4};
void *gd(void *tf);
int a=1;
int main()
{
    pthread_h h1;
    pthread_create(&th1,NULL,tf,a);
    pthread_join(th1,NULL);
}
