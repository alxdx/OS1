#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	FILE *archivoOrigen, *archivoDestino;
	int n;
	int aux;
	if(argc==3){
		archivoOrigen=fopen(argv[1],"rb");
		archivoDestino=fopen(argv[2],"wb");
		fread(&n,sizeof(int),1,archivoOrigen);

		int i;
		for(i=0;i<n;i++){
			fread(&aux,sizeof(int),1,archivoOrigen);
			fprintf(archivoDestino,"%d\n",aux);
		}
		fclose(archivoOrigen);
		fclose(archivoDestino);
	}
	else
		printf("\n ingrese dos parametros [Origen.dat] [destino.txt]\n");

	return 0;
}
