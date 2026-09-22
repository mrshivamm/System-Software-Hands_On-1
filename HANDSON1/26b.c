#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing using execlp()\n");
    execlp("ls", "ls", "-Rl", NULL);

   
    perror("execlp");
    return 1;
}
