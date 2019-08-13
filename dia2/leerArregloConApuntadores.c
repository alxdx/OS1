#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[] ){
	if(argc==2){
		
		int arreglo[20];
		int *ptr=arreglo;
		int n;
		n=atoi(argv[1]);
		
		for(int i=0;i<n;i++){
			scanf("%d",(ptr+i));
		}

		ptr=arreglo;
		printf("%c elementos leidos: \n",argv[1]);

		for(int i=0;i<n;i++){
			printf("%d ",*ptr++);
		}
	}else{
		printf("\n ingrese nnumero de enteros a leer \n");
	}
	return 0;
}
