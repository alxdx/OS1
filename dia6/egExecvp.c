#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	pid_t pid;
	char *argumentos[3];

	argumentos[0]="ls";
	argumentos[1]="-l";
	argumentos[2]=NULL;
	if ((pid=fork())==0){
		execvp(argumentos[0],argumentos);
		perror("excec");
	}
	else
		printf("%s\n","proceso padre" );

	return 0;
}