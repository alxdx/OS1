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

	key_t keyPID=ftok(".",'d');
	int shmemPID=shmget(keyPID,sizeof(int),0666|IPC_CREAT);
	int *pid_mem=(int *)shmat(shmemPID,NULL,0);
	*pid_mem=200;
	//printf("%lu\n",sizeFile);

	sleep(5);
	key_t keyFile=ftok(".",'c');
	int shmem=shmget(keyFile,492,0666);
	char *file_mem=(char *)shmat(shmem,NULL,0);
	
  int i=0;
	while(*(file_mem+i)!='\0'){
		printf("%c",*(file_mem+i));
		i++;
	}
  
  shmdt(file_mem);
   shmctl(shmem,IPC_RMID,NULL);
  shmdt(pid_mem);
   shmctl(shmemPID,IPC_RMID,NULL);
  
	return 0;
}