
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    int rt;
  
} process;

int main() {
    int n, i, j,completed=0, curtime=0,avtat=0,avwt=0,front=0,rear=-1;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    process p[30],q[30];
    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
     printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
     
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }
    
   for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
     for (int i = 0; i < n; i++)
        q[++rear] = p[i];
   while(completed < n)
   {
       i=front%n;
      if(q[i].rt>quantum)
      {
        q[i].rt-=quantum;
        curtime+=quantum;
      }
      else  if(q[i].rt<=quantum && q[i].rt!=-1){       
      curtime+=q[i].rt;
     q[i].ct=curtime;
     q[i].tat=q[i].ct-q[i].at;
     q[i].wt=q[i].tat-q[i].bt;

     avtat+=q[i].tat;
     avwt+=q[i].wt;
     ++completed;
     q[i].rt=-1;
      }
      front++;
   }
        for (int i = 0; i < n; i++)
    {
        p[i] = q[i];
    }

    

    printf("\nProcess id\tArrival time\tBurst time\tCompletion time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    printf("Average waiting time:%d",avwt/n);
     printf("Average turnaround time:%d",avtat/n);
    return 0;
}
