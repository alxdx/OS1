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
	int PARES[N];
	for (int i = 1; i <= N; ++i)
	{
		PARES[i-1]=2*i;
	}

	int shm_id,*ptr;
	key_t key=ftok(".",'o');
	shm_id=shmget(key,sizeof(PARES)*2,0666|IPC_CREAT);
	ptr=(int *)shmat(shm_id,NULL,0);

	for (int i = 0; i < N; ++i)
	{
		*(ptr+i)=PARES[i];
	}
	shmdt(ptr);
	return 0;
}