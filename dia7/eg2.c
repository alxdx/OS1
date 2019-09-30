#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <signal.h>

int file;
void lee();
void escribe();
int main(int argc, char const *argv[])
{
	pid_t pid;
	creat("ddatos.dat",0777);
	file=open("ddatos.dat",02);
	if((pid=fork())==0){
		struct sigaction catcher;
		catcher.sa_handler= escribe;
		catcher.sa_flags=0;
		sigemptyset(&catcher.sa_mask);
		sigaction(SIGALRM,&catcher,NULL);

		while(1){
			alarm(1);
			pause();
		}
	}
	else{
		sleep(1);
		struct sigaction bullet;
		bullet.sa_handler= lee;
		bullet.sa_flags=0;
		sigemptyset(&bullet.sa_mask);
		sigaction(SIGALRM,&bullet,NULL);
		
		while(1){
			alarm(1);
			pause();
		}
	}
	return 0;
}

void lee(){
	int aux=rand();
	write(file,&aux,sizeof(int));
}

void escribe(){
	int aux;
	read(file,&aux,sizeof(int));
	printf("%d\n",aux);
}