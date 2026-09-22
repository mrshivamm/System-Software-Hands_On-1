#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
 int main(){
	 char c1[]="ABCDEFGHIJ";
	 char c2[]="1234567890";

	 int fd= open("file3.txt",O_RDWR|O_CREAT|O_TRUNC,0644);

	 if(fd==-1){
		 perror("open");
		 return 1;
	 }

	 write(fd,c1,10);

	 off_t pos=lseek(fd,10,SEEK_CUR);

	 if(pos==-1){
		 perror("lseek");
		 close(fd);
		 return 1;
	 }

	 printf("file pointer position :%ld\n",pos);
	 write(fd,c2,10);

	 close(fd);
	 return 0;
 }
