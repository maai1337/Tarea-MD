#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 20

typedef struct {
    int numVertices;
    char vertices[MAX_VERTICES];
    int matrizAdyacencia[MAX_VERTICES][MAX_VERTICES];
} Grafo;

void inicializarGrafo(Grafo* g, int numVertices);
void agregarArista(Grafo* g, char v1, char v2, int dirigido);
int indiceVertice(Grafo* g, char v);
void leerGrafo(Grafo* g, const char* nombreArchivo, int dirigido);

#endif