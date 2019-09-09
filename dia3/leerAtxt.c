#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include <string.h>

struct ESTUDIANTE{

        char nombre[50];
        char matricula[30];
        int edad;
        char sexo[5];
        char carrera[50];
};



int main(int argc, char *argv[]){

	
        char nombre[50];
        char matricula[30];
	char edad[3];
        char sexo[5];
        char carrera[50];

	int fileId;
        struct ESTUDIANTE var;
	int TXTid,aux;
        struct ESTUDIANTE toTXT;

        fileId=open("estructuras.dat",02);
	printf("id:%d",fileId);
        creat("nuevo.txt",0777);
        TXTid=open("nuevo.txt",02);
        read(fileId,&aux,sizeof(int));
//	printf("n=%d",fileId);
        for(int i=0;i<aux;i++){

		read(fileId,&toTXT,sizeof(struct ESTUDIANTE));
		sprintf(edad,"%i",toTXT.edad);			

                write(TXTid,toTXT.nombre,sizeof(nombre));
                write(TXTid,toTXT.matricula,sizeof(matricula));
                write(TXTid,toTXT.sexo,sizeof(char));
                write(TXTid,toTXT.carrera,sizeof(carrera));
                write(TXTid,edad,sizeof(edad));
		printf("\nalumno %s copiado\n",toTXT.nombre);
        }
        printf("\ndatos copiados a nuevo.txt\n");
	return 0;
}

