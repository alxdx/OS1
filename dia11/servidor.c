#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
#define MAX_NAME 100
#define MAX 10000
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[MAX_NAME]; 
};
struct data_buffer
{
	long data_type;
	char data_doc[MAX]
};

int main(int argc, char const *argv[])
 {
	struct mesg_buffer message;
	struct  data_buffer fileData;

 	key_t key; 
    int msgid;
    int n; 
  
    key = ftok(".", 65); 
    msgid = msgget(key, 0666 | IPC_CREAT); 

    msgrcv(msgid, &message, sizeof(message), 1, 0); 
    n=atoi(message.mesg_text);
 
    for (int i = 0; i < n; ++i)
    {
    	msgrcv(msgid, &message, sizeof(message), 2, 0); 
    	printf(">> %s \n",message.mesg_text); 

    	/*lee y manda archivo*/
    	int fileId;
		fileId=open(message.mesg_text,0);
		struct stat fileSi;
		fstat(fileId,&fileSi);
		int sizeFile=(int)fileSi.st_size;
		printf("%d\n",sizeFile);
		fileData.data_type=3;
		read(fileId,fileData.data_doc,sizeFile);
		msgsnd(msgid, &fileData, sizeof(fileData), 0);
    }

 	return 0;
 } 