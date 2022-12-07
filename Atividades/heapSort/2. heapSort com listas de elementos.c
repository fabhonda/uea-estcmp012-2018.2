#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int tamHeap;

void heapfy(int array[], int i);
void buildHeap(int array[], int n);
void heapSort(int array[], int n);
void imprimir(int array[], int tam);

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	//Listas crescentes para ordenar
	int lista1[]={1,2,3,4,5,6,7,8};
	int lista2[]={10,20,30,40,50};
	int lista3[]={1,3,5,7,11,13,17};
	
	//Listas decrescentes para ordenar
	int lista4[]={10,9,8,7,6,5,4};
	int lista5[]={500,400,300,200,100};
	int lista6[]={50,45,40,35,30};
	
	//Listas desordenadas aleatoriamente
	int lista7[500];
	int lista8[500];
	int lista9[500];
	
	int x;
	for(x=0; x<500;x++){
		lista7[x] = rand()%100;
		lista8[x] = rand()%100;
		lista9[x] = rand()%100;
	}
	
	int indice_lista, tam;
	printf("Informe a lista a ser ordenada: ");
	scanf("%i",indice_lista);
	switch(indice_lista){
		case 1:
			tam=8;
			imprimir(lista1,tam);
			heapSort(lista1, tam);
			imprimir(lista1,tam);
			break;
		case 2:
			tam=5;
			imprimir(lista2,tam);
			heapSort(lista2, tam);
			imprimir(lista2,tam);
			break;
		case 3:
			tam=7;
			imprimir(lista3,tam);
			heapSort(lista3, tam);
			imprimir(lista3,tam);
			break;
		case 4:
			tam=7;
			imprimir(lista4,tam);
			heapSort(lista4, tam);
			imprimir(lista4,tam);
			break;
		case 5:
			tam=5;
			imprimir(lista5,tam);
			heapSort(lista5, tam);
			imprimir(lista5,tam);
			break;
		case 6:
			tam=5;
			imprimir(lista6,tam);
			heapSort(lista6, tam);
			imprimir(lista6,tam);
			break;
		case 7:
			tam=10;
			imprimir(lista7,tam);
			heapSort(lista7, tam);
			imprimir(lista7,tam);
			break;
		case 8:
			tam=10;
			imprimir(lista8,tam);
			heapSort(lista8, tam);
			imprimir(lista8,tam);
			break;
		case 9:
			tam=10;
			imprimir(lista9,tam);
			heapSort(lista9, tam);
			imprimir(lista9,tam);
			break;
		default:
			printf("\nERRO, INFORME APENAS NÚMEROS DE 1 A 9");
			break;
	
}
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
void imprimir(int array[], int tam){
		printf("\n");
		int x=0;
		while(x<tam){
			printf("\t%i",array[x]);
			x++;
		}
	}

