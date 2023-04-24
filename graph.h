#include "list.h"

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
//Todo: add arch, matrixAdj, djikstra;
typedef struct graph{
    unsigned int numVertices;
    struct adjList* adjlist;
}graph;

extern graph* newGraph();
extern void printGraph(graph* g);
extern void printValueGraph(graph* g);
extern unsigned int graphSize(graph* g);
extern bool addVertex(graph* g, char* value);
//extern bool addArch();

#endif
