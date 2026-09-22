#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid;

	pid= fork();

	if(pid==-1){
		perror("fork");
		return 1;
	}

	else if(pid==0){
		printf("child process running\n");
		printf("childs pid : %d\n",getpid());
		printf("parents pid: %d\n",getppid());

		sleep(200);

		printf("child process running without parent\n");
		printf("childs pid :%d\n",getpid());
		printf("new parent id:%d\n",getppid());

	}
	else{
		printf("parent is runnning\n");
		printf("parent pid:%d\n",getpid());
		printf("child pid:%d\n",pid);

		sleep(2);

		printf("parent exiting:\n");

		exit(0);
	}
	return 0;
}

