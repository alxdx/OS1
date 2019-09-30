#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <signal.h>
pid_t pid;
void ckiller();
void bkiller();
void akiller();
void killer();

int main(int argc, char const *argv[]){
	creat("processIds.dat",0777);
	if((pid=fork()==0)){

		if(fork()==0){

			if(fork()==0){//c
				alarm(6);
				struct sigaction bullet;
				bullet.sa_handler= ckiller;
				bullet.sa_flags=0;
				sigemptyset(&bullet.sa_mask);
				sigaction(SIGALRM,&bullet,NULL);
				int file=open("processIds.dat",01);
				int myId,ppid=getppid();
				write(file,&myId,sizeof(int));
				while(1)
					printf("soy C con padre: %d\n",ppid);
			}else{//b

				struct sigaction bcatcher;
				bcatcher.sa_handler= bkiller;
				bcatcher.sa_flags=0;
				sigemptyset(&bcatcher.sa_mask);
				sigaction(SIGUSR1,&bcatcher,NULL);

				int file=open("processIds.dat",01);
				int myId,ppid=getppid();
				write(file,&myId,sizeof(int));
				
				while(1)
					printf("soy B con padre: %d\n",ppid);
			}
		}
		else{//a

				struct sigaction acatcher;
				acatcher.sa_handler= akiller;
				acatcher.sa_flags=0;
				sigemptyset(&acatcher.sa_mask);
				sigaction(SIGUSR2,&acatcher,NULL);

				int ppid=getppid();
				while(1)
					printf("soy A con padre: %d\n",ppid);
		}
	}
	else{//r
		struct sigaction rcatcher;
		rcatcher.sa_handler= killer;
		rcatcher.sa_flags=0;
		sigemptyset(&rcatcher.sa_mask);
		sigaction(SIGUSR1,&rcatcher,NULL);
		pause();
	}
	return 0;
}

void ckiller(){
	kill(getppid(),SIGUSR1);
}

void bkiller(){
	kill(getppid(),SIGUSR2);
}

void akiller(){
	kill(getppid(),SIGUSR1);
}

void killer(){
	int file,hijo1,hijo2,hijo3;
	file=open("processIds.dat",00);
	read(file,&hijo3,sizeof(int));
	read(file,&hijo2,sizeof(int));
	hijo1=pid;
	kill(hijo1,SIGKILL);
	kill(hijo2,SIGKILL);
	kill(hijo3,SIGKILL);

}