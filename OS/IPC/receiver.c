#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>

int main()
{
    char buffer[200];
    void *sharedmem;
   int shmid;
   shmid=shmget((key_t)2345,1024,0666); 
   printf("Key of shared memory:%d",shmid);
   sharedmem=shmat(shmid,NULL,0);
   printf("\nReciever process attached at:%p",sharedmem);
   printf("\nData read from sender is:%s",(char *)sharedmem);        
}