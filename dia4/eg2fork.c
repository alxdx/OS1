#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    pid_t pid1, pid2;
    int status1, status2;
 	int a=7,b=8;
    if ( (pid1=fork()) == 0 ){ /*  padre */
        if ( (pid2=fork()) == 0 ){ /*  nieto */
            int resResta=b-a;
 			printf("resultado resta:%d\n",resResta);
			printf("Proceso : %d, hijo de %d\n",getpid(), getppid());
        }
        else{ /*  padre */
            wait(&status2);
 			
 			int resSuma=a+b;
 			printf("resultado suma:%d\n",resSuma);

            printf("Proceso: %d, hijo de %d\n",getpid(), getppid());
        }
    }
    else{ /* abuelo */
        wait(&status1);
		printf("padre: \n  Proceso: %d, hijo de %d\n", getpid(),getppid());
    }
 
    return 0;
}