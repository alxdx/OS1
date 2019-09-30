
//ejercicios en 144
//programa 2.9 run back y ls -l &
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h> 
#include <signal.h>
void leeDatos();

int main(int argc, char const *argv[]){
	pid_t pid;
	if((pid=fork())==0){
		int file1,aux;
		creat("datos.dat",0777);
		file1=open("datos.dat",01);
		for(int i=1;i<=10;i++){
			aux=i*3;
			write(file1,&aux,sizeof(int));
		}
		kill(getppid(),SIGUSR1);
	}
	else{
		struct sigaction manejador;
		manejador.sa_handler=leeDatos;
		sigemptyset(&manejador.sa_mask);
		manejador.sa_flags=0;
		sigaction(SIGUSR1,&manejador,NULL);
		pause();
	}
	return 0;
}

void leeDatos(){
	int file,aux;
	file= open("datos.dat", 00);
	for (int i = 0; i < 10; ++i){
		read(file,&aux,sizeof(int));
		printf("%d\n",aux );
	}
}