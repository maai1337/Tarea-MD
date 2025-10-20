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