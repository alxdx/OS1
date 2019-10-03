#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
 int i,n=4;
	pid_t childpid;
	for(int i=1;i<n;++i)
		if((childpid=fork())<=0)
			break;
		
	
	fprintf(stderr,"este es el proceso %d con padre %d\n",getpid(),getppid());
}
