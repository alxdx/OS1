#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *archivo;
<<<<<<< HEAD
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
=======
>>>>>>> e6270a1b3694037217f669df51529a10a6ac1bdf
}

