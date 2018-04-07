#include<iostream>
using namespace std;


int wait_time_faculty( int burst_faculty[], int rburst_faculty[], int f1, int wait_faculty[], int quant_data, int quantum, int t)
  { int ft=0;int count=0,burst=0;
  cout<<"inside wait_time_faculty"<<endl;
  for (int i = 0 ; i < f1; i++)
  count += burst_faculty[i];
    while(count < burst)
    {
    	cout<<"Inside secind while"<<endl;

    for (int i = 0 ; i < f1; i++)
    {
  
      if (rburst_faculty[i] > 0)
      {      

        if (rburst_faculty[i] >= quant_data)
        {cout<<"rburst_faculty[i] >= quant_data"<<endl;
          // adding burst to total time may or mat not exceed the queue burst 
          //check if adding exceeds queue burst
		cout<<"ft = "<<ft<<endl;
          if((ft + quant_data) >= quantum)
		  {cout<<"ft + quant_data"<<endl;
            if((ft + quant_data) == quantum){
              ft += quant_data;
              burst += quant_data;
              cout<<"ft = "<<ft<<endl;
              t += quant_data;
              cout<<"ft = "<<ft<<endl;
              rburst_faculty[i]-=quant_data;  
			  ft=0;            
            }

            if((ft + quant_data) > quantum){
            	cout<<"ft = "<<ft<<endl;
              ft += quant_data;
              burst += quant_data;
			  int z= quantum - ft;
              rburst_faculty[i] -= z;
              cout<<"ft = "<<ft<<endl;
              t += t + z;
              ft=0;
            }

          }
          else{
            rburst_faculty[i] -= quant_data;
            ft += quant_data;
            burst += quant_data;
            t += quant_data;      
			cout<<"ft = "<<ft<<endl;     
          }
      }
        else{

          t = t + rburst_faculty[i];
          burst += rburst_faculty[i];
          ft += rburst_faculty[i];
			cout<<"t = t + rburst_faculty[i]"<<endl;
			cout<<"ft = "<<ft<<endl;

          wait_faculty[i] = t - burst_faculty[i];


          rburst_faculty[i] = 0;
            }
        }
      
    }
    if(count>25)
    break;
    
  }
  return t;
}



void waiting( int s1,int f1, int burst_student[],int burst_faculty[],
                 int quant_data, int wait_student[],int wait_faculty[], int quantum)
{
  
  cout<<"Inside findwaiting time"<<endl;
  int c=0;
  int rburst_student[s1];
  int rburst_faculty[f1];
  int burst_f[f1];

int count=0,burst=0;
  for (int i = 0 ; i < f1; i++)
  count += burst_student[i];
  
  for (int i = 0 ; i < s1 ; i++){
  
    rburst_student[i] = burst_student[i];
    count += burst_student[i];}
  for (int i = 0 ; i < f1 ; i++)
    rburst_faculty[i] = burst_faculty[i];
	for (int i = 0 ; i < f1 ; i++)
    burst_f[i] = burst_faculty[i];
    
    for (int i = 0 ; i < f1 ; i++)
    wait_faculty[i] = 0;

  int t = 0;
  int st=0;
  // round robin 

  while (1)
  {
  	cout<<"Insside while"<<endl;
    bool done = true;

    for (int i = 0 ; i < s1; i++)
    {

      if (rburst_student[i] > 0)
      {
        done = false; 

        if (rburst_student[i] >= quant_data)
        {cout<<"rburst_student[i] >= quant_data"<<endl;

          // adding burst to total time may or mat not exceed the queue burst 
          //check if adding exceeds queue burst
          if((st + quant_data >= quantum))
		  {
            if((st + quant_data) == quantum)
			{
              st += quant_data;
              t += quant_data;
              rburst_student[i] -= quant_data;
              c = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
              t = t + c;
              st = 0;
              
            }
            if((st + quant_data) > quantum){
              st += quant_data;
              int z = quantum - st;
              rburst_student[i] -= z;
              t += z;
              c = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
              t = t + c;
              st = 0;
            }
            
          }

          else{
            rburst_student[i] -= quant_data;
            st += quant_data;
            t += quant_data;           
          }
      }
          //burst time is smaller than or equal to quan_data
            else{
          t = t + rburst_student[i];
          st += rburst_student[i];
              
          wait_student[i] = t - burst_student[i];

          rburst_student[i] = 0;
            }
        }
        
      }
      if (done == true)
      break;
    }
    
    } 

void turn_around(int s1,int f1,int burst_student[],
                        int burst_faculty[],int wait_student[],int wait_faculty[],int turn_student[],int turn_faculty[])
{
 
  for (int i = 0; i < s1 ; i++)
    turn_student[i] = burst_student[i] + wait_student[i];

  for (int i = 0; i < f1 ; i++)
    turn_faculty[i] = burst_faculty[i] + wait_faculty[i];
}


void average(int student[],int faculty[], int s1,int f1, int burst_student[],int burst_faculty[],
                 int quant_data,int quantum)
{
  int wait_student[s1], wait_faculty[f1],turn_student[s1], turn_faculty[f1] ;
  int total_wait_student = 0, total_wait_faculty=0,  total_turn_student = 0, total_turn_faculty=0;

  waiting(s1,f1, burst_student,burst_faculty,quant_data,wait_student,wait_faculty, quantum);
  turn_around( s1,f1, burst_student,burst_faculty,wait_student,wait_faculty, turn_student, turn_faculty);

 
  cout << "Processes "<< " Burst time "
    << " Waiting time " << " Turn around time\n";

  // total waiting time and total turn around time
  for (int i=0; i<s1; i++)
  {
    total_wait_student = total_wait_student + wait_student[i];
    total_turn_student = total_turn_student + turn_student[i];
    cout << " " << i+1 << "\t\t" << burst_student[i] <<"\t "
      << wait_student[i] <<"\t\t " << turn_student[i] <<endl;
  }

  cout << "Average waiting time = "
    << (float)total_wait_student / (float)s1;
  cout << "\nAverage turn around time = "
    << (float)total_turn_student / (float)s1;
    int j=0;

  for (int i=faculty[j]; i < f1; i++)
  {
    total_wait_faculty = total_wait_faculty + wait_faculty[i];
    total_turn_faculty = total_turn_faculty + turn_faculty[i];
    cout << " " << i << "\t\t" << burst_faculty[i] <<"\t "
      << wait_faculty[i] <<"\t\t " << turn_student[i] <<endl;
      j++;
  }

  cout << "Average waiting time = "
    << (float)total_wait_faculty / (float)f1;
  cout << "\nAverage turn around time = "
    << (float)total_turn_faculty / (float)f1;

}

int main()
{
  int student[] = { 1, 2, 3};
  int s1 = sizeof student / sizeof student[0];
  int faculty[] = { 4,5,6};
  int f1 = sizeof faculty / sizeof faculty[0];

  int burst_student[] = {10, 5, 8};
  int burst_faculty[] = {8,5,6};
  int quant_data=4;

  // Time quantum
  int quantum = 12;
  average(student,faculty, s1,f1, burst_student,burst_faculty,quant_data, quantum);
  return 0;
}
