
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[]){

    pid_t pid1, pid2;
    int status1, status2;
    int file1,file2; 
    if ( (pid1=fork()) == 0 ){ //hijo
        printf("Soy el primer hijo (%d, hijo de %d)\n",  getpid(), getppid());
        file1=creat("datos.dat",0777);
        file1=open("datos.dat",01);
        for(int i=2;i<=20;i+=2){
            write(file1,&i,sizeof(int));
        }
    }
    else{ //padre

        if ( (pid2=fork()) == 0 ){ //hijo2
            printf("Soy el segundo hijo (%d, hijo de %d)\n",  getpid(), getppid());
            file2=creat("datos2.dat",0777);
            file2=open("datos2.dat",01);
            for(int i=1;i<20;i+=2){
                write(file2,&i,sizeof(int));
            }

        }
        else{ //padre
            int a,b,suma;
            waitpid(pid1, &status1, 0);
            waitpid(pid2, &status2, 0);
            file1=open("datos.dat",00);            
            file2=open("datos2.dat",00);

            printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
            for (int i = 0; i < 10; ++i){
                read(file1,&a,sizeof(int));
                read(file1,&b,sizeof(int));
                suma=a+b;
                printf("%d + %d = %d\n",a,b,suma);
            }

        }
    }
 
    return 0;
}