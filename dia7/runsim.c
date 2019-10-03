#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define MAX_CANON 100

void  parse(char *line, char **argv){
     while (*line != '\0') {        
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     
          *argv++ = line;          
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             
     }
     *argv = '\0';                 
}

int main(int argc, char *argv[] ){

	if(argc==3){
		int pr_limit=atoi(argv[1]);
		int pr_count=0;
		FILE *file;
		char line[MAX_CANON],*arLine[MAX_CANON];
		file=fopen(argv[2],"r");
		
		while(fgets(line,sizeof(char)*100,file)!=NULL){
			parse(line,arLine);
			if(pr_count==pr_limit){
				wait(NULL);
				pr_count--;
			}else{
				pid_t pid;
				pr_count++;
				if((pid=fork())==0){
					if(execvp(*arLine,arLine)<0)
						perror("exec");
				}
				else{
				//	printf("%s",line);
					waitpid(pid,NULL,WNOHANG);	
						pr_count--;

				}
				
			}
		}
		for(pr_limit;pr_limit>=0;pr_limit--){
			wait(NULL);
		}
	}
	else
		printf("ingrese dos argumentos\n");
}
