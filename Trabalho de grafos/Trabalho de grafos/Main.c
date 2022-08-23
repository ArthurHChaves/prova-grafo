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
	int* Sociabilidade; // vetor da sociabilidade dos herois
	int numherois, i, j, media_Socie; //numero max de herois, i/j, int para a media da sociabilidade dos herois

	printf("Quantos herois serao cadastrados?\n"); 
	scanf("%d", &numherois); // informa quantos herois serão cadastrados
	
	// aloca dinamicamente os herois
	grafo = criaGrafo(numherois);

	herois = (char**)malloc(numherois * sizeof(char*));
	Sociabilidade = (int*)malloc(numherois * sizeof(int));
	
	//cadastra os herois
	for (i = 0; i < numherois; i++) {
		herois[i] = (char*)malloc(Tamho_string * sizeof(char)); // aloca a segunda parte da matriz para cada posição inicial
		printf("Nome do heroi\n");
		getchar();
		fgets(herois[i], Tamho_string, stdin); // pega o nome do heroi
		
		printf("Sociabilidade do  heroi(0 até 10): ");
		scanf("%d", &Sociabilidade[i]); // pega a sociabilidade do heroi
		
	}
	
	// for para percorrer os vetores
	for (i = 0; i < numherois; i++) {
		for (j = 0; j < numherois; j++) {
			media_Socie = (Sociabilidade[i] + Sociabilidade[j]) / 2; // faz a media da sociabilidade do heroi 'i' com todos os outros
			if (media_Socie > 5) {
				criaAresta(grafo, i, j); // cria uma adj para caso a sociabilidade entre os herois 'i' e 'j' seja maior que 5
			}
		}
	}

	imprime_grafo_com_nome(grafo, herois); // chama a funçaimprime o grafo


	return SUCESS;
}
