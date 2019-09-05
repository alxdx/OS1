#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	pid_t pid;
	int status;
	if((pid=fork())==0){
		printf("Mi padre:%d\n",getppid());
	  return 10;
  }
	else{
		wait(&status);
		printf("Mi id: %d\nId de mi hijo: %d\n",getpid(),pid);
		if(WIFEXITED(status))
			printf("estado de mi hijo: %d\n",WEXITSTATUS(status));
	}
	return 0;
}


