#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

/* Determines which hashing method to use.
 * LINEAR_P means Linear Probing
 * DOUBLE_H means Double Hashing
 * */

/* A struct containing data for the htable */
typedef struct graphrec *graph;

extern graph graph_new(int vertices);
extern void graph_add_edge(graph g, int v1, int v2);
extern void graph_bfs(graph g);
extern void graph_print(graph g);
extern void graph_free(graph g);


#endif
