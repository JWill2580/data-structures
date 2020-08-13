/* graph-test.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "graph.h"

int main(void) {
    int u = 0, v = 0;
    int vertices = 0;
    graph g;

    scanf("%d", &vertices);
    g = graph_new(vertices);

    while(2 == scanf("%d%d", &u, & v)){
        graph_add_edge(g, u, v);
    }

    graph_bfs(g);
    graph_print(g);
    graph_free(g);

    return EXIT_SUCCESS;
}
