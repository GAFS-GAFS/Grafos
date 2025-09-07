#ifndef _GRAFO_MATRIZ_
#define _GRAFO_MATRIZ_

#include <stdio.h>
#include <stdlib.h>

// Estruturas para grafo com matriz de adjacência

typedef struct t_grafo {
    int n;           // número de vértices
    int **matriz;    // matriz de adjacência
} *grafo;

typedef int vertice;
typedef struct {
    int u, v;
    int peso;
} aresta;

// Funções

grafo cria_grafo(int n);
void destroi_grafo(grafo G);
void adiciona_vertice(int id, grafo G); // não faz nada, só para compatibilidade
void remove_vertice(int id, grafo G);   // não implementado
void adiciona_aresta(int id, int u_id, int v_id, grafo G);
void remove_aresta(int id, grafo G);    // não implementado
int grau(vertice v, grafo G);
void imprime_grafo(grafo G);
void imprime_vertice(vertice v, grafo G);
void imprime_aresta(aresta e);

#endif
