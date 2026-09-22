#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd,fd2,fd3,fd4;

	fd=open("file4.txt",O_WRONLY|O_CREAT|O_APPEND,0644);
	
	if(fd==-1){
		perror("open");
		return 1;
	}

	fd2=dup(fd);
	fd3=dup2(fd,10);
	fd4= fcntl(fd,F_DUPFD,7);

	if(fd2==-1){
		perror("dup");
		close(fd);
		return 1;
	}

	if(fd3==-1){
		perror("dup2");
		close(fd);
		return 1;
	}

	if(fd4==-1){
		perror("fcntl");
		close(fd);
		return 1;
	}

	write(fd,"hello\n",6);
	write(fd2,"world\n",6);

	write(fd3,"heyyy\n",6);
	write(fd4,"there\n",6);

	printf("fd:%d\n,fd2:%d\n,fd3:%d\n,fd4:%d\n",fd,fd2,fd3,fd4);


	close(fd);
	close(fd2);
	close(fd3);
	close(fd4);

	return 0;
}


