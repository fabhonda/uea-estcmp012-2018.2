//Insertion Sort com ordem crescente
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int i,j,n,chave,tam;
	
	printf("\nInforme o tamanho do vetor: ");
	scanf("%d",&tam);
	int numeros[tam];
	
	printf("\n");
	for(n=0;n<tam;n++){
		printf("Digite o %dº número: ",n+1);
		scanf("%d",&numeros[n]);
	}
	
	printf("\nVetor: \t\t ");
	for(n=0;n<tam;n++){
		printf("%d\t",numeros[n]);
	}
	
	for(j=1;j<tam;j++){
		chave = numeros[j];
		i=j-1;
		while(i>=0 && numeros[i] > chave){
			numeros[i+1] = numeros[i];
			i--;
		}
		numeros[i+1] = chave;
	}
	
	printf("\nVetor ordenado: ");
	for(n=0;n<tam;n++){
		printf("%d\t",numeros[n]);
	}
	
	return 0;
}
