#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    int shmid;
    void *sharedmem;
    char buffer[200];
    shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
    printf("Key of shared memory:%d",shmid);
    sharedmem= shmat(shmid,NULL,0);
    printf("\nSender process attached at:%p",sharedmem);  //note- %p is used to give address of pointer
    printf("\nEnter data to write to shared memory:\n");
   //scanf("%s",buffer);
   read(0,buffer,100);    //read is used instead of scanf to read data input as line of text with scanf only a word can be input 
    strcpy(sharedmem,buffer);
    printf("\nData wrote successfully");
}