/*******************************************
 * Leitura e impressao de grafos (matriz).
 *******************************************/
#include "grafo_matriz.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    grafo G = cria_grafo(n);
    for (int i = 1; i <= n; ++i)
        adiciona_vertice(i, G);
    int id = 1;
    int u, v;
    scanf("%d %d", &u, &v);
    while (u && v) {
        adiciona_aresta(id, u, v, G);
        ++id;
        scanf("%d %d", &u, &v);
    }
    imprime_grafo(G);
    destroi_grafo(G);
    return 0;
}
