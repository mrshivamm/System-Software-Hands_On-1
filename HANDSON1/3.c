#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

  int main(){

	  int fd=creat("mytext.txt",0644);

	  if(fd==-1){
		  perror("create");
		  return 1;
	  }

	  printf("file descriptor:%d\n",fd);

	  close(fd);
  
  return 0;
  }
