#include <iostream>
#include <locale>
using namespace std;

int tipo_grafo;



typedef struct pilha {
	int elemento;
	pilha *prox=NULL;
}PILHA;

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
void deep(GRAFO* gr, int no, bool v[], PILHA *p);
void stack_push(PILHA **inicio, int elemento);
void stack_print(PILHA **inicio);
int stack_size(PILHA **inicio);
PILHA* stack_pop(PILHA **inicio);



int main(){
	setlocale(LC_ALL,"Portuguese");
	int vi,vf,peso;	
	PILHA* p=NULL;
	
	GRAFO* gr = criaGrafo(5);
	bool v[5];
	
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
	
	deep(gr, 0, v, p);
	
	cout << "\n";

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
		naoDirecionado(gr,vf,vi,p);   
	return(true);
}

//Imprime o grafo
void imprime(GRAFO* gr){
	char cities[5] = {'S','T','Y','X','Z'};
	cout << "Vertices: " << gr->vertices << ". Arestas: " << gr->arestas << endl;
	for(int i=0; i<gr->vertices; i++){
		cout << cities[i] << ": ";
		ADJACENCIA* ad = gr->vert[i].cad;
		while(ad){
			cout << cities[ad->vertice] << "(" << ad->peso << ")" << " ";
			ad = ad->prox;
		}
		cout << endl;
	}	
	cout << "\n";
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


//Busca em Profundidade
void deep(GRAFO* gr, int no, bool v[], PILHA *p){
	char cities[5] = {'S','T','Y','X','Z'};
	int v_atual;
	int abj[gr->vertices];
	
	stack_push(&p, no);
	v[no] = true;
	
	cout << "Cidade " << cities[no] << " visitada" << endl;
	
	while(stack_size(&p) != 0){
		v_atual = stack_pop(&p)->elemento;
		ADJACENCIA* ad=gr->vert[v_atual].cad;
		
		while(ad){
			if(v[ad->vertice] == false){
				v[ad->vertice] = true;
				cout << "Cidade " << cities[ad->vertice] << " visitada" << endl;
				stack_push(&p, ad->vertice);
			}
			ad = ad->prox;
		}
	}
}

//Insere um elemento no topo da pilha
void stack_push(PILHA **inicio, int elemento){
	
	PILHA* novo = new (PILHA);
	novo->elemento = elemento;
	novo->prox = NULL;
	
	if((*inicio)==NULL){
		(*inicio) = novo;
		return;
	}
	
	novo->prox = (*inicio);
	(*inicio) = novo;
}

//Imprime a pilha
void stack_print(PILHA **inicio){
	PILHA* atual = (*inicio);
	PILHA* anterior = (*inicio);
	cout << endl;
	while(atual != NULL){
		cout << atual->elemento << " ";
		anterior = atual;
		atual=atual->prox;
	}
}

//Retorna o tamanho da pilha
int stack_size(PILHA **inicio){
	PILHA* atual = (*inicio);
	PILHA* anterior = (*inicio);
	int cont=0;
	while(atual != NULL){
		cont++;
		anterior = atual;
		atual=atual->prox;
	}
	return cont;
}

//Retira um elemento do topo da pilha
PILHA* stack_pop(PILHA **inicio){
	PILHA *elemento=(*inicio), *aux;
	
	aux = (*inicio);
	(*inicio) = (*inicio)->prox;
	aux->prox = NULL;
	
	return elemento;
}
