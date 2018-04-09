#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool student_finish=false;
bool faculty_finish=false;
int burst2 = 0;
int i=0;
int wait_time_faculty( int burst_faculty[], int rburst_faculty[], int f1, int wait_faculty[], int quant_data, int quantum, int t )
  { int ft=0;int count=0;

  bool done = false;
  
  for (i = 0 ; i < f1; i++)
  count += burst_faculty[i];

  
    while(ft < quantum && faculty_finish == false)
    {


    for (i = 0 ; i < f1; i++)
    {
  
      if (rburst_faculty[i] > 0)
      {      

        if (rburst_faculty[i] >= quant_data)
        {
          // adding burst to total time may or mat not exceed the queue burst 
          //check if adding exceeds queue burst
    
          if((ft + quant_data) >= quantum)
     		 {
			  
     		 if((ft + quant_data) > quantum){
     		 	
              ft += quant_data;
              burst2 += quant_data;
              
              
        		int z= quantum - ft;
              rburst_faculty[i] -= z;
              
              t += t + z;
              if(rburst_faculty[i] == 0){
              	
              	wait_faculty[i] = t - burst_faculty[i];
              	
			  }
              if(count==burst2){
    		faculty_finish == true;
			}
				}
              
            if((ft + quant_data) == quantum){
            	
              ft += quant_data;
              t += quant_data;
              burst2 += quant_data;
              
              if(rburst_faculty[i] == 0){
              	
              	wait_faculty[i] = t - burst_faculty[i];
              	
			  }
              
              
              rburst_faculty[i]-=quant_data;
			if(count==burst2){
   				faculty_finish == true;
			}
            }

            
            }
          else{
            rburst_faculty[i] -= quant_data;
            ft += quant_data;
            t += quant_data; 
            burst2 += quant_data;
            if(rburst_faculty[i] == 0){
              	
              	wait_faculty[i] = t - burst_faculty[i];
              	
			  }
  
	  if(count==burst2){
    		faculty_finish == true;
			}   
          }
          
  		}
        else{

          t = t + rburst_faculty[i];
          burst2 += rburst_faculty[i];          
          ft += rburst_faculty[i];
          wait_faculty[i] = t - burst_faculty[i];
          if(count==burst2){
				
    		faculty_finish == true;
    		done = true;
			}
          rburst_faculty[i] = 0;
            }
        }
      
    }
    if(ft>=quantum && student_finish == true){
	
    ft = 0;
}
    if(count==burst2){
    	
    	faculty_finish == true;
	}
	if(done = true){
	
	break;
}
}return t;

  }
  



void waiting( int s1,int f1, int burst_student[],int burst_faculty[],
                 int quant_data, int wait_student[],int wait_faculty[], int quantum)
{
  
  int rburst_student[s1];
  int rburst_faculty[f1];
  int burst_f[f1];

int count=0,burst=0;
  for (i = 0 ; i < f1; i++){
  
  count += burst_student[i];
  rburst_student[i] = burst_student[i];
  rburst_faculty[i] = burst_faculty[i];
  burst_f[i] = burst_faculty[i];
  wait_faculty[i] = 0;}


  int t = 0;
  int st=0;
  // round robin 

  while (1 && student_finish == false)
  {
   
    bool done = true;

    for (i = 0 ; i < s1; i++)
    {

      if (rburst_student[i] > 0)
      {
        done = false; 

        if (rburst_student[i] >= quant_data)
        {

          // adding burst to total time may or mat not exceed the queue burst 
          //check if adding exceeds queue burst
          if((st + quant_data >= quantum))
      {		
            if((st + quant_data) == quantum)
      {		
              st += quant_data;
              t += quant_data;
              burst += quant_data;
              
              rburst_student[i] -= quant_data;
              if(rburst_student[i] == 0){
              	
              	wait_student[i] = t - burst_student[i];
			  }
              t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
              if(count==burst){
      			student_finish=true;
				  		
              if(faculty_finish==false){
			  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				} 
				else{
					
				}}
				
			  
              st = 0;
              
            }
            if((st + quant_data) > quantum){
            	
              st += quant_data;
              int z = quantum - st;
              burst += quant_data;
              
              
              
              rburst_student[i] -= z;
              t += z;
              t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
              if(count==burst){
      			student_finish=true;	  			
              if(faculty_finish==false){				  		  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				} 
				}
              st = 0;
            }
            
          }
          

          else{
            rburst_student[i] -= quant_data;
            st += quant_data;
            burst += quant_data;
            
            if(rburst_student[i] == 0){
              	
              	wait_student[i] = t - burst_student[i];
			  }
            
             t += quant_data;
            if(count==burst){
      			student_finish=true;	  			
              
			if(faculty_finish==false){					  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				}
				   }    
          }
      }
          //burst time is smaller than or equal to quan_data
            else{
          t = t + rburst_student[i];
          st += rburst_student[i];
          burst += rburst_student[i];
          
          wait_student[i] = t - burst_student[i];
          
          rburst_student[i] = 0;
          if(count==burst){
      			student_finish=true;  
				       
          if(faculty_finish==false){		  	  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				}
			}
            }
        }
        
      }
      if(count==burst){
      	student_finish=true;
	  }
      if (done == true)
      break;
    }
    
    } 

