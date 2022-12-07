#include <iostream>
#include <locale>
using namespace std;

int tipo_grafo;

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

GRAFO* criaGrafo(int v);
ADJACENCIA *criaAdj(int v, int peso);
bool criaAresta(GRAFO* gr, int vi, int vf, int p);
void imprime(GRAFO* gr);
bool naoDirecionado(GRAFO* gr, int vi, int vf, int p);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int vi,vf,peso;	
	
	GRAFO* gr = criaGrafo(5);
	
	do{
		cout << "--------Qual o tipo de grafo?-------- \n0-DIRECIONADO\n1-NÃO DIRECIONADO\n";
		cin >> tipo_grafo;
	}while(tipo_grafo!=0 && tipo_grafo!=1);
	
	cout << "\n";
	

	criaAresta(gr,0,1,10);
	criaAresta(gr,0,2,5);
	criaAresta(gr,1,2,2);
	criaAresta(gr,1,3,1);
	criaAresta(gr,2,1,3);
	criaAresta(gr,2,3,9);
	criaAresta(gr,2,4,2);
	criaAresta(gr,3,4,4);
	criaAresta(gr,4,0,7);
	criaAresta(gr,4,3,6);


	imprime(gr);

	return 0;	
}

//Criando um grafo
GRAFO* criaGrafo(int v){
	GRAFO* g = new(GRAFO);
	g->vertices = v;
	g->arestas = 0;
	g->vert = new VERTICE[v];
	for(int i=0; i<v; i++)
		g->vert[i].cad = NULL;
	return g;
}

//Iniciando aresta no grafo (criação de adjacência)
ADJACENCIA *criaAdj(int v, int peso){
	ADJACENCIA* temp = new(ADJACENCIA);
	temp->vertice = v;
	temp->peso = peso;
	temp->prox = NULL;
	return (temp);
}

//Criando uma aresta
bool criaAresta(GRAFO* gr, int vi, int vf, int p){
	if(!gr) return (false);
	if ((vf<0) || (vf>= gr->vertices))
		return (false);
	if ((vi<0) || (vi>= gr->vertices))
		return (false);
	ADJACENCIA* novo = criaAdj(vf,p);
	novo->prox = gr->vert[vi].cad;
	gr->vert[vi].cad = novo;
	gr->arestas++;
	if(tipo_grafo == 1)
		naoDirecionado(gr,vf,vi,p);   //Comentar para se tornar um grafo Direcionado
	return(true);
}

//Imprime o grafo
void imprime(GRAFO* gr){
	char cities[5] = {'S','T','Y','X','Z'};
	cout << "Vertices: " << gr->vertices << ". Arestas: " << gr->arestas << endl;
	for(int i=0; i<gr->vertices; i++){
		//cout << "v" << i << ": ";
		cout << cities[i] << ": ";
		ADJACENCIA* ad = gr->vert[i].cad;
		while(ad){
			//cout << "v" << ad->vertice << "(" << ad->peso << ")" << " ";
			cout << cities[ad->vertice] << "(" << ad->peso << ")" << " ";
			ad = ad->prox;
		}
		cout << endl;
	}	
}

//Para fazer Grafo não direcionado
bool naoDirecionado(GRAFO* gr, int vi, int vf, int p){
	if(!gr) return (false);
	if ((vf<0) || (vf>= gr->vertices))
		return (false);
	if ((vi<0) || (vi>= gr->vertices))
		return (false);
	ADJACENCIA* novo = criaAdj(vf,p);
	novo->prox = gr->vert[vi].cad;
	gr->vert[vi].cad = novo;
	gr->arestas++;
	return(true);
}
