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
	int shm_id,*ptr;
	key_t key=ftok(".",'o');
	shm_id=shmget(key,sizeof(ARR)*2,0666);
	ptr=(int *)shmat(shm_id,NULL,0);
  int suma=0;
	for (int i = 0; i < N; ++i)
	{
    suma+=*(ptr+i)+*(ptr+N+i);
		printf("%d\n",suma);
	}
  shmdt(ptr);
  shmctl(shm_id,IPC_RMID,NULL);
	return 0;
}