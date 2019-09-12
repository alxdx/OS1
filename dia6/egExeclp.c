#include <stdio.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	pid_t pid;
	int status;
	if((pid=fork()==0)){
		execlp("ls","ls","-l",NULL);
		perror("exec");
	}else
		printf("%s\n","proceso padrea");
	return 0;
}