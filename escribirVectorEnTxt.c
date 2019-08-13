#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
	FILE *archivoOrigen,*archivoDestino;
	int vector[20],i;
	if(argc==3){

		archivoOrigen=fopen(argv[1],"rb");
		archivoDestino=fopen(argv[2],"wb");
		int conta=fread(vector,sizeof(int),20,archivoOrigen);
		for(i=0;i<conta;i++){
			fprintf(archivoDestino,"%d\n",vector[i]);
		}
		fclose(archivoOrigen);
		fclose(archivoDestino);
	}
	else
		printf("ingrese dos nombres [origen.dat] [destino.txt]");
return 0;
}
