#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <signal.h>
#include <stdlib.h>
pid_t pid;

void killer(){
	kill(pid,SIGKILL);
}

int main(int argc, char const *argv[])
{
	//pid_t pid;
	if ((pid=fork())==0){
		int file,conta=0,id=getpid();
		creat("id.dat",007);
		file=open("id.dat",01);
		while(1){
			write(file,&id,sizeof(int));
		}
	}else{
		alarm(3);
		int status;
		struct sigaction bullet;
		bullet.sa_handler=killer;
		bullet.sa_flags=0;
		sigemptyset(&bullet.sa_mask);
		sigaction(SIGALRM,&bullet,NULL);
		
		wait(&status);
	}
	exit(0) ;
}