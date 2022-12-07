#include <iostream>
#define TAM 5

using namespace std;

void AddAresta(int vector[TAM][TAM], int v1, int v2){
	vector[v1][v2] = 1;
	vector[v2][v1] = 1;
}

void imprimir(int vector[TAM][TAM]){
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			cout << vector[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int vector[TAM][TAM];
	
	for(int i=0; i<TAM; i++){
		for(int j=0; j<TAM; j++){
			vector[i][j] = 0;
		}	
	}
	
	AddAresta(vector, 1, 2);
	AddAresta(vector, 2, 3);
	AddAresta(vector, 4, 0);
	AddAresta(vector, 0, 2);
	
	imprimir(vector);
	
	return 0;
}
