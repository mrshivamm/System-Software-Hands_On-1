#include<stdio.h>
#include<sys/select.h>
#include<unistd.h>

int main(){
	fd_set readfd;
	struct timeval timeout;

	FD_ZERO(&readfd);

	FD_SET(STDIN_FILENO,&readfd);

	timeout.tv_sec=10;
	timeout.tv_usec=0;

	int ret= select(STDIN_FILENO +1,&readfd,NULL,NULL,&timeout);

	if(ret ==-1){
		perror("select");
		return 1;
	}
	else if(ret ==0){
		printf("timeout\n");
	}

	else{
		if(FD_ISSET(STDIN_FILENO,&readfd)){
				printf("data availabe\n");

				char buffer[100];

				int n = read(STDIN_FILENO,buffer,sizeof(buffer));

				if(n>0){
				  write(STDOUT_FILENO,buffer,n);
				  }
		  }

				  
	  }
	  return 0;
  }

