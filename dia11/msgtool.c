#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MAX_SEND_SIZE 80

struct mymsgbuf{
  long mtype;
  char mtext[MAX_SEND_SIZE];
};
void send_message(int qid,struct mymsgbuf *qbuf,long type,char *text);
void read_message(int qid,struct mymsgbuf *qbuf,long type);
void remove_queue(int qid);
void change_queue_mode(int qid,char *mode);
void usage();

int main(int argc, char const *argv[])
{
	key_t key;
	int msgqueue_id;
	struct mymsgbuf qbuf;
	if (argc ==1)
		usage();

	key=ftok(".",'m');
	if ((msgqueue_id=msgget(key,IPC_CREAT|0660))== -1)
	{
		perror("msgget");
		exit(1);
	}
	switch(tolower(argv[1][0])){
		case 'e':send_message(msgqueue_id,(struct mymsgbuf *)&qbuf,atol(argv[2]),argv[3]);
			break;
		case 'r':read_message(msgqueue_id,&qbuf,atol(argv[2]));
			break;
		case 'b':remove_queue(msgqueue_id);
			break;
		case 'm': change_queue_mode(msgqueue_id,argv[2]);
			break;
		default: usage();
	}
	return 0;
}

void send_message(int qid,struct mymsgbuf *qbuf,long type,char *text){
	printf("%s\n","Enviando mensaje...");
	qbuf->mtype=type;
	strcpy(qbuf->mtext,text);
	if ((msgsnd(qid,(struct msgbuf *)qbuf,strlen(qbuf->mtext)+1,0))==-1)
	{
		perror("msgsnd");
		exit(1);
	}
}
void read_message(int qid,struct mymsgbuf *qbuf,long type){
	printf("%s\n","leyendo mensaje...");
	qbuf->mtype=type;
	msgrcv(qid,(struct msgbuf *)qbuf,MAX_SEND_SIZE,type,0);
	printf("Tipo: %ld Texto: %s\n", qbuf->mtype,qbuf->mtext);
}

void remove_queue(int qid){
	msgctl(qid,IPC_RMID,0);
}

void change_queue_mode(int qid,char *mode){
	struct msqid_ds myqueue_ds;
	msgctl(qid,IPC_STAT,&myqueue_ds);
	sscanf(mode,"%ho",&myqueue_ds.msg_perm.mode);
	msgctl(qid,IPC_SET,&myqueue_ds);
}

void usage(){
	fprintf(stderr, "msgtool -utilidad de manejo de colas de mensajes\n");
	fprintf(stderr, "\nUSO: msgtool (e)nviar <tipo><texto>\n");
	fprintf(stderr, "\n             (r)ecibir <tipo>\n");
	fprintf(stderr, "\n             (b)orrar\n");
	fprintf(stderr, "\n             (m)odo <modo octal>\n");
	exit(1);
}