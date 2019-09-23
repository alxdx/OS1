#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
	
	pid_t pid;

	if ((pid=fork())==0){
		if(execvp(argv[1],&argv[1])<0)
			perror("exec");
	}
	else
		printf("%s\n","proceso padre" );

	return 0;
}
