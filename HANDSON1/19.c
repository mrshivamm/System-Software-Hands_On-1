#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());

    while (1)
    {
        printf("Process is running...\n");
        sleep(2);
    }

    return 0;
}
