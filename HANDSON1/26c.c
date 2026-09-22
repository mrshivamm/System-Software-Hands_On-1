#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main()
{
    printf("Executing using execle()\n");
    execle("/usr/bin/ls", "ls", "-Rl", NULL, environ);

   
    perror("execle");
    return 1;
}
