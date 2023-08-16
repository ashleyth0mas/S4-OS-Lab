#include<stdio.h>
#include<stdlib.h>
int main()
{
    int pno,bno ,psize[20],bsize[20],allocation[20]={0},i,j;
    printf("Enter the no of processes:");
    scanf("%d",&pno);
     printf("\nEnter the process size:\n");
    for(i=0;i<pno;i++)
    {
        printf("Process %d:",i+1);
   scanf("%d",&psize[i]);
    }
     printf("\nEnter the no of memoryblocks:\n");
    scanf("%d",&bno);
    printf("\nEnter the block size:\n");
    for(i=0;i<bno;i++)
    {
        printf("Block %d:",i+1);
        scanf("%d",&bsize[i]);
    }
    for(i=0;i<pno;i++)
    {
        for(j=0;j<bno;j++)
        {
            if(psize[i]<=bsize[j])
            {
                allocation[i]=j+1;
                bsize[j]-=psize[i];
                break;
            }
            
        }
    } 
    printf("Process no\tProcess size\tBlock no\n");
    for(i=0;i<pno;i++)
    {
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]>0)
        printf("%d\n",allocation[i]);
        else
        printf("Not allocated\n");
    }
}