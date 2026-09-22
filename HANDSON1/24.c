#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0)
    {
        printf("Child 1 running, PID: %d\n", getpid());
        sleep(3);
        printf("Child 1 exiting\n");
        exit(0);
    }

    pid2 = fork();

    if (pid2 == 0)
    {
        printf("Child 2 running, PID: %d\n", getpid());
        sleep(5);
        printf("Child 2 exiting\n");
        exit(0);
    }

    pid3 = fork();

    if (pid3 == 0)
    {
        printf("Child 3 running, PID: %d\n", getpid());
        sleep(2);
        printf("Child 3 exiting\n");
        exit(0);
    }
    printf("parent process is running \n");
    printf("Parent PID: %d\n", getpid());

    printf("Parent is waiting for Child 2...\n");

    waitpid(pid2, NULL, 0);

    printf("Child 2 has finished.\n");
    printf("Parent exiting.\n");

    return 0;
}