void turn_around(int s1,int f1,int burst_student[],
                        int burst_faculty[],int wait_student[],int wait_faculty[],int turn_student[],int turn_faculty[])
{
 
  for (i = 0; i < s1 ; i++)
    turn_student[i] = burst_student[i] + wait_student[i];

  for (i = 0; i < f1 ; i++)
    turn_faculty[i] = burst_faculty[i] + wait_faculty[i];
}


void average(int s1,int f1, int burst_student[],int burst_faculty[],
                 int quant_data,int quantum)
{
  int wait_student[s1], wait_faculty[f1],turn_student[s1], turn_faculty[f1] ;
  int total_wait_student = 0, total_wait_faculty=0,  total_turn_student = 0, total_turn_faculty=0;

  waiting(s1,f1, burst_student,burst_faculty,quant_data,wait_student,wait_faculty, quantum);
  turn_around( s1,f1, burst_student,burst_faculty,wait_student,wait_faculty, turn_student, turn_faculty);

  printf("Processing details for Students\n");
  printf("\n\n\n  Processes \t Burst-time \t Waiting time \t Turn around time\n\n");

  // total waiting time and total turn around time
  
  for (i=0; i<s1; i++)
  {
    total_wait_student = total_wait_student + wait_student[i];
    total_turn_student = total_turn_student + turn_student[i];
    printf("\t%d \t ",i+1); printf("\t%d \t ",burst_student[i]);printf("\t%d \t ",wait_student[i]);printf("\t%d",turn_student[i]);
    printf("\n");
  }
  printf("\n");
  printf("Average waiting time = %f\n", ((float)total_wait_student / (float)s1));
  printf("Average turn around time = %f\n", ((float)total_turn_student / (float)s1));
  printf("\n");
  printf("\n");
  printf("Processing details for Faculties\n");

  printf("\n\n\n  Processes \t Burst-time \t Waiting time \t Turn around time\n\n");

	printf("\n");
  for (i=0; i < f1; i++)
  {
    total_wait_faculty = total_wait_faculty + wait_faculty[i];
    total_turn_faculty = total_turn_faculty + turn_faculty[i];
    printf("\t%d \t ",i+1); printf("\t%d \t ",burst_faculty[i]);	printf("\t%d \t ",wait_faculty[i]); printf("\t%d \t ",turn_faculty[i]);
	printf("\n");      
  }

  printf("\n");
  printf("Average waiting time = %f\n", ((float)total_wait_faculty / (float)f1),"\n");
  printf("Average turn around time = %f\n", ((float)total_turn_faculty / (float)f1), "\n");

}

int main()
{
 
  
  printf("Program to handle student and faculty queries\n");
  printf("Enter number of students and faculties \n");
  
  int n1,n2;
  scanf("%d",&n1);
scanf("%d",&n2);
  
  int burst_student[n1];
  int burst_faculty[n2];
  printf("You have only 2 hours or 7200 seconds to complete all queries \n");
  printf("Enter values accordingly \n\n");
  printf("Enter burst times in seconds for student queries\n\n");
  
  for(i=0;i<n1;i++)
  scanf("%d",&burst_student[i]);
  
  printf("Enter burst times in seconds for faculty queries\n\n");
  
  for(i=0;i<n2;i++)
  scanf("%d",&burst_faculty[i]);
  
  
  int quant_data=4;

  // Time quantum
  int quantum = 12;
  printf("Enter burst times for student queries\n\n");
  int sum=0;
  
  for(i=0;i<n1;i++)
  sum += burst_student[i];
  
  for(i=0;i<n2;i++)
  sum += burst_faculty[i];
  if(sum > 7200){
  	printf("Cannot process your request, burst times are too high\n\n");
  }
  else
  average(n1,n2, burst_student,burst_faculty,quant_data, quantum);
  
  return 0;
}
