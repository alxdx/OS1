#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
<<<<<<< HEAD
#include <signal.h>
#include <stdlib.h>

void consumirNumeros(int tuberia);
void generarPares(int tuberia, int t1, int t2);
void generarImpares(int tuberia, int t1, int t2);

int main(int argc, char const *argv[]){

	int tuberia[2];
	int t1[2], t2[2],pid1,pid2;
=======
>>>>>>> 199dc2bde2465e6ae225a2533f8410a9c0793925
	if (pipe(tuberia)<0){
		perror("no se puede crear la tuberia");	
		exit(0);
	}
	if (pipe(t1)<0){
<<<<<<< HEAD
		perror("no se puede crear la tuberia");
		exit(0);
	}
	if (pipe(t2)<0){
		perror("no se puede crear la tuberia");
=======
>>>>>>> 199dc2bde2465e6ae225a2533f8410a9c0793925
		exit(0);
	}

	switch((pid1=fork())){
		case -1: 	perror("error al crear el proceso");
					close(tuberia[0]);
					close(tuberia[1]);
					close(t1[0]);close(t1[1]);
					close(t2[0]);close(t2[1]);	
					exit(0);

		case 0:		close(tuberia[0]);
					//aqui lee de t1 y escribe en t2
					close(t1[1]);close(t2[0]);
					generarImpares(tuberia[1],t1[0],t2[1]);
					//se cierran los descriptores
					close(tuberia[1]);
					close(t1[0]);
					close(t2[1]);
				break;
		default: 	
				switch(pid2=fork()){
					case -1: 	perror("error al crear el proceso");
						close(tuberia[0]);
						close(tuberia[1]);
						close(t1[0]);close(t1[1]);
						close(t2[0]);close(t2[1]);	
						kill(pid1,SIGKILL);
						exit(0);
					case 0:		close(tuberia[1]);
						close(t1[0]);close(t1[1]);
						close(t2[0]);close(t2[1]);	
						consumirNumeros(tuberia[0]);
						close(tuberia[0]);
						exit(0);
					default:	close(tuberia[0]);
						//lee de t2 y escribe en t1
						close(t1[0]); close(t2[1]);
						generarPares(tuberia[1],t1[1],t2[0]);
						close(tuberia[1]);
						close(t1[1]);
						close(t2[0]);
				}
	}
}

void generarPares(int tuberia, int t1, int t2){
<<<<<<< HEAD
	int i=0;
=======
>>>>>>> 199dc2bde2465e6ae225a2533f8410a9c0793925
	char testigo;
	write(tuberia,&i,sizeof(int));
	//cede el turno a p2
	write(t1,&testigo,sizeof(char));
<<<<<<< HEAD
  
	
=======
	for (i = 2; i < 50; i=i+10){
		//espera turno
		read(t2,&testigo,sizeof(char));
		//inserta numero a pipe
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
		//cede turno
		write(t1,&testigo,sizeof(char));
>>>>>>> 199dc2bde2465e6ae225a2533f8410a9c0793925
	}
	return;
}

void generarImpares(int tuberia, int t1, int t2){
<<<<<<< HEAD

=======
	int i=0,aux;
	char testigo;
	for (i = 1; i < 50; i=i+10){
		//espera turno
		read(t2,&testigo,sizeof(char));
		//inserta numero a pipe
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
			write(tuberia,&i,sizeof(int));
			i+=2;
		//cede turno
		write(t1,&testigo,sizeof(char));
>>>>>>> 199dc2bde2465e6ae225a2533f8410a9c0793925
	}
	return;
}

void consumirNumeros(int tuberia){
	int i;
	while((read(tuberia,&i,sizeof(int)))>0){
		printf("%d\n", i);
	}
	return;
<<<<<<< HEAD
}
=======
>>>>>>> 199dc2bde2465e6ae225a2533f8410a9c0793925
