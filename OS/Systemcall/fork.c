// fork(),wait(),getpid(),getppid() system calls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int pid;
    pid = fork();
    printf("Hello World\n");
    if (pid < 0)
    {
        printf("Error");
        exit(1);
    }
    else if (pid == 0)
    {
        // CHILD PROCESS
        printf("Child process ID:%d and Parent process ID:%d", getpid(), getppid());
        // child process executed
        int c, a = 4, b = 5;
        c = a + b;
        printf("\n Sum of %d and %d is %d", a, b, c);
    }
    else
    {
        // PARENT PROCESS
        printf("\n Parent process ID: %d and Child process ID:%d", getpid(), pid);
        wait(NULL); // wait till child process is executed
        int d, e = 10, f = 5;
        d = e - f;
        printf("\n Difference of %d and %d is %d", e, f, d);
    }
}
