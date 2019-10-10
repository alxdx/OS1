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
	key_t key=ftok(".",'o');
	shm_id=shmget(key,sizeof(IMPARES)*2,0666);
	ptr=(int *)shmat(shm_id,NULL,0);

	for (int i =N; i < (2*N); ++i)
	{
		*(ptr+i)=IMPARES[i];
	}
  for (int i = N; i < (2*N); ++i)
	{
		printf("%d\n",*(ptr+i));
	}
  
	shmdt(ptr);
	return 0;
}