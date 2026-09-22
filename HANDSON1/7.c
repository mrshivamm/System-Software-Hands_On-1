#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

	char buffer[1024];
	int n;

	int fd1= open("file1.txt",O_RDONLY);

	if(fd1==-1){
		perror("read");
		return 1;
	}

	int fd2= open("file2.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);

	if(fd2==-1){
		perror("file2");
		close(fd1);
		return 1;
	}

	while(( n=read(fd1,buffer,sizeof(buffer)))>0){
			write(fd2,buffer,sizeof(buffer));
			}
	close(fd1);
	close(fd2);

	return 0;
	}



