#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(){
	int i,j,n,aux;
	int numeros[]={5,9,1,6,8};
	
	for(n=0;n<TAM;n++){
		printf("\t%d",numeros[n]);
	}
	
	for(i=0;i<TAM-1;i++){
		for(j=0;j<TAM-i-1;j++){
			if(numeros[j] > numeros[j+1]){
				aux = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = aux;
			}
		}
	}
	
	printf("\n");
	for(n=0;n<TAM;n++){
		printf("\t%d",numeros[n]);
	}
	
	return 0;
	
}
