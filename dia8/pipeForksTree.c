#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/wait.h>

void killFunc();
int s=1;
int main(int argc, char const *argv[])
{
		//R
	int fd[2];
	pipe(fd);
	int aux,dato;
	if (fork()==0){//M 
		if (fork()==0)//Q
		{
			while(s){
					read(fd[0],&aux, sizeof(int));
					printf("\nsoy Q leo el dato %d\n\tpid:%d",aux,getpid()); 
				}

		}
		else{
			if (fork()==0)//z
			{
				if (fork()==0)//s
				{
					if (fork()==0)//t
					{
						while(s){
								read(fd[0],&aux,sizeof(int));
								printf("\nsoy T leo el dato %d\n\tpid:%d",aux,getpid());
							}
					}
					else{
						while(s){
							read(fd[0],&aux,sizeof(int));
							printf("\nsoy S leo el dato %d\n\tpid:%d",aux,getpid());
						}
					}
				}
				else{
					while(s){
							read(fd[0],&aux,sizeof(int));
							printf("\nsoy Z leo el dato %d\n\tpid:%d",aux,getpid());
					}
				}
			}
			else{
				dato=10;
				while(s){
					write(fd[1],&dato,sizeof(int));
					printf("\nsoy M escribo el dato %d\n\tpid:%d",dato,getpid());
				}
			}
		}
	}
	else{
		if (fork()==0)//L
		{
			if (fork()==0)//a
			{
				dato=25;
				while(s){
					write(fd[1],&dato,sizeof(int));
					printf("\nsoy A escribo el dato %d\n\tpid:%d",dato,getpid());
				}
			}
			else{
				if (fork()==0)//w
				{
					if (fork()==0)//b
					{
						while(s){
								read(fd[0],&aux,sizeof(int));
								printf("\nsoy B leo el dato %d\n\tpid:%d",aux,getpid());
						}
					}
					else{
						if (fork()==0)//D
						{
							if (fork()==0)//F
							{
								dato=50;
								while(s){
									write(fd[1],&dato,sizeof(int));
									printf("\nsoy F escribo el dato %d\n\tpid:%d",dato,getpid());
								}

							}
							else{
								if (fork()==0)//E
								{
									dato=55;
									while(s){
										write(fd[1],&dato,sizeof(int));
										printf("\nsoy E escribo el dato %d\n\tpid:%d",dato,getpid());
									}

								}
								else{
									dato=45;
									while(s){
										write(fd[1],&dato,sizeof(int));
										printf("\nsoy D escribo el dato %d\n\tpid:%d",dato,getpid());
									}

								}
							}
						}
						else{//lo que hace W
							while(s){
								read(fd[0],&aux,sizeof(int));
								printf("\nsoy W leo el dato %d\n\tpid:%d",aux,getpid());
							}

						}
					}
				}
				else{
					if (fork()==0)//k
					{
						while(s){
							read(fd[0],&aux,sizeof(int));
							printf("\nsoy K leo el dato %d\n\tpid:%d",aux,getpid());
						}

					}
					else{
						//lo que hace L 
						dato=20;
						while(s){
							write(fd[1],&dato,sizeof(int));
							printf("\nsoy L escribo el dato %d\n\tpid:%d",dato,getpid());
						}

					}
				}
			}
		}
		else{
		//lo que hace R
			alarm(5);
			struct sigaction killer;
			killer.sa_handler=killFunc;
			killer.sa_flags=0;
			sigemptyset(&killer.sa_mask);
			sigaction(SIGALRM,&killer,NULL);
		}
	}
	return 0;
}

void killFunc(){
	s=0;
}
