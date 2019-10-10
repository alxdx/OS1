#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

struct DATA
{
	int n;
	char car;
};

int main(int argc, char const *argv[]){
	key_t key;
	int shm_id;
	struct DATA *mem,info;
	key=ftok(".",'o');
  
	shm_id=shmget(key,sizeof(struct DATA),0666);
	mem=(struct DATA *)shmat(shm_id,0,0);

	info=*mem;
	
	for (int i = 0; i < info.n; ++i)
	{
		printf("%c\n",info.car);
	}
	shmdt(mem);
  shmctl(shm_id,IPC_RMID,NULL);
}

