#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "dijkstra.h"

int letra_a_indice(char c) {
    return c - 'a';
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        printf("Uso: %s <inicio> <final> <archivo_grafo> <0=no dirigido,1=dirigido>\n", argv[0]);
        return 1;
    }

    char inicio_letra = argv[1][0];
    char final_letra = argv[2][0];
    char* archivo = argv[3];
    int dirigido = atoi(argv[4]);

    int inicio = letra_a_indice(inicio_letra);
    int final = letra_a_indice(final_letra);

    Grafo g;
    leerGrafo(&g, archivo, dirigido);

    Dijkstra(&g, inicio, final);

    return 0;
}