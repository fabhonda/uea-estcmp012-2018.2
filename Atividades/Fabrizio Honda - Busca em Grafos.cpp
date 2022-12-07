//Fabrizio Honda - Algoritmo e Estrutura de Dados II
//Grafo não direcionado, Lista de Adjacência e Busca em largura

#include <iostream>
#include <locale>
using namespace std;


typedef struct aux{
	int vertice;
	aux* proximo;
}ELEMENTO;

typedef struct{
	ELEMENTO *inicio;
	ELEMENTO *fim;
}FILA;

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
void buscaLargura(GRAFO* gr);

void inicializaFila(FILA* f);
int tamanho (FILA* f);
void reinicializar(FILA* f);
ELEMENTO returnVertice(FILA*p);
bool inserirVertice(FILA* f, int vert);

void bfs_vist(GRAFO* gr, int no, bool v[]);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int vi,vf,peso;
	
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

//Criando uma aresta (grafo direcionado)
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
	naoDirecionado(gr,vf,vi,p); 
	return(true);
}

//Cria uma aresta (grafo não direcionado)
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

//Imprime o grafo
void imprime(GRAFO* gr){
	cout << "Vertices: " << gr->vertices << ". Arestas: " << gr->arestas << endl;
	for(int i=0; i<gr->vertices; i++){
		cout << "v" << i << ": ";
		ADJACENCIA* ad = gr->vert[i].cad;
		while(ad){
			cout << "v" << ad->vertice << "(" << ad->peso << ")" << " ";
			ad = ad->prox;
		}
		cout << endl;
	}	
}

//Busca em largura
void bfs_vist(GRAFO* gr, int no, bool v[]){
	FILA f;
	int v_atual;
	inicializaFila(&f);
	inserirVertice(&f,no);
	v[no] = true;
	cout << "No " << no << " visistado" << endl;
	while(tamanho(&f) !=0){
		v_atual=returnVertice(&f).vertice;
		ADJACENCIA* ad=gr->vert[v_atual].cad;
		while(ad){
			if(v[ad->vertice]==false){
				v[ad->vertice]=true;
				cout << "No " << ad->vertice << " visitado" << endl;
				inserirVertice(&f,ad->vertice);
			}
			ad = ad->prox;
		}
	}
}

//Inicializa a Fila
void inicializaFila(FILA* f){
	f->fim = NULL;
	f->inicio = NULL;
}

//Retorna o tamanho da Fila
int tamanho(FILA* f){
	ELEMENTO atual;
	int tam=0;

  if (filaVazia(f) == 1){
    cout << "Fila VAZIA !!"<< endl;
  } else{
    while ((f->inicio) != NULL){
      atual = (f->inicio);
      tam++;
      (f->inicio) = (f->inicio->proximo);
      free(atual);
    }
  }
  return tam;
}

//Exclui a Fila atual e a reinicializa
void reinicializar(FILA* f){
	ELEMENTO atual;

  if (filaVazia(f) == 1){
    cout << "Fila vazia!!";
  } else {
    atual = (f->inicio);
    if ((f->inicio) == (f->fim)){
      (f->inicio) = NULL;
      (f->fim) = NULL;
    } else{
      (f->inicio) = (f->inicio->proximo);
    }
    free(atual);
  }
}

//Retorna o vértice
ELEMENTO returnVertice(FILA* p){
	return p->inicio->vertice;
}

//Insere um vértice
bool inserirVertice(FILA* f, int vert){
	ELEMENTO atual=NULL;

  if (filaVazia(f) == 1){
    f->inicio = vert;
    f->fim = vert;	
    return true;
  } else{
	f->fim->proximo = vert;
    f->fim = vert;
    return false;
  }
}

int filaVazia(FILA* f){
  if (f->inicio == NULL){
    return 1;
  }else{
    return 0;
  }
}
