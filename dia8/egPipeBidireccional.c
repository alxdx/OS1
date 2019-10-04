#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
 
int main(int argc, char const *argv[])
{
	pid_t pid;
	int pipe1[2]; //de hijo a padre
	int pipe2[2]; //de padre a hijo
	pipe(pipe1);
	pipe(pipe2);
	char text[100];
	if((pid=fork())==0){
		char aux[100];
		strcpy(text,"soy el hijo, Saludos papá");
		write(pipe1[1],text, sizeof(text));	
		read(pipe2[0],aux,sizeof(aux));
		printf("%s\n",aux);
	}
	else{
		char aux[100];
		read(pipe1[0],aux,sizeof(aux));
		printf("%s\n",aux);
		strcpy(text,"soy el padre, Saludos hijo");		
		write(pipe2[1],text, sizeof(text));	
		wait(NULL);
	}
	return 0;
}