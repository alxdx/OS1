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
	int X=8,id;
  int *ptr;
	key_t key;
  key=ftok(".",'b');
  
	if (fork()==0)
	{
    sleep(1);
    id=shmget(key,sizeof(int),0666);
    ptr=shmat(id,NULL,0);
		printf("Entero: %d\n", *ptr);
	}
	else{
    id=shmget(key,sizeof(int),0666|IPC_CREAT);
    ptr=(int *)shmat(id,NULL,0);
    X=2;
    *ptr=X;
    wait(NULL);
    shmdt(ptr);
    shmctl(id, IPC_RMID, NULL);
  }
}
