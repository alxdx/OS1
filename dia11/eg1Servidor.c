#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    key = ftok(".", 65); 
  
    msgid = msgget(key, 0666 | IPC_CREAT); 
    message.mesg_type = 1; 
  
    printf("Escribe Algo: "); 
    gets(message.mesg_text); 
  
    msgsnd(msgid, &message, sizeof(message), 0);   
    return 0; 
} 