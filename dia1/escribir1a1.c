#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *archivo;
	int aux,i;

	if(argc>1){
		archivo=fopen("nGuardados.dat","wb");
		int p=atoi(argv[1]);
		fwrite(&p,sizeof(int),1,archivo);
		
		for( i=0;i<p;i++){
			scanf("%d",&aux);

			fwrite(&aux,sizeof(int),1,archivo);
			//printf("%d;%d",i,aux);
		}

		fclose(archivo);
		return 0;
	}
	else
		printf("\n ingresa el numero de datos a guardar\n");

	//return 0;
}

