#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing using execl()\n");
    execl("/usr/bin/ls", "ls", "-Rl", NULL);

    perror("execl");
    return 1;
}
