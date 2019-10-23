#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>
#include <string.h>
struct buf{
	long type;
	char message[50];
};

int main (int argc, char *argv){
 if(fork()==0){
 	struct buf via;
 	key_t msgkey=ftok(".",50);
 	int msid;
	msid=msgget(msgkey, 0666|IPC_CREAT);
	via.type=1;

	strcpy(via.message,"hola padre");
	msgsnd(msid,&via,sizeof(via),0);
	msgrcv(msid,&via,sizeof(via),1,0);
	printf("%s\n",via.message);

 }else{
 	struct buf via;
 	key_t msgkey=ftok(".",50);
 	int msid;
	msid=msgget(msgkey, 0666|IPC_CREAT);
	via.type=1;
	strcpy(via.message,"hola hijo");
	msgsnd(msid,&via,sizeof(via),0);
	msgrcv(msid,&via,sizeof(via),1,0);
	printf("%s\n",via.message);
	
	wait(NULL);
	msgctl(msid,IPC_RMID,NULL);
 return 0;
 }
}
