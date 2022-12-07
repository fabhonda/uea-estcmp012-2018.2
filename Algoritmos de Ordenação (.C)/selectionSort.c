#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main(){
	int i,j,n,min,temp;
	int numeros[5]={5,1,9,6,8};
	
	for(n=0;n<TAM;n++){
		printf("\t%d",numeros[n]);
	}
	
	for(i=0;i<TAM-1;i++){
		min = i;
		for(j=i+1;j<TAM;j++){
			if(numeros[min] > numeros[j]) {
				min = j;
			}
		}
		temp  = numeros[min];
		numeros[min] = numeros[i];
		numeros[i] = temp;
	}
	
	printf("\n");
	for(n=0;n<TAM;n++){
		printf("\t%d",numeros[n]);
	}
	
	return 0;
}
