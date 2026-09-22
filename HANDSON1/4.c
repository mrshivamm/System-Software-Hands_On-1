#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

      int fd=open("mytext.txt",O_RDWR|O_CREAT|O_EXCL,0644);

      if(fd==-1){
	      perror("open");
	      return 1;
      }

      printf("file opened successfully with fd : %d\n",fd);

      close(fd);
  
	return 0;
}
