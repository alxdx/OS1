#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int n,m;
	pid_t pid;
	pid = fork();
	switch(pid)
	{
	case -1:
		exit(-1);
	case 0:
		m = atoi(argv[1]);
		n = atoi(argv[2]);
		if(n!=0){
		printf("\nImprimo mi ID %d veces\nDuermo %d segundos\n",n,m);
			sleep(m);
			for(int i=0; i<n;i++)
			{
				printf("Programa hijo1: Mi id es %d\n",getpid());
			}
			break;
			
		default: 
			printf("\n");
		}
	}
}
