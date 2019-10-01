#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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
		FILE *f;
		char line[100],*arLine[100];
		f=fopen(argv[2],"r");
		while(fgets(line,sizeof(char)*100,f)!=NULL){
			parse(line,arLine);
				if(fork()==0){
					if(execvp(*arLine,arLine)<0)
						perror("exec");
				}
				else{
					pr_count++;

				}
		}
		
	}
	else
		printf("ingrese solo un argumento\n");
}
