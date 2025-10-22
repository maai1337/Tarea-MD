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
char indice_a_letra(int indice);
int seleccionarMinimo(Vertice vertices[], int num_vertices);
bool hayNoVisitado(Vertice vertices[], int num_vertices);
void inicializar_vertice(Vertice *v);

#endif