#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int n,m;
	pid_t pid;
	pid = fork();
	switch(pid){
	case -1:
		exit(-1);
	case 0:
		m = atoi(argv[1]);
		n = atoi(argv[2]);
		printf("Duermo %d segundos\n",m);
		printf("Imprimo mi ID %d veces\n",n);
		if(n!=0){
			sleep(m);
			for(int i=0; i<n;i++)
			{
				printf("Mi id es %d\n",getpid());
			}
			break;
			
	default: 
			printf("Soy el proceso padre\n");
		}
	}
}
