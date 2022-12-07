#include <stdio.h>

typedef struct adjacencia{
	int vertice;
	int peso;
	struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice{
	ADJACENCIA *cad;
}VERTICE;

typedef struct grafo{
	int vertices;
	int arestas;
	VERTICE *vert;
}GRAFO;


int main(){
	GRAFO* gr = criaGrafo(5);
	criaAresta(gr,0,1,20);
	criaAresta(gr,1,2,40);
	criaAresta(gr,2,0,12);
	criaAresta(gr,2,4,40);
	criaAresta(gr,3,1,30);
	criaAresta(gr,4,3,80);
	imprime(gr);
	
	return 0;
}

//Número fixo de vértices
GRAFO* criaGrafo(int v){
	GRAFO* g = new(GRAFO);
	g->vertices=v;
	g->arestas=0;
	int i;
	g->vert = new VERTICE[v];
	for(i=0;i<v;i++)
		g->vert[i].cad = NULL;
	return g;
}

//Criação de adjacência
ADJACENCIA* criaAdj(int v, int peso){
	ADJACENCIA* temp = new(ADJACENCIA);
	temp->vertice = v;
	temp->peso = peso;
	temp->prox = NULL;
	return(temp);
}

//Criação da aresta
bool criaAresta(GRAFO* gr, int vi, int vf, TIPOPESO p){
	if(!gr){
		return (false);
	}
	if((vf<0) || (vf >= gr->vertices)){
		return (false);
	}
	if((vi<0) || (vi >= gr->vertices)){
		return (false);
	}
	ADJACENCIA* novo = criaAdj(vf,p);
	novo->prox = gr->vert[vi].cad;
	gr->vert[vi].cad = novo;
	gr->arestas++;
	return (true);
}

//Imprime o grafo
void imprime(GRAFO* gr){
	printf("Vertices: %i. Arestas: %i",gr->vertices,gr->arestas);
	int i;
	for(i=0;i<gr->vertices;i++){
		printf("%i:",i);
		ADJACENCIA* ad = gr->vert[i].cad;
		while(ad){
			printf("v%i(%i)",ad->vertice,ad->peso);
			ad = ad->prox;
		}
		printf("\n");
	}
}
