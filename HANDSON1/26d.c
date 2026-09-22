#include <stdio.h>
#include <unistd.h>

int main()
{
    char *args[] = {"ls", "-Rl", NULL};

    printf("Executing using execv()\n");
    execv("/usr/bin/ls", args);

   
    perror("execv");
    return 1;
}
