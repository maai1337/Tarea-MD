#include <stdio.h>
#include "graph.h"
#include <stdlib.h>
#include <string.h>
#include "dijkstra.c"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("error\n");
    }

    Grafo g;
    leerGrafo(&g, argv[1], atoi(argv[2]));
}