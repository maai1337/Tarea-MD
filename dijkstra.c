#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define INF 999

char indice_a_letra(int indice);

typedef struct {
    int distancia;
    bool visto;
    int padre;
} Vertice;

void inicializar_vertice(Vertice *v) {
    v->distancia = INF;
    v->visto = false;
    v->padre = -1;
}

bool hayNoVisitado(Vertice vertices[], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (!vertices[i].visto) {
            return true;
        }
    }
    return false;
}

int seleccionarMinimo(Vertice vertices[], int num_vertices) {
    int minDist = INF;
    int minIndex = -1;

    for (int i = 0; i < num_vertices; i++) {
        if (!vertices[i].visto && vertices[i].distancia < minDist) {
            minDist = vertices[i].distancia;
            minIndex = i;
        }
    }

    return minIndex;
}

void imprimir_camino(int num_vertices, Vertice vertices[num_vertices], int final) {
    int indice = final;

    if (vertices[indice].distancia == INF) {
        printf("La distancia entre los vertices ingresados es infinita.\n");
        return;
    }

    char camino[num_vertices];
    int contador = 0;

    while (indice != -1) {
        camino[contador] = indice_a_letra(indice);
        contador++;
        indice = vertices[indice].padre;
    }

    printf("El camino más corto es: ");

    for (int i = contador - 1; i >= 0; i--) {
        printf("%c", camino[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

char indice_a_letra(int indice) {
    return 'a' + indice;
}

void Dijkstra(Grafo* g, int inicio, int final) {
    Vertice vertices[(*g).numVertices];

    for (int i = 0; i < (*g).numVertices; i++) {
        inicializar_vertice(&vertices[i]);
    }

    vertices[inicio].distancia = 0;

    while (hayNoVisitado(vertices, (*g).numVertices)) {
        int min_index = seleccionarMinimo(vertices, (*g).numVertices);
        if (min_index == -1) { // Todos los nodos son inalcanzables
            break;
        }

        vertices[min_index].visto = true;

        for (int i = 0; i < (*g).numVertices; i++) {
            // Para todo vecino de u
            if (!vertices[i].visto && (*g).matrizAdyacencia[min_index][i] > 0) {
                int peso_uv = (*g).matrizAdyacencia[min_index][i];

                if (vertices[i].distancia > vertices[min_index].distancia + peso_uv) {
                    vertices[i].distancia = vertices[min_index].distancia + peso_uv;
                    vertices[i].padre = min_index;
                }
            }
        }
    }

    imprimir_camino((*g).numVertices, vertices, final);
}
