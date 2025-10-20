#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

int indiceVertice(Grafo* g, char v) {
    int i;
    for (i = 0; i < (*g).numVertices; i++)
        if ((*g).vertices[i] == v) return i;
    return -1;
}

void inicializarGrafo(Grafo* g, int numVertices) {
    int i, j;
    (*g).numVertices = numVertices;
    for (i = 0; i < numVertices; i++)
        for (j = 0; j < numVertices; j++)
            (*g).matrizAdyacencia[i][j] = 0;
}

void agregarArista(Grafo* g, char v1, char v2, int dirigido) {
    int i = indiceVertice(g, v1);
    int j = indiceVertice(g, v2);

    if (i == -1 || j == -1) {
        printf("Error: vértice no encontrado (%c-%c)\n", v1, v2);
        return;
    }

    (*g).matrizAdyacencia[i][j] = 1;
    if (!dirigido)
        (*g).matrizAdyacencia[j][i] = 1;
}