#include <stdio.h>
#include <stdlib.h>

// Definições de tipos
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

// Estruturas de dados para o grafo
typedef struct adjacencia {
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

// Função para criar um grafo
GRAFO *criaGrafo(int v) {
    int i;

    GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *)malloc(v * sizeof(VERTICE));

    for (i = 0; i < v; i++) {
        g->adj[i].cab = NULL;
    }
    return g;
}

// Função para criar uma adjacência
ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}

// Função para criar uma aresta
bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p) {
    vi--;
    vf--;
    if (!gr)
        return false;
    if ((vf < 0) || (vf >= gr->vertices))
        return false;
    if ((vi < 0) || (vf >= gr->vertices))
        return false;

    ADJACENCIA *novo = criaAdj(vf, p);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab = novo;
    gr->arestas++;
    return true;
}

// Função para imprimir a lista de adjacência do grafo
void imprimeLista (GRAFO *gr){
	
	printf("Vertices: %d. Arestas: %d. \n", gr->vertices, gr->arestas); 
	int i;
	for (i=0; i<gr->vertices; i++){
		printf("v%d: ",i+1);
		ADJACENCIA *ad = gr->adj[i].cab; 
			while(ad){ 
				printf("v%d (%d) ", ad->vertice+1, ad->peso); 
				ad = ad->prox; 
			}
		printf("\n");
	}
}

// Função para imprimir a matriz do grafo
void imprimeMatriz(GRAFO *gr) {
    int i, j;
    printf("Matriz do Grafo:\n");

    for (i = 0; i < gr->vertices; i++) {
        for (j = 0; j < gr->vertices; j++) {
            ADJACENCIA *ad = gr->adj[i].cab;
            bool adjacente = false;

            while (ad) {
                if (ad->vertice == j) {
                    printf("%d ", ad->peso);
                    adjacente = true;
                    break;
                }
                ad = ad->prox;
            }

            if (!adjacente) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Função para imprimir o valor total do caminho de {1, 5}
void imprimeValorCaminho(GRAFO *gr) {
	int valorTotal = 0;
	ADJACENCIA *ad = gr->adj[0].cab; 
    
    
    while(ad){ 
    	if(ad->vertice == 2)
		{
			valorTotal += ad->peso;
			ad = gr->adj[2].cab; 
			break;
		} 
		ad = ad->prox; 
	}
	
	while(ad){ 
    	if(ad->vertice == 3)
		{
			valorTotal += ad->peso;
			ad = gr->adj[3].cab; 
			break;
		} 
		ad = ad->prox; 
	}
	
	while(ad){ 
    	if(ad->vertice == 4)
		{
			valorTotal += ad->peso;
			ad = gr->adj[4].cab; 
			break;
		} 
		ad = ad->prox; 
	}
	printf("O valor total do caminho de {1, 5} eh: %d\n", valorTotal);

}

int main() {
    GRAFO *grafo = criaGrafo(5);
    criaAresta(grafo, 1, 1, 1);
    criaAresta(grafo, 1, 3, 1);
    
    criaAresta(grafo, 2, 3, 1);
	criaAresta(grafo, 2, 4, 1);
    criaAresta(grafo, 2, 5, 1);
    
    

    criaAresta(grafo, 3, 1, 1);
    criaAresta(grafo, 3, 2, 1);
    criaAresta(grafo, 3, 4, 1);
    
    criaAresta(grafo, 4, 2, 1);
	criaAresta(grafo, 4, 3, 1);
    criaAresta(grafo, 4, 5, 1);
    
	criaAresta(grafo, 5, 2, 1);
    criaAresta(grafo, 5, 4, 1);
   

	imprimeLista(grafo);
	printf("\n");
    imprimeMatriz(grafo);
   	printf("\n");
	printf("---------------\nGrafo 2:\n");
	
	GRAFO *grafo2 = criaGrafo(5);
    criaAresta(grafo2, 1, 1, 5);
    criaAresta(grafo2, 1, 3, 4);
    
    criaAresta(grafo2, 2, 3, 2);
	criaAresta(grafo2, 2, 4, 3);
    criaAresta(grafo2, 2, 5, 7);

    criaAresta(grafo2, 3, 1, 4);
    criaAresta(grafo2, 3, 2, 2);
    criaAresta(grafo2, 3, 4, 5);
    
    criaAresta(grafo2, 4, 2, 3);
	criaAresta(grafo2, 4, 3, 5);
    criaAresta(grafo2, 4, 5, 4);
    
	criaAresta(grafo2, 5, 2, 7);
    criaAresta(grafo2, 5, 4, 4);
    
    imprimeLista(grafo2);
	printf("\n");
    imprimeMatriz(grafo2);
    printf("\n");
	imprimeValorCaminho(grafo2);
    return 0;
}
