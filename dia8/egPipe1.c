#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h> 
int main(int argc, char const *argv[])
{
	int n= atoi(argv[1]);
	int fd[2];
	if (fork()==0)
	{
		pipe(fd);
		for (int i = 1; i <= n; ++i){
			write(fd[1],&i,sizeof(int));
		}
	}else{
		for (int i = 1; i <= n; ++i)
		{
			int aux;
			read(fd[0],&aux, sizeof(int));
			printf("%d\n",aux );
		}
	}
	return 0;
}
