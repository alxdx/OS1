#include <stdio.h>
#include <stdlib.h>

int main(int argc,  char *argv[]){
	
	FILE *archivo;
	int aux=0;
	archivo=fopen(argv[1],"rb");
	if(archivo!=NULL){
		int p;
		fread(&p,sizeof(int),1,archivo);

		for(int i=0;i<p;i++){
			
			fread(&aux,sizeof(int),1,archivo);
			printf("%d ",aux);
		}
		printf("\n");
		fclose(archivo);
	}
	else
		printf("file error");
	return 0;
}
