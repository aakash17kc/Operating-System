#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
int student[]={0,1,2,3,4,5,6,7,8,9};
int faculty[]={0,1,2,3,4};
void *gd(void *tf);
int a=1;
int main()
{
    /*char user[10]="akc";
    int pass=977;
    printf("Enter username for UNIX system");
    char username[10];
    scanf("%[^\n]", &username);
    while(user!=username){
    	printf("Try again\n");
    	scanf("%[^\n]", &username);
    }
    printf("Enter password");
    int password;
    scanf("%d\n", &password);
    while(password!=pass){
    	printf("Try again\n");
    	scanf("%d\n", &password);
    }*/
    time_t t;   // not a primitive datatype
    time(&t);

    printf("\nThis program has been writeen at (date and time): %s", ctime(&t));;

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
   /* return 0;
    pthread_h h1;
    pthread_create(&th1,NULL,tf,a);
    pthread_join(th1,NULL);*/
}
