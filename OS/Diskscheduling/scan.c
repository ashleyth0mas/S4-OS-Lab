#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int head,nr,R[30],totheadmov=0,i,j,move,size,temp,index;
      printf("Enter disk size:\n");
    scanf("%d",&size);
       printf("Enter intial head position:\n");
    scanf("%d",&head);
    printf("Enter no of requests:\n");
    scanf("%d",&nr);
     printf("Enter the requests sequence:\n");
     for(i=0;i<nr;i++)
     {
     scanf("%d",&R[i]);
     }
   
     for(i=0;i<nr-1;i++)
     {
        for(j=0;j<nr-i-1;j++)
        {
            if(R[j]>R[j+1])
            {
                temp=R[j];
                R[j]=R[j+1];
                R[j+1]=temp;
            }
        }
     }
     printf("Enter direction: 1.High 2.Low\n");
     scanf("%d",&move);
     
      for(i=0;i<nr;i++)
     {
  
     if(head<R[i])
     {
index=i;
break;
     }
     
     }
     if(move==1)
   {
   for(i=index;i<nr;i++) 
   {
   totheadmov+=abs(head-R[i]);
   head=R[i];
   }
   totheadmov+=abs(size-head-1);  
   head=size-1;
    for(i=index-1;i>0;i--) 
   {
    totheadmov+=abs(head-R[i]);
    head=R[i];
   }
     printf("Total head movements=%d",totheadmov);
     printf("\nAverage seek time=%d",totheadmov/nr);
}
else{
  for(i=index-1;i>0;i--) 
   {
   totheadmov+=abs(head-R[i]);
   head=R[i];
   }
   totheadmov+=abs(head-0); 
   head=0;
    for(i=index;i<nr;i++) 
   {
    totheadmov+=abs(head-R[i]);
    head=R[i];
   }
     printf("Total head movements=%d",totheadmov);
     printf("\nAverage seek time=%d",totheadmov/nr);  
}
}