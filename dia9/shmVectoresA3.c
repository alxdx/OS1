#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	int N=atoi(argv[1]);
  int ARR[N];
	int shm_idPar,shm_idImpar,*ptrPar,*ptrImpar;
	key_t keyPar=ftok(".",'a');
  key_t keyImpar=ftok(".",'e');

	shm_idPar=shmget(keyPar,sizeof(ARR),0666);
  shm_idImpar=shmget(keyImpar,sizeof(ARR),0666);
	
  ptrPar=(int *)shmat(shm_idPar,NULL,0);
  ptrImpar=(int *)shmat(shm_idImpar,NULL,0);
  int suma=0;
	
  for (int i = 0; i < N; ++i)
	{
    suma+=*(ptrPar+i)+*(ptrImpar+i);
		printf("%d\n",suma);
	}
  shmdt(ptrPar);
  shmdt(ptrImpar);
  shmctl(shm_idPar,IPC_RMID,NULL);
  shmctl(shm_idImpar,IPC_RMID,NULL);
	return 0;
}