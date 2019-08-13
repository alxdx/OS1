
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	FILE *archivo;
	int n=argc,data[20];

	for(int i=0;i<n-1;i++){
		data[i]=atoi(argv[i+1]);
	}
	
	if(argc>1){
		
		archivo=fopen("vectorLeido.dat","wb");
		if(archivo!=NULL){
			
			fwrite(data,sizeof(int),n-1,archivo);
			 fclose(archivo);
		}
		else
			printf("FILE ERROR");
	
	}
	return 0;
}

