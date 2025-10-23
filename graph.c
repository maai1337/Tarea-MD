#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"


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

void leerGrafo(Grafo* g, const char* nombreArchivo, int dirigido) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        exit(1);
    }

    char linea[256];

    if (fgets(linea, sizeof(linea), archivo) == NULL) {
        printf("Archivo vacío\n");
        exit(1);
    }

    int contador = 0;
    char* token = strtok(linea, " \n");
    while (token != NULL && contador < MAX_VERTICES) {
        (*g).vertices[contador] = token[0];
        contador++;
        token = strtok(NULL, " \n");
    }

    inicializarGrafo(g, contador);

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
    char* token = strtok(linea, " \n");
    while (token != NULL) {
        if (strlen(token) >= 2) {
            char v1 = token[0];
            char v2 = token[1];
            agregarArista(g, v1, v2, dirigido);
        }
        token = strtok(NULL, " \n");
    }
}
    fclose(archivo);
}