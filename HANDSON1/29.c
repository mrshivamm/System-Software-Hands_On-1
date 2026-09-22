#include<stdio.h>
#include<unistd.h>
#include<sched.h>

int  main(){
	int policy;
	struct sched_param param;

	policy= sched_getscheduler(0);

	if(policy==-1){
		perror("scheduler\n");
		return 1;
	}

	if(policy==SCHED_OTHER){
		printf("scheduler is other\n");
	}
        else if(policy==SCHED_FIFO){
		printf("scheduler is fifo\n");
	}
	else if(policy==SCHED_RR){
		printf("scheduler is rr\n");
	}
        
	param.sched_priority=1;

	if( sched_setscheduler(0,SCHED_RR,&param)==-1){
		perror("set_scheduler\n");
		return 1;
	}
         printf("scheduler changed to RR\n");

	policy=sched_getscheduler(0);

	if(policy==SCHED_RR){
		printf("current scheduler is RR\n");
	}

	return 0;
}
