#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int head,nr,R[30],totheadmov=0,i;
       printf("Enter intial head position:\n");
    scanf("%d",&head);
    printf("Enter no of requests:\n");
    scanf("%d",&nr);
     printf("Enter the requests sequence:\n");
     for(i=0;i<nr;i++)
     {
     scanf("%d",&R[i]);
     }
     for(i=0;i<nr;i++) 
     {
        totheadmov+=abs(head-R[i]);
        head=R[i];
     }
     printf("Total head movements=%d",totheadmov);
     printf("\nAverage seek time=%d",totheadmov/nr);
}