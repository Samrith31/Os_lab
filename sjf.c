#include <stdio.h>


int waitingtime(int proc[],int n,int burst_time[],int wait_time[]){

    wait_time[0]=0;
    int i;
    for(i=1;i<n;i++){
        wait_time[i]=burst_time[i-1]+wait_time[i-1];
    }

}


int turnaroundtime(int proc[],int n,int burst_time[],int wait_time[],int tat[]){
    int i;
    for(i=0;i<n;i++)
    tat[i]=burst_time[i]+wait_time[i];
}

int avgtime( int proc[],int n,int burst_time[]){
     int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
     int i=0;

      waitingtime(proc,n,burst_time,wait_time);
      turnaroundtime(proc,n,burst_time,wait_time,tat);

       printf("Processor  Burst_time   Waiting_time   Turn_around_time\n");
      for(i=0;i<n;i++){
        total_wt=total_wt+wait_time[i];
        total_tat=total_tat+tat[i];

        printf(" %d",(i+1));
        printf("            %d",burst_time[i]);
        printf("                  %d",wait_time[i]);
        printf("                     %d\n",tat[i]);

      }

           float  s1=(float)total_wt/(float)n;
           float s2=(float)total_tat/(float)n;
      printf("Average waiting time : %f\n",s1);
       printf("Average turnaround time : %f\n",s2);

}



   int main(){

        int nofpr;
        int nofbr;
        int i=0;
       printf("Enter the no of the processors\n");
       scanf("%d",&nofpr);
       int proc[nofpr];
       for(i=0;i<nofpr;i++){
         printf("Enter the the no %d\n",i+1);
         scanf("%d",&proc[i]);
       }

     int n= sizeof(proc)/sizeof(proc[0]);

      printf("Enter the no of burst time\n");
       scanf("%d",&nofbr);

     int burst_time[nofbr];
      for(i=0;i<nofbr;i++){
         printf("Enter the the no %d\n",i+1);
         scanf("%d",&burst_time[i]);
       }
        int q=0;
        int w=0;
        int a;

        //sorting
       for (q = 0; q < n; ++q){
       for (w = q + 1; w < n; ++w){
       if (burst_time[q] > burst_time[w]){
         a = burst_time[q];
         burst_time[q] = burst_time[w];
         burst_time[w] = a;
       }
    }
 }

   int e=0;
   for(e=0;e<n;e++){
     printf(" %d",burst_time[e]);

   }
    printf("\n");




     avgtime(proc,n,burst_time);

   }
