#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
int main(){
	struct stat st;

	if(stat("file1.txt",&st)==-1){
		perror("stat");
		return 1;
	}

	printf("inode no :%ld\n",st.st_ino);
	printf("no of hard link:%ld\n",st.st_nlink);
	printf("UID: %d\n",st.st_uid);
	printf("GID:%d\n",st.st_gid);
	printf("size:%ld\n",st.st_size);
	printf("blocksize:%ld bytes \n",st.st_blksize);
	printf("number of blocks:%ld bytes \n",st.st_blocks);
	printf("time of last access :%s",ctime(&st.st_atime));
	printf("time of last modification:%s",ctime(& st.st_mtime));
	printf("time of last change:%s",ctime(&st.st_ctime));

	return 0;
}
