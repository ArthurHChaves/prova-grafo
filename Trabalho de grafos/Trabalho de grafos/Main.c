#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define SUCESS (0)
#define Tamho_string (100+1)

void imprime_grafo_com_nome(GRAFO* gr, char** h) {

	printf("\nNumero de vertices: %d.\nNum de arestas: %d. \n", gr->vertices, gr->arestas);
	int i;

	for (i = 0; i < gr->vertices; i++) {
		printf("\nGrupo do heroi %s", h[i]);
		ADJ* adj = gr->adj[i].cab;
		while (adj) {
			printf("-%s", h[adj->vertice]);
			adj = adj->prox;

		}
		printf("\n");
	}
}

int main() {

	GRAFO* grafo;

	char** herois;
	int* Sociabilidade;
	int numherois, i, j, media_Socie;

	printf("Quantos herois serao cadastrados?\n");
	scanf("%d", &numherois);

	grafo = criaGrafo(numherois);

	herois = (char**)malloc(numherois * sizeof(char*));
	Sociabilidade = (int*)malloc(numherois * sizeof(int));

	for (i = 0; i < numherois; i++) {
		herois[i] = (char*)malloc(Tamho_string * sizeof(char));
		printf("Nome do heroi\n");
		getchar();
		fgets(herois[i], Tamho_string, stdin);
		
		printf("Sociabilidade do  heroi(0 até 10): ");
		scanf("%d", &Sociabilidade[i]);
		
	}
	
	for (i = 0; i < numherois; i++) {
		for (j = 0; j < numherois; j++) {
			media_Socie = (Sociabilidade[i] + Sociabilidade[j]) / 2;
			if (media_Socie > 5) {
				criaAresta(grafo, i, j);
			}
		}
	}

	imprime_grafo_com_nome(grafo, herois);


	return SUCESS;
}