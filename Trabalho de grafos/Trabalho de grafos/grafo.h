typedef struct adjacencia {
    int vertice;
    struct adjacencia* prox;
}ADJ;

typedef struct vertice {

    ADJ* cab;
}VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE* adj;
}GRAFO;

GRAFO* criaGrafo(int vert);
ADJ* criaAdj(int vert);
int criaAresta(GRAFO* gr, int vert, int vert_ligado);
void imprime_grafo(GRAFO* gr);
void remove_aresta(GRAFO* g, int v1, int v2);
