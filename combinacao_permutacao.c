#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void combinatoria(int vetor[], int pos);
void combinatoria_sem(int vetor[], int valor);
void permutacao(int *a, int inicio, int fim);
void imprime_vetor(int *array);

int n, r;

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int vetor[] = {1,2,3,3};
	permutacao(vetor,0,3);
	return 0;
}


void combinatoria(int vetor[], int pos){
	//total++;
	int i;
	for(i=1;i<=n;i++){
		vetor[pos] = i;
		if(pos==(r-1)){
			imprime_vetor(vetor);
		}
		else{
			combinatoria(vetor,pos+1);
		}
	}
}

void combinatoria_sem(int vetor[], int valor){
	//total++;
	int i;
	for(i=valor;i<=n;i++){
		vetor[pos] = i;
		if(pos==(r-1)){
			imprime_vetor(vetor);
		}
		else{
			combinatoria(vetor,pos+1,i);
		}
	}
}

void permutacao(int *a, int inicio, int fim){
	int i;
	if(inicio==fim){
		imprime_vetor(a);
	}
	else{
		for(i=inicio;i<=fim;i++){
			trocar(&a[inicio],&a[i]);
			permutacao(a,inicio+1,fim);
			trocar(&a[inicio],&a[i]);
		}
	}
	
}

void imprime_vetor(int *array){
	int i;
	for(i=0;i<sizeof(array)/4;i++){
		printf("\n %d", array[i]);
	}
}
