
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *archivo;
	int n=argc,data[100],conta=0;
	char *name,*d;
	if(argc==2){

		name=argv[1];
		archivo=fopen(name,"rb");
		if(archivo!=NULL){
			 
			 conta=fread(data,sizeof(int),100,archivo);
			  
			 fclose(archivo);
			 
			 for(int  i=0;i<conta;i++ ){
				printf("%d ",data[i]);
			 }
		}
		else
			printf("FILE ERROR");
	
	}
	else
		printf("ingrese un nombre de archivo");
	return 0;
}

