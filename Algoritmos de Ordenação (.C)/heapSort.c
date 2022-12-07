#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int tamHeap, cont=0;

void heapfy(int array[], int i);
void buildHeap(int array[], int n);
void heapSort(int array[], int n);

int main(){
	setlocale(LC_ALL,"Portuguese");

	int x, tam;
	printf("\nInforme o tamanho do vetor: ");
	scanf("%i",&tam);
	int lista[tam];
	printf("\n");
	for(x=0;x<tam;x++){
		printf("%iº número: ",x+1);
		scanf("%i",&lista[x]);
	}
	
	printf("\n");
	x=0;
	while(x<tam){
		printf("\t%i",lista[x]);
		x++;
	}
	
	heapSort(lista, tam);
	
	x=0;
	printf("\n");
	while(x<tam){
		printf("\t%i",lista[x]);
		x++;
	}
	printf("\n%i",cont);
	
	return 0;
}


void heapfy(int array[], int i){
	int l = 2*i + 1;
	int r = 2*i + 2;
	int m = i;
	int aux;
	
	if(l < tamHeap  && array[l] > array[m])
		m = l;
	if(r < tamHeap  && array[r] > array[m])
		m = r;
	if(m != i){
		aux = array[i];
		array[i] = array[m];
		array[m] = aux;
		heapfy(array, m);
	}
}

void buildHeap(int array[], int tamanho){
	tamHeap = tamanho;
	int i;
	for(i=tamanho/2 - 1; i>= 0; i-- ){
		heapfy(array,i);
	}
}

void heapSort(int array[], int tamanho){
	int aux, i;
	buildHeap(array,tamanho);
	for(i=tamanho-1;i>=0;i--){
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;
		tamHeap--;
		heapfy(array,0);
	}
}
