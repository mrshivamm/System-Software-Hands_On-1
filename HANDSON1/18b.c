#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	int record;
	int value;
	struct flock lock;
	
	fd= open("record.txt",O_RDONLY);

	if(fd==-1){
		perror("open");
		return 1;
	}

	printf("enter the record you want to read\n");
        scanf("%d",&record);	
	 if (record < 1 || record > 3)
    {
        printf("Invalid record number\n");
        close(fd);
        return 1;
    }

	lock.l_type=F_RDLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start= (record-1)*sizeof(int);
	lock.l_len=sizeof(int);

	printf("read lock appluying \n");

	lseek(fd,lock.l_start,SEEK_SET);

	fcntl(fd,F_SETLKW,&lock);

	printf("read lock applied");

	read(fd,&value,sizeof(int));
	printf("the value of record %d is %d\n",record,value);

	lock.l_type=F_UNLCK;
	printf("read lock unlockin\n");


	fcntl(fd,F_SETLK,&lock);
	printf("read lock unlocked\n");

	close(fd);
	return 0;
}




	
