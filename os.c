#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int i=0,j=0,count1=0,count2=0;
int quant_queue=8;
int quant_data=3;

int student[]; int faculty[];
struct node1{
  int info1;
  node *next1;
}*start1=NULL;

struct node2{
  int info2;
  node *next2;
}*start2=NULL;

void create1(){
  start1 = new node;
printf("Enter data-value for 1st student: ");
scanf("%d\n",start1->info );
start1->next1 = NULL;
}

void insert1(node *pt) // pt for traversing
{
while(pt->next1!=NULL)
 {
 pt = pt->next1;
 }
node *temp = new node;
scanf("%d\n"temp->info1);
temp->next1 = NULL;
p1->next1 = temp;
}

void create2(){
  start2 = new node;
printf("Enter data-value for student: %d\n",i+1);
scanf("%d\n", start2->info);
start2->next2 = NULL;

}

void insert2(node *pt)
{
while(pt->next2!=NULL)
 {
 pt = pt->next2;
 }
node *temp = new node;
printf("Enter data-value for student: %d\n",i+1);
scanf("%d\n"temp->info2);
temp->next2 = NULL;
p1->next2 = temp;
}

void average_time(){

}

int main(){
  //Student deatils
printf("Enter no of students ");
int stu,burst_stu;
scanf("%d",&stu);
printf("Enter burst time for every student ");
for(i=0;i<stu;i++)
{
  if(i=0)
  create1(start1);
  insert1(start1);
  count1++;
  student[i]=count1;
}

printf("Enter no of faculties ");
int fac,burst_fac;
scanf("%d",&stu);
printf("Enter burst time for every faculty ");
for(i=0;i<fac;i++)
{
  if(i=0)
  create2(start2);
  insert2(start2);
  count2++;
  faculty[i]=count2;

}

long int size1=sizeof(int);// long unsigned int
long int size2=size;// long unsigned int

average_time(start1,size1,student,quant_data);


}
