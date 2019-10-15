#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(int argc, char const *argv[])
{
	int file;
	file=open(argv[1],0);
	struct stat fileSi;
	fstat(file,&fileSi);
	int sizeFile=(int)fileSi.st_size;
	printf("%d\n",sizeFile);

	char DATAFILE[sizeFile],*file_mem;
	read(file, DATAFILE, sizeFile);
	//printf("%s\n",DATAFILE);

	key_t keyFile=ftok(".",'c');
	int shmem=shmget(keyFile,sizeFile,0666|IPC_CREAT);
	file_mem=(char *)shmat(shmem,NULL,0);

	for(int i=0;i<sizeFile+1;i++){
		*(file_mem+i)=DATAFILE[i];
    printf("%c",*(file_mem+i));
	}

	sleep(5);
	key_t keyPID=ftok(".",'d');
	int shmemPID=shmget(keyPID,sizeof(int),0666);
	int *pid_mem=(int *)shmat(shmemPID,NULL,0);

	printf("%d\n",*pid_mem );

	return 0;
}