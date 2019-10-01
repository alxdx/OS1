#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char **argv[])
{
	pid_t pid;
	char *argumentos[3];
	pid = fork();

	argumentos[0] = "./hijo1";
	
	switch(pid)
	{
		case -1:
			exit(-1);

		case 0:
			execl("./hijo1","./hijo1",argv[1],argv[2],NULL);
			break;
		default:
			printf("Proceso padre\n");
	}
}
