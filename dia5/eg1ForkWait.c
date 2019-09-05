#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	pid_t pid;
	int file1;
	int status;
	if((pid=fork())==0){
		creat("datos.dat",0777);
		file1=open("datos.dat",01);
		for(int i=1;i<=10;i++){
			write(file1,&i,sizeof(int));
		}
	}else{
		wait(&status);
		int n;
		file1=open("datos.dat",00);
		for(int i=1;i<=10;i++){
  		read(file1,&n,sizeof(int));
  		printf("%d\n",n );
		}    
	}

	return 0;
}


