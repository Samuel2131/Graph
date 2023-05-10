#include "list.h"

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

//Todo: djikstra;
typedef struct graph{
    unsigned int numVertices;
    struct adjList* adjlist;
    bool** adjMatrix;
}graph;

extern graph* newGraph();
extern void printGraph(graph* g);
extern void printValueGraph(graph* g);
extern void printAdjMatrix(graph* g);
extern void printAdjMatrixWithoutVertex(graph* g);
extern unsigned int graphSize(graph* g);
extern bool addVertex(graph* g, char* value);
extern bool fillGraph(graph* g, char** arrStr, unsigned int numVertex);
extern bool addArch(graph* g, char* value1, char* value2, unsigned int weight);
extern int getNumArch(graph* g, char* value);
extern bool isConnected(graph* g, char* node1, char* node2);
extern bool updateGraphNode(graph* g, char* oldValue, char* newValue);
extern bool deleteGraphNode(graph* g, char* vertex);
extern bool deleteArch(graph* g, char* vertex1, char* vertex2);
extern bool clearGraph(graph* g);
extern void deallocGraph(graph* g);
extern void bestRoute(graph* g, char* startVertex, char* endVertex);

#endif
