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
	printf("N y Car:\n");
  
	scanf("%d",&info.n);
	scanf("%s",&info.car);
  
	shm_id=shmget(key,sizeof(struct DATA),0666|IPC_CREAT);
	mem=(struct DATA *)shmat(shm_id,0,0);
	*mem=info;
	shmdt(mem);
}

