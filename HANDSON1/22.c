#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid;

	pid=fork();

	if(pid==-1){
		perror("fork");
		return 1;
	}

	else if(pid==0){
		printf("child process runnning \n");
                printf("child pid: %d\n ",getpid());

		exit(0);
	}

	else
	{
		printf("parent process is running \n");
		printf("parent process pid %d\n",getpid());
		printf("child process pid: %d\n",pid);

		sleep(30);
		printf("parent process exiting.....\n");

	}

	return 0;
}
