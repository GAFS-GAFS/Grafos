// Programa para construir o subgrafo induzido G[X] de um grafo não direcionado
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o número de vértices: ");
    scanf("%d", &n);

    // Aloca matriz de adjacência
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = calloc(n, sizeof(int));
    }

    // Lê as arestas
    printf("Digite as arestas (par de vértices, 0 0 para terminar):\n");
    int u, v;
    while (1) {
        scanf("%d %d", &u, &v);
        if (u == 0 && v == 0) break;
        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Vértices inválidos!\n");
            continue;
        }
        matriz[u-1][v-1] = 1;
        matriz[v-1][u-1] = 1;
    }

    // Lê o conjunto X
    int m;
    printf("Digite o número de vértices do conjunto X: ");
    scanf("%d", &m);
    int *X = malloc(n * sizeof(int));
    int *em_X = calloc(n, sizeof(int));
    printf("Digite os vértices de X (1 a %d): ", n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &X[i]);
        if (X[i] < 1 || X[i] > n) {
            printf("Vértice inválido!\n");
            i--;
            continue;
        }
        em_X[X[i]-1] = 1;
    }

    // Cria matriz do subgrafo induzido G[X]
    printf("\nMatriz de adjacência do subgrafo G[X]:\n");
    for (int i = 0; i < n; i++) {
        if (!em_X[i]) continue;
        for (int j = 0; j < n; j++) {
            if (!em_X[j]) continue;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera memória
    for (int i = 0; i < n; i++) free(matriz[i]);
    free(matriz);
    free(X);
    free(em_X);
    return 0;
}
