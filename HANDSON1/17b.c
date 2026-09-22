#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	int ticket;
	struct flock lock;

	fd=open("ticket.txt",O_RDWR);

	if(fd==-1){
		perror("open");
		return 1;
	}

	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;

	printf("trying to acquire lock\n");

	if(fcntl(fd,F_SETLKW,&lock)==-1){
		perror("lock");
		close(fd);
		return 1;
	}

	printf("lock acquired\n");

	read(fd,&ticket,sizeof(ticket));
	printf("initially ticket number is %d\n",ticket);

	ticket++;

	lseek(fd,0,SEEK_SET);

	write(fd,&ticket,sizeof(ticket));
        printf("new ticket number %d\n",ticket);

	lock.l_type=F_UNLCK;
	printf("lock unlocked\n");

	fcntl(fd,F_SETLK,&lock);
	close(fd);
	return 0;
}



