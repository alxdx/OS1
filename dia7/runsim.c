#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char *argv[] ){

	if(argc==3){
		int pr_limit=atoi(argv[1]);
		int pr_count=0,file;
		char line[20];
		file=open(argv[2],00);

		while(read(file,line,sizeof(char)*20>=1)){
			if(pr_count==pr_limit){
				wait(NULL);
				pr_count--;
			}else{
				if(fork()==0){
					if(execvp())
				}
				printf("%s",line);
			}
		}
	}
	else
		printf("ingrese solo un argumento\n");
}
