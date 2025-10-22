#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#define INF 999

typedef struct {
    int distancia;
    bool visto;
    int padre;
} Vertice;

void dijkstra(int num_vertices, int** matriz_adyacencia, int inicio, int final);
void imprimir_camino(int num_vertices, Vertice vertices[], int final);

#endif