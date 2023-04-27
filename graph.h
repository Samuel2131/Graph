#include "list.h"

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

//Todo: delete graph and all node graph, djikstra, add better view for adjMatrix;
typedef struct graph{
    unsigned int numVertices;
    struct adjList* adjlist;
    bool** adjMatrix;
}graph;

extern graph* newGraph();
extern void printGraph(graph* g);
extern void printValueGraph(graph* g);
extern void printAdjMatrix(graph* g);
extern unsigned int graphSize(graph* g);
extern bool addVertex(graph* g, char* value);
extern bool addArch(graph* g, char* value1, char* value2);
extern int getNumArch(graph* g, char* value);
extern bool isConnected(graph* g, char* node1, char* node2);
extern bool updateGraphNode(graph* g, char* oldValue, char* newValue);
extern bool deleteGraphNode(graph* g, char* value);

#endif