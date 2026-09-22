#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Before exec()\n");

    execl("/home/shivam/softwareSystem/handson1/processManag/hello", "./hello", NULL);

    perror("execl");

    return 1;
}
