#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main(int args, char *argv[])
{
	pid_t pid;
	int status;
	pid = fork();

	switch(pid)
	{
		case -1:
			exit(-1);

		case 0:
			execlp("./hijo1","./hijo1",argv[1],argv[2],NULL);
			perror("exec");
			break;
	}

}
