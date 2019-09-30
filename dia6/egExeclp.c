#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(int args, char *argv[])
{
	pid_t pid;
	int status;
	pid = fork();

	if(pid==0){
			execlp("./hijo","./hijo",argv[1],argv[2],NULL);
			perror("exec");		
	}else
		printf("%s\n","proceso padre" );	
}
