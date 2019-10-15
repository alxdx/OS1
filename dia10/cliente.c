#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
	

	char archivo[20], *ptrSolicitud;
void printFlujo();
int main(int argc, char const *argv[])
{
	int server=atoi(argv[1]);
  int myId=getpid();
   printf("#cliente - %d\n",myId);
	struct sigaction manejador;
		manejador.sa_handler=printFlujo;
		sigemptyset(&manejador.sa_mask);
		manejador.sa_flags=0;
		sigaction(SIGUSR2,&manejador,NULL);
	
	while(1){
		printf("Archivo: ");
		scanf("%s",archivo);

		key_t keySolicitud=ftok(".",'n');
		int shmSolicitud=shmget(keySolicitud,(sizeof(archivo)+sizeof(int)),0666|IPC_CREAT);
		ptrSolicitud =(char *)shmat(shmSolicitud,NULL,0);
		for (int i = 0; i < 20; ++i)
		{
			*(ptrSolicitud+i)=archivo[i];
		}
          
    *(ptrSolicitud+20)=myId;
    printf("sended: %d",*(ptrSolicitud+20));
		kill(server,SIGUSR1);
    
		pause();

	}

	return 0;
}

void printFlujo(){
	int fileId;
	fileId=open(archivo,0);
	struct stat fileSi;
	fstat(fileId,&fileSi);
	int sizeFile=(int)fileSi.st_size;
	//printf("%d\n",sizeFile);

	key_t keyFile=ftok(".",'c');
	int shmem=shmget(keyFile,sizeFile,0666);
	char *file_mem=(char *)shmat(shmem,NULL,0);
	
  int i=0;
	while(*(file_mem+i)!='\0'){
		printf("%c",*(file_mem+i));
		i++;
	}
	shmdt(file_mem);
   shmctl(shmem,IPC_RMID,NULL);
}
