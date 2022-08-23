#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

#define SUCESS (0)
#define Tamho_string (100+1)//define o tamanho maximo para a strig


//função para imprimir grafo com nome
void imprime_grafo_com_nome(GRAFO* gr, char** h) {

	printf("\nNumero de vertices: %d.\nNum de arestas: %d. \n", gr->vertices, gr->arestas); // informa o numero de vertices e arestas
	int i;

	for (i = 0; i < gr->vertices; i++) {
		printf("\nGrupo do heroi %s", h[i]); // printa o nome do heroi
		ADJ* adj = gr->adj[i].cab;
		while (adj) {
			printf("-%s", h[adj->vertice]);// printa seus companheiros/amizades
			adj = adj->prox;

		}
		printf("\n");
	}
}

int main() {

	GRAFO* grafo;

	char** herois; // matriz de herois
	int* força, *inteligencia, *agi, *vigor, *media; // vetores dos atributos dos herois
	int numherois, i, j, media_Total; //numero max de herois, i/j, int para a media da sociabilidade dos herois

	printf("Quantos herois serao cadastrados?\n"); 
	scanf("%d", &numherois); // informa quantos herois serão cadastrados
	
	// aloca dinamicamente os herois
	grafo = criaGrafo(numherois)
	herois = (char**)malloc(numherois * sizeof(char*));
	media = (int*)malloc(numherois * sizeof(int));
	vigor = (int*)malloc(numherois * sizeof(int));
	agi = (int*)malloc(numherois * sizeof(int));
	inteligencia = (int*)malloc(numherois * sizeof(int));
	força = (int*)malloc(numherois * sizeof(int));
	
	//cadastra os herois
	for (i = 0; i < numherois; i++) {
		herois[i] = (char*)malloc(Tamho_string * sizeof(char)); // aloca a segunda parte da matriz para cada posição inicial
		printf("Nome do heroi\n");
		getchar();
		fgets(herois[i], Tamho_string, stdin); // pega o nome do heroi
		
		printf("força, inteligencia, agilidade, vigor do  heroi respectivamente (0 até 9):\n");
		scanf("%d %d %d %d", &força[i], &inteligencia[i], &agi[i], &vigor[i]); // cadastra os atrib dos herois
		media[i] = força[i] + inteligencia[i] + agi[i] + vigor[i]; // cria uma media para o heroi 'i'
		
	}
	
	// for para percorrer os vetores
	for (i = 0; i < numherois; i++) {
		for (j = 0; j < numherois; j++) {
			media_Total = (media[i] + media[j]) / 2;
			if (media_Total >= 25) {
				criaAresta(grafo, i, j); // cria uma adj para caso a sociabilidade entre os herois 'i' e 'j' seja maior que 25
			}
		}
	}

	imprime_grafo_com_nome(grafo, herois); // chama a funçao imprime o grafo

	for (i = 0; i < grafo->arestas; i++) { // libera as arestas do grafo
		for (j = 0; j < grafo->arestas; j++) {
			remove_aresta(grafo, i, j);
		}
	}

	free(grafo); // libera o grafo
	return SUCESS;
}
