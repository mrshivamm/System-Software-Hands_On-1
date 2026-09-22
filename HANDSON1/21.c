#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	pid_t pid;

	int fd=open("output.txt",O_RDWR|O_CREAT|O_TRUNC,0644);

	if(fd==-1){
		perror("file");
		return 1;
	}

	pid=fork();

	if(pid==-1){
		perror("fork");
		return 1;
	}
        else if(pid==0){
		write(fd,"child process writing\n",22);
	}
	else{
		write(fd,"parent process writing\n",23);
	}

	close(fd);

	return 0;
}
