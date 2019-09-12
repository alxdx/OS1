#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include <string.h>
struct ESTUDIANTE{
	char nombre[50];
	char matricula[30];
	int  edad;
	char sexo[5];
	char carrera[50];
};

int main(int argc, char *argv[]){
	int fileId;	
	struct ESTUDIANTE var;
	if(argc==2){
		creat("estructuras.dat",0777);
		fileId=open("estructuras.dat",01);
		int n=atoi(argv[1]);
		int debug;
		write(fileId,&n,sizeof(int));
		for(int i=0;i<n;i++){
			printf("%s\n","nombre:");
			fgets(var.nombre,50,stdin);
			printf("%s\n","matricula:");
			fgets(var.matricula,30,stdin);
			printf("%s\n","sexo:");
			fgets(var.sexo,5,stdin);
			printf("%s\n","carrera:");
			fgets(var.carrera,50,stdin);
			printf("%s\n","edad:");
			scanf("%i",&var.edad);
		
			debug=write(fileId,&var,sizeof(struct ESTUDIANTE));
		//	printf("debug:%d",debug);
		}
	//	printf("%s",var.nombre);
		
	/*	int TXTid,aux;
		struct ESTUDIANTE toTXT;
		fileId=open("estructuras.dat",02);
		creat("estructuras.txt",0777);
		TXTid=open("estructuras.txt",02);
		read(fileId,&aux,sizeof(int));		
		for(int i=0;i<aux;i++){
			read(fileId,&toTXT,sizeof(struct ESTUDIANTE));
			write(TXTid,&toTXT,sizeof(struct ESTUDIANTE));
		}
		printf("\ndatos copiados a estructuras.txt\n");
	*/	
		//printf("%s",var.matricula);
	}
	else
		printf("\ningresa numero de estudiantes a guardar\n");
	return 0;
}
