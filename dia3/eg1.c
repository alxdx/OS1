#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	int pid,*var;
	if(argc==2){
		pid=creat("datos.dat",0777);
		pid=open("datos.dat",01);
		int n= atoi(argv[1]);
		write(pid,&n,sizeof(int));
		for(int i=0;i<n;i++){
			scanf("%d",var);
			write(pid,var,sizeof(int));
		}
		int aux,toScreen;
		//close(pid);
		//pid=open("datos.dat",02);
		pid=open("datos.dat",02);
		read(pid,&aux,sizeof(int));
		printf("%s","datos leidos:");
		for(int i=0;i<aux;i++){
			read(pid,&toScreen,sizeof(int));
			printf("\n%d",toScreen);
		}
	}
	else
		printf("ingresa numero de datos a guardar");
	return 0;

}
