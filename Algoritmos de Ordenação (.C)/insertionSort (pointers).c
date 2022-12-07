//Insertion Sort com ordem crescente e ponteiros começando pelo segundo elemento
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void insertionSort(int *lista, int tamanho);

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
	
	insertionSort(numeros,tam);
	
	printf("\nVetor ordenado: ");
	for(n=0;n<tam;n++){
		printf("%d\t",numeros[n]);
	}
	
	return 0;
}

void insertionSort(int *lista,int tamanho){
	int i,j, aux;
		for(i=1;i<tamanho;i++){
			aux = *(lista+i);
			j=i-1;
			while((*(lista+j) > aux) && (j>=0)){
				*(lista+j+1) = *(lista+j);
				*(lista+j) = aux;
				j--;
			}
		}
}
