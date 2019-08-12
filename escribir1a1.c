#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *archivo;
	int aux;
	if(argc>2){
		fopen("nGuardados.dat","wb");
		int n=argc-2;
		int p=atoi(argv[1]);
		for(int i=O;i<p;i++){
			scanf("%i",&aux);
			fwrite(&aux,sizeof(int),1,archivo);
		}

		fclose(archivo);
	}
	else
		printf("\n ingresa el numero de datos a guardar");

}

