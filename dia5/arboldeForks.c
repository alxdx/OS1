#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
 int main(int argc, char const *argv[]){
 	pid_t seedPid;
 	int status;
 	//R
	printf("\nSoy %d hijo de %d\n",getpid(),getppid());
 	if ((seedPid=fork())==0){//M
 		wait(&status);
 		printf("Soy M %d hijo de %d\n",getpid(),getppid());
 		if(fork()==0){//Q
	 		wait(&status);
	 		printf("Soy %d hijo de %d\n",getpid(),getppid());
 		}
 		else{
 		wait(&status);
 			if(fork()==0){//A
		 		printf("Soy %d hijo de %d\n",getpid(),getppid());
 				if(fork()==0){//z
			 		printf("Soy %d hijo de %d\n",getpid(),getppid());
 				}
 				else{
		 		wait(&status);
 					if(fork()==0){//N
				 		printf("Soy %d hijo de %d\n",getpid(),getppid());
 						if(fork()==0)//S
					 		printf("Soy %d hijo de %d\n",getpid(),getppid());
            else
              wait(&status);
 					}
 					else
			 		wait(&status);
 				}
 			}
 			else
 				wait(&status);
 		}
 	}else{
 		wait(&status);
 		if(fork()==0){//L
	 		printf("Soy L %d hijo de %d\n",getpid(),getppid());
 			if(fork()==0){//K
		 		printf("Soy %d hijo de %d\n",getpid(),getppid());
 			}else{
	 		wait(&status);
 				if(fork()==0){//G
			 		printf("Soy %d hijo de %d\n",getpid(),getppid());
			 		if(fork()==0){//B
				 		printf("Soy %d hijo de %d\n",getpid(),getppid());
			 		}
          			else
            		wait(&status);
 				}else{
		 		wait(&status);
 					if(fork()==0){//D
				 		printf("Soy %d hijo de %d\n",getpid(),getppid());
 					}else
			 		wait(&status);
 				}
 			}

 		}else
		wait(&status);
 	}
 	return 0;
 }