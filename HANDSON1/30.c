#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid > 0)
    {
        return 0;
    }

    if (setsid() < 0)
    {
        perror("setsid");
        return 1;
    }

    chdir("/");

    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int target_hour = 21;
    int target_minute = 15;

    while (1)
    {
        time_t now = time(NULL);
        struct tm *current = localtime(&now);

 
        if (current->tm_hour == target_hour &&
            current->tm_min == target_minute)
        {
           
            int fd = open("/tmp/daemon_output.txt",
                          O_CREAT | O_WRONLY | O_APPEND,
                          0644);

            if (fd != -1)
            {
                char message[] = "Task executed by daemon\n";

              
                write(fd, message, sizeof(message) - 1);

                close(fd);
            }

        
            sleep(60);
        }

        sleep(1);
    }

    return 0;
}
