
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
void handler1();
void handler2();

int main(int argc, char *argv[]){

    pid_t pid1, pid2;
    int status1, status2;
    int file1,file2;
    struct sigaction p,q;
        	p.sa_handler=handler1;
        	sigemptyset(&p.sa_mask);
        	p.sa_flags=0;

        	q.sa_handler=handler2;
        	sigemptyset(&q.sa_mask);
        	q.sa_flags=0;

    if ( (pid1=fork()) == 0 ){ //hijo
        printf("Soy el primer hijo (%d, hijo de %d)\n",  getpid(), getppid());
        file1=creat("datos.dat",0777);
        file1=open("datos.dat",01);
        for(int i=2;i<=20;i+=2){
            write(file1,&i,sizeof(int));
        }
        	kill(getppid(),SIGUSR1);
	
    }
    else{

        if ( (pid2=fork()) == 0 ){ //hijo2
            printf("Soy el segundo hijo (%d, hijo de %d)\n",  getpid(), getppid());
            file2=creat("datos2.dat",0777);
            file2=open("datos2.dat",01);
            for(int i=1;i<20;i+=2){
                write(file2,&i,sizeof(int));
            }
        	kill(getppid(),SIGUSR2);

        }
        else{ //padre
        	
        	(sigaction(SIGUSR1,&p,NULL))
        		pause();
        		sigaction(SIGUSR2,&q,NULL);
        	pause();
        	pause();
        }
    }
 
    return 0;
}
void handler1(){
	printf("1 ok\n");
}
void handler2(){
            int a,b,suma;
	        int file1=open("datos.dat",00);            
            int file2=open("datos2.dat",00);

            printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
            for (int i = 0; i < 10; ++i){
                read(file1,&a,sizeof(int));
                read(file2,&b,sizeof(int));
                suma=a+b;
                printf("%d + %d = %d\n",a,b,suma);
            }
}
