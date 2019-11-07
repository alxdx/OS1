#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>

	char archivo[20],*ptrSolicitud;
	int pid;
void leeDatos();
int main(int argc, char const *argv[])
{
	struct sigaction manejador;
		manejador.sa_handler=leeDatos;
		sigemptyset(&manejador.sa_mask);
		manejador.sa_flags=0;
		sigaction(SIGUSR1,&manejador,NULL);
		printf("Servidor- ID %d\n", getpid());
		while(1){
			pause();
		}



	return 0;
}

void leeDatos(){
	key_t keySolicitud=ftok(".",'n');
	int shmSolicitud=shmget(keySolicitud,(sizeof(archivo)+sizeof(int)),0666);
	ptrSolicitud =(char *)shmat(shmSolicitud ,NULL,0);
	for (int i = 0; i < 20; ++i)
	{
		archivo[i]=*(ptrSolicitud+i);
	}
	pid=*(ptrSolicitud+(sizeof(archivo)));
	printf("%s\n",archivo);
	printf("from:%d\n",pid);

	shmdt(ptrSolicitud);
	shmctl(shmSolicitud,IPC_RMID,NULL);

	/*****/
	int fileId;
	fileId=open(archivo,0);
	struct stat fileSi;
	fstat(fileId,&fileSi);
	int sizeFile=(int)fileSi.st_size;
	printf("%d\n",sizeFile);

	char DATAFILE[sizeFile],*file_mem;
	read(fileId, DATAFILE, sizeFile);

	key_t keyFile=ftok(".",'c');
	int shmem=shmget(keyFile,sizeFile,0666|IPC_CREAT);
	file_mem=(char *)shmat(shmem,NULL,0);

	for(int i=0;i<sizeFile+1;i++){
		*(file_mem+i)=DATAFILE[i];
    printf("%c",*(file_mem+i));
	}
  int gg=getpid();
	kill((gg+1),SIGUSR2);
  printf("señal no enviada");
}