#include "graph.h"

int main() {
    graph* g = newGraph();
    printf("\nAddress graph : %p", g);

    printGraph(g);

    addVertex(g, "A");
    printGraph(g);

    addVertex(g, "B");
    addVertex(g, "C");
    addVertex(g, "D");
    addVertex(g, "E");
    addVertex(g, "F");
    addVertex(g, "G");
    printGraph(g);

    printValueGraph(g);
    printf("\nNum vertices : %u", graphSize(g));
    printf("\nAdd arch result : %d", addArch(g, "A", "B", 2));
    printf("\nAdd arch result : %d", addArch(g, "A", "C", 8));
    printf("\nAdd arch result : %d", addArch(g, "B", "E", 5));
    printf("\nAdd arch result : %d", addArch(g, "B", "D", 2));
    printf("\nAdd arch result : %d", addArch(g, "A", "G", 16));
    printf("\nAdd arch result : %d", addArch(g, "F", "G", 2));
    printf("\nAdd arch result : %d", addArch(g, "D", "C", 2));
    printf("\nAdd arch result : %d", addArch(g, "D", "F", 7));
    printf("\nAdd arch result : %d", addArch(g, "C", "F", 5));
    printf("\nAdd arch result : %d", addArch(g, "E", "G", 8));
    printf("\nAdd arch result : %d", addArch(g, "B", "G", 20));

    addVertex(g, "I");

    printGraph(g);

    printf("\nNumero di archi collegati ad D = %d", getNumArch(g, "D"));

    printAdjMatrix(g);
    printf("\n");

    printValueGraph(g);

    printf("\nCost to arrive to G node = %lf", calculateRouteCost(g, "G"));

    addVertex(g, "E");
    printf("\nAdd arch result : %d", addArch(g, "E", "D", 0));
    printf("\nAdd arch result : %d", addArch(g, "C", "E", 10));
    printGraph(g);
    printAdjMatrix(g);

    if(isConnected(g, "C", "E")) printf("\nYes\n");
    else printf("\nNo\n");

    printf("\nDelete arch : %d", deleteArch(g, "A", "C"));
    printf("\nDelete arch : %d", deleteArch(g, "B", "D"));
    printGraph(g);
    printAdjMatrix(g);

    printf("\nUpdate graph node : %d", updateGraphNode(g, "C", "C++"));
    printGraph(g);
    printAdjMatrix(g);
    printValueGraph(g);

    printf("\nDelete graph node : %d", deleteGraphNode(g, "A"));
    printf("\nDelete graph node : %d", deleteGraphNode(g, "B"));
    printGraph(g);
    printAdjMatrixWithoutVertex(g);
    printValueGraph(g);
    /*
    printf("\nClear graph : %d", clearGraph(g));
    printGraph(g);
    printAdjMatrix(g);
    printValueGraph(g);

    */

    printf("\nCost to arrive to G node = %lf", calculateRouteCost(g, "G"));

    printf("\nBefore : %u", g->numVertices);
    deallocGraph(g);
    printf("\nAfter : %u", g->numVertices);

    char** arr;
    arr = (char**) malloc(sizeof(char*) * 10);

    for(int i=0;i<10;i++){
        *(arr+i) = (char*) calloc(1, sizeof(char));
        *(*(arr+i)) = (65+i);
    }

    graph* g1 = newGraph();
    printGraph(g1);

    fillGraph(g1, arr, 10);
    printGraph(g1);

    return 0;
}
