#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

main(int args, char *argv[] ) {

	char *temp[] = {NULL,argv[1],argv[2],NULL};
	temp[0]="./hijo";
	execve("./hijo",temp,NULL);
	printf("world");
}