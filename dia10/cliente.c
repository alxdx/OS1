#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


#define MAX_NAME 100
#define MAX 10000
 //tipo 1 numero de elementos
//tipo 2 nombe de archios
//tipo 3 datos
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[MAX_NAME]; 
};
struct data_buffer
{
	long data_type;
	char data_doc[MAX];
};

int main(int argc, char const *argv[])
{
	struct  data_buffer fileData;
	struct mesg_buffer message;
 	key_t key; 
    int msgid; 
	int n;

	key = ftok(".", 65); 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.mesg_type = 1; 
    printf("Cuantos documentos?: ");
    fgets(message.mesg_text,MAX_NAME,stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    n=atoi(message.mesg_text);

    message.mesg_type = 2;
    for (int i = 0; i < n; ++i)
    {
		scanf("%s",message.mesg_text);
		msgsnd(msgid, &message, sizeof(message), 0);
    
		msgrcv(msgid, &fileData, sizeof(fileData),3,0); 
    	printf(">> %s \n",fileData.data_doc); 

    }
        msgctl(msgid, IPC_RMID, NULL); 
	return 0;
}