#include "grafo_matriz.h"
#include <stdio.h>
#include <stdlib.h>

// Cria grafo vazio com n vértices

grafo cria_grafo(int n) {
    grafo G = malloc(sizeof(struct t_grafo));
    G->n = n;
    G->matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        G->matriz[i] = calloc(n, sizeof(int));
    }
    return G;
}

void destroi_grafo(grafo G) {
    for (int i = 0; i < G->n; i++)
        free(G->matriz[i]);
    free(G->matriz);
    free(G);
}

void adiciona_vertice(int id, grafo G) {
    // Não faz nada, só para compatibilidade
}

void remove_vertice(int id, grafo G) {
    // Não implementado
}

void adiciona_aresta(int id, int u_id, int v_id, grafo G) {
    G->matriz[u_id-1][v_id-1] = 1;
    G->matriz[v_id-1][u_id-1] = 1;
}

void remove_aresta(int id, grafo G) {
    // Não implementado
}

int grau(vertice v, grafo G) {
    int d = 0;
    for (int j = 0; j < G->n; j++)
        if (G->matriz[v-1][j]) d++;
    return d;
}

void imprime_grafo(grafo G) {
    printf("\nMatriz de adjacência:\n");
    for (int i = 0; i < G->n; i++) {
        for (int j = 0; j < G->n; j++)
            printf("%d ", G->matriz[i][j]);
        printf("\n");
    }
}

void imprime_vertice(vertice v, grafo G) {
    printf("%d - [%d]( ", v, grau(v, G));
    for (int j = 0; j < G->n; j++)
        if (G->matriz[v-1][j])
            printf("{%d,%d} ", v, j+1);
    printf(")");
}

void imprime_aresta(aresta e) {
    printf("{%d,%d}", e.u, e.v);
}
