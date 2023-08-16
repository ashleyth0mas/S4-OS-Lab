//SJF with arrival time
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
} process;
process temp;
int main() {
    int n, i, j,small,tt,pos;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    process p[30];
    
    printf("Enter the burst time and arrival time of processes:\n");
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;  
        scanf("%d %d", &p[i].bt, &p[i].at);
    }
    
    // Sorting processes based on arrival time using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

            
            }
        }
    }
    
    p[0].wt = 0;
    p[0].ct = p[0].bt;
    tt=tt+p[0].ct;
    p[0].tat = p[0].ct - p[0].at;
    
    small=999;
    for(i=1;i<n;i++)
    {
        
        for (j=i;j<n;j++)
        {
if(p[j].at< tt)
{
    if(p[j].bt<small)
    {
 small=p[j].bt;
    pos=j;
    }
   
}
        }
        p[i].ct=p[i-1].ct+p[i].bt;
        tt+=p[i].ct;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
 
    
    printf("\nProcess id\tArrival time\tBurst time\tCompletion time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }
    
    return 0;
}
