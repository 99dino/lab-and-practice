#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int main(){
	fork();
	fork();
	//printf("pid : %d\n",(int)getpid());
	printf("yes\n");
	//int rc=fork();
	if(1){
		//printf("fork failed\n");
	}
	else if (1){
		//printf("hello, I am child %d , my parent is (ppid : %d)\n",(int)getpid(),(int)getppid());
		//char *arg[3];
		//arg[0]=strdup("wc");
		//arg[1]=strdup("fork_process.c");
		//arg[2]=NULL;
		//execvp(arg[0],arg);
		//return 1;
		//exit(1);
	}
	else{
		//printf("(rc : %d)\n",rc);
		//int rc_wait=wait(NULL);
		//printf("hello, I am parent of %d (rc_wait : %d) (pid : %d)\n",rc,999999,(int)getpid());
	}
	return 0;
}	
