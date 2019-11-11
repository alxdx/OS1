#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/shm.h>
#define MAX 2000
#define PASO 5

void generarPares(int memoria, int t1, int t2,int t3);
void generarImpares(int memoria, int t1, int t2,int t3);
void consumirNumeros(int memoria,int t3);

int main(int argc, char const *argv[]){


	int t1[2], t2[2],t3[2],pid1,pid2;
	int shmId;
	key_t key=ftok(".",'a');
	shmId=shmget(key,sizeof(int)*(PASO*2),0666|IPC_CREAT);
	
	if (pipe(t1)<0){
		perror("no se puede crear la tuberia: ");	
		exit(0);
	}
	if (pipe(t2)<0){
		perror("no se puede crear la tuberia: ");	
		exit(0);
	}
	if (pipe(t3)<0){
		perror("no se puede crear la tuberia: ");	
		exit(0);
	}

	switch((pid1=fork())){
		case -1: 	perror("error al crear el proceso");
					close(t1[0]);close(t1[1]);
					close(t2[0]);close(t2[1]);	
					close(t3[0]);close(t3[1]);	
					exit(0);

		case 0:		//aqui lee de t1 y escribe en t2
					close(t1[1]);close(t2[0]);close(t3[0]);
					generarImpares(shmId,t1[0],t2[1],t3[1]);
					//se cierran los descriptores
					close(t1[0]);
					close(t2[1]);
					close(t3[1]);
				break;
		default: 	
				switch(pid2=fork()){
					case -1: 	perror("error al crear el proceso");
						close(t1[0]);close(t1[1]);
						close(t2[0]);close(t2[1]);	
						kill(pid1,SIGKILL);
						exit(0);
					case 0:		
						close(t1[0]);close(t1[1]);
						close(t2[0]);close(t2[1]);
						close(t3[1]);	
						consumirNumeros(shmId,t3[0]);
            close(t3[0]);
            exit(0);
					default:
						//lee de t2 y escribe en t1
						close(t1[0]); close(t2[1]);close(t3[0]);
						generarPares(shmId,t1[1],t2[0],t3[1]);
						close(t1[1]);
						close(t2[0]);
						close(t3[1]);
            
				}
	}
}

void generarPares(int shmId, int t1, int t2,int t3){
	int i=0;
	char testigo;
	int *ptr;
	ptr=shmat(shmId,NULL,0);
  int k=0;
  for (i = 0; i <(PASO*2) ;i+=2){
		*(ptr+k)=i;
	  //printf("->%d\n",*(ptr+k));
    k++;
	}
  //cede el turno a p2
  write(t3,&testigo,sizeof(char));
  write(t1,&testigo,sizeof(char));
  
	for (int i = (PASO*2); i < MAX; i=i+(PASO*2)){
		//espera turno
		read(t2,&testigo,sizeof(char));
		//inserta numero a memoria
    int h=0;
    for (int j = i; j <(i+(PASO*2)) ;j+=2){
			*(ptr+h)=j;
		  //printf("->%d\n",*(ptr+h));
      h++;
		}
		write(t3,&testigo,sizeof(char));
    //cede turno
		write(t1,&testigo,sizeof(char));
	}
		shmdt(ptr);

	return;
}

void generarImpares(int shmId, int t1, int t2,int t3){
	int i=0;
	char testigo;
	int *ptr;
	ptr=shmat(shmId,NULL,0);
	for (i = 1; i < MAX; i=i+(PASO*2)){
		//espera turno
		read(t1,&testigo,sizeof(char));
		//inserta numero a memoria
		int h=PASO;
    for (int j = i; j <(i+(PASO*2)) ;j+=2){
			*(ptr+h)=j;
		  //printf("->%d\n",*(ptr+h));
      h++;
		}
		write(t3,&testigo,sizeof(char));
		//cede turno
		write(t2,&testigo,sizeof(char));
	}
		shmdt(ptr);
	return;
}

void consumirNumeros(int shmId,int t3){
	int *i;
  int band=1;
	char testigo;
	i=shmat(shmId,NULL,0);
	int j=0;
	while(j<(MAX/PASO)){
		read(t3,&testigo,sizeof(char));
		if(band){
      int h=0;
      for (int k = 0; k <PASO ;k+=1){
        printf("%d\n", *(i+h));
        h++;
      }
      band=0;
    }else{
      int h=PASO;
      for (int k = 0; k <PASO ;k+=1){
        printf("%d\n", *(i+h));
        h++;
      }
      band=1;      
    }
	  j+=1;
  }
	shmdt(i);
	shmctl(shmId,IPC_RMID,NULL);
	return;
}
  