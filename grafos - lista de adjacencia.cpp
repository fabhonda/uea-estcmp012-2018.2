#include <iostream>
#define TAM 5

using namespace std;

struct Adjacencia{
	int vertice;
	struct Adjacencia *prox;
};

struct Vertice{
	Adjacencia *adj;
};

struct Grafo{
	int arestas;
	int vertices;
	
	Vertice *cad;	
};

Grafo* CriaGrafo(int v){
	Grafo *gr = new(Grafo);
	
	gr->vertices = v;
	gr->arestas = 0;
	
	gr->cad = new(Vertice[v]);
	
	for(int i=0; i<TAM; i++){
		gr->cad[i].adj = NULL;
	}
	
	return gr;
}

void AddAresta(Grafo *g, int v1, int v2){
	Adjacencia *adj = new (Adjacencia);
	adj->vertice = v2;
	adj->prox = g->cad[v1].adj;
	g->cad[v1].adj = adj;
	
	Adjacencia *adj2 = new (Adjacencia);
	adj2->vertice = v1;
	adj2->prox = g->cad[v2].adj;
	g->cad[v2].adj = adj2;
	
}

void imprimir(Grafo *g){
	for(int i=0; i<TAM; i++){
		
		cout << "\nVertice " << i << ": ";
		
		Adjacencia *andar = g->cad[i].adj;
		
		while(andar){
			cout << andar->vertice << " ";
			andar = andar->prox;
		}
		
	}
}

int main(){
	Grafo *g = CriaGrafo(TAM);
	
	AddAresta(g, 1,2);
	AddAresta(g, 3,4);
	AddAresta(g, 4,2);
	AddAresta(g, 1,3);
	
	imprimir(g);
	return 0;
}
