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
	int IMPARES[N];
	for (int i = 0; i < N; ++i)
	{
		IMPARES[i]=2*i+1;
	}

	int shm_id,*ptr;
	key_t key=ftok(".",'e');
	shm_id=shmget(key,sizeof(IMPARES),0666|IPC_CREAT);
	ptr=(int *)shmat(shm_id,NULL,0);

	for (int i =0; i <N; ++i)
	{
		*(ptr+i)=IMPARES[i];
	}
  
	shmdt(ptr);
	return 0;
}