#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int flag;
	int fd= open("file1.txt",O_RDWR);

	if(fd==-1){
		perror("open");
		return 1;
	}

	flag= fcntl(fd,F_GETFL);

	if(flag==-1){
		perror("fcntl");
		close(fd);
		return 1;
	}

	if((flag & O_ACCMODE)==O_RDONLY){
		printf("reaed onky mode");
	}
	else if((flag & O_ACCMODE) ==O_WRONLY){
		printf("write mode only");
	}

	else if((flag & O_ACCMODE)== O_RDWR){
		printf("both read and write mode");
	}

	close(fd);
	return 0;
}
