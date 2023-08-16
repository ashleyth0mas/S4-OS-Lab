#include<stdio.h>
#include<stdlib.h>
int main()
{
    int f,p,i,j,k=0,hits=0,miss=0,pagefault,frames[10],pages[20];
    printf("Enter no of pages:");
    scanf("%d",&p);
    printf("Enter no of frames:");
    scanf("%d",&f);
     printf("Enter page stream:");
for(i=0;i<p;i++)
{
    scanf("%d",&pages[i]);
}
for(i=0;i<f;i++)
{
    frames[i]='-';
}
for(i=0;i<p;i++)
{
    int flag=0;
    for(j=0;j<f;j++)
    {
        if(pages[i]==frames[j])
        {
            flag++;
            hits++;
            break;
        }
    }
    if(flag==0)
    {
        frames[k]=pages[i];
        miss++;
        k=(k+1)%f;
    }
}
printf("\nNo of hits=%d",hits);
printf("\nHit ratio=%f",(float)hits/(float)p);
printf("\nPage fault=%d",miss);
printf("\nMiss ratio=%f",(float)miss/(float)p);

}