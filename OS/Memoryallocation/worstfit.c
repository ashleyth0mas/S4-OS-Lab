#include<stdio.h>
#include<stdlib.h>
int main()
{
    typedef struct{
        int bid;
        int bsize;
    }block;
    block b[20];
    block large;
          int pno ,bno,psize[20],allocation[20]={0},i,j;
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
        b[i].bid=i+1;
        printf("Block %d:",i+1);
        scanf("%d",&b[i].bsize);
    }
    for(i=0;i<bno-1;i++)
    {
        for(j=0;j<bno-i-1;j++)
        {
            if(b[j].bsize<b[j+1].bsize)
            {
                large=b[j+1];
                b[j+1]=b[j];
                b[j]=large;
              
            }
            
        }
    } 
    for(i=0;i<pno;i++)
    {
        for(j=0;j<bno;j++)
        {
            if(psize[i]<=b[j].bsize)
            {
                allocation[i]=b[j].bid;
                b[j].bsize-=psize[i];
                break;
            }
        }
    }
    printf("Process no\tProcess size\tBlockno\n");
    for(i=0;i<pno;i++)
    {
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]>0)
        printf("%d\n",allocation[i]);
        else
        printf("Not allocated\n");
    }
    }