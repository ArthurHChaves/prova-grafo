#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


#define true (1)
#define false (0)


GRAFO* criaGrafo(int vert) {
	int i;

	GRAFO* g = (GRAFO*)malloc(sizeof(GRAFO));
	g->vertices = vert;
	g->arestas = 0; 
	g->adj = (VERTICE*)malloc(vert * sizeof(VERTICE));

	for (i = 0; i < vert; i++) {
		g->adj[i].cab = NULL; 
	}
	return(g);
}

ADJ* criaAdj(int vert) {
	ADJ* adj = (ADJ*)malloc(sizeof(ADJ));
	adj->vertice = vert;
	adj->prox = NULL;
	return(adj);
}

int criaAresta(GRAFO* gr, int vert, int vert_ligado) {
	if (!gr) return (false); //valida se o grafo existe 

	if ((vert_ligado < 0) || (vert_ligado >= gr->vertices)) { //valida se o  vertice ao  qual vai se ligar existe
		return(false);
	}
	if ((vert < 0) || (vert_ligado >= gr->vertices)) { //ou se é maior que o numero de arestas
		return(false);
	}

	ADJ* novo = criaAdj(vert_ligado); //cria uma nova adjacencia no ultimo vertice ao qual se ligou

	novo->prox = gr->adj[vert].cab; //a nova adjacencia vai receber a cabeça(posição inicial, ou vertice) da lista 
	gr->adj[vert].cab = novo;
	gr->arestas++;
	return (true);
}

void imprime_grafo(GRAFO* gr) {

	printf("Numero de vertices: %d.\nNum de arestas: %d. \n", gr->vertices, gr->arestas);
	int i;

	for (i = 0; i < gr->vertices; i++) {
		printf("vertice %d: ", i);
		ADJ* adj = gr->adj[i].cab;
		while (adj) {
			printf("v%d,", adj->vertice);
			adj = adj->prox;
			
		}
		printf("\n");
	}
}

void libera_grafo_l(GRAFO* g) {
	int i;

	for (i = 0; i < g->vertices; i++) {
		ADJ* adj = g->adj[i].cab;
		while (adj) {
			free(adj);
			adj = adj->prox;

		}
		free(g);
	}
}