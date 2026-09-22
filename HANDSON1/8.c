#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	char ch;

	int fd= open("file1.txt",O_RDONLY);

	if(fd==-1){
		perror("file1");
		return 1;
	}

	while((read(fd,&ch,1))>0){
		write(1,&ch,1);
	}

	close(fd);
	return 0;
}

