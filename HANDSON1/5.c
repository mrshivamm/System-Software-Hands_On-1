#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd1,fd2,fd3,fd4,fd5;

	fd1=open("file1.txt",O_CREAT|O_RDWR,0644);
	fd2=open("file2.txt",O_CREAT|O_RDWR,0644);
	fd3=open("file3.txt",O_CREAT|O_RDWR,0644);
	fd4=open("file4.txt",O_CREAT|O_RDWR,0644);
	fd5=open("file5.txt",O_CREAT|O_RDWR,0644);

	if(fd1==-1||fd2==-1||fd3==-1||fd4==-1||fd5==-1){
		perror("open");
		return 1;
	}

	printf("file opened successfully with fd1,fd2,fd3,fd4,fd5 : %d,%d,%d,%d,%d\n",fd1,fd2,fd3,fd4,fd5);

	while(1){
		sleep(20);
	}

	return 0;
}
	

