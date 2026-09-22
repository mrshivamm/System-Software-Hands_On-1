#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	int value;
	int record;
        struct flock lock;

	fd= open("record.txt",O_RDWR);

	if(fd==-1){
		perror("open");
		return 1;
	}
	printf("ENTER A RECORD\n");
	scanf("%d",&record);

	if(record<1 ||record>3){
		printf("invalid record number\n");
		close(fd);
		return 1;
	}

	lock.l_whence=SEEK_SET;
	lock.l_start=(record-1)*sizeof(int);
	lock.l_len=sizeof(int);

	lock.l_type=F_WRLCK;

	printf("write lock applying\n");

	fcntl(fd,F_SETLKW,&lock);
	printf("lock applied\n");

	lseek(fd,lock.l_start,SEEK_SET);
        read(fd,&value,sizeof(int));
	printf("original value of record %d is %d \n",record,value);

        printf("enter new value\n");
	scanf(" %d",&value); 

	lseek(fd,lock.l_start,SEEK_SET);
	write(fd, &value ,sizeof(int));
	printf("new value of record %d is %d\n",record,value);

	lock.l_type= F_UNLCK;

	fcntl(fd,F_SETLK,&lock);
	printf("lock unlocked\n");

	close(fd);
	return 1;
}




	
