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
    printGraph(g);

    printValueGraph(g);
    printf("\nNum vertices : %u", graphSize(g));
    printf("\nAdd arch result : %d", addArch(g, "A", "B"));
    printf("\nAdd arch result : %d", addArch(g, "B", "C"));
    printf("\nAdd arch result : %d", addArch(g, "A", "C"));
    printf("\nAdd arch result : %d", addArch(g, "A", "A"));
    printf("\nAdd arch result : %d", addArch(g, "C", "A"));
    printf("\nAdd arch result : %d", addArch(g, "B", "D"));
    printf("\nAdd arch result : %d", addArch(g, "D", "B"));
    printGraph(g);

    printf("\nNumero di archi collegati ad D = %d", getNumArch(g, "D"));

    printAdjMatrix(g);
    printf("\n");

    addVertex(g, "E");
    printf("\nAdd arch result : %d", addArch(g, "E", "D"));
    printf("\nAdd arch result : %d", addArch(g, "C", "E"));
    printGraph(g);
    printAdjMatrix(g);

    if(isConnected(g, "C", "E")) printf("\nYes\n");
    else printf("\nNo\n");

    printf("\nUpdate graph node : %d", updateGraphNode(g, "C", "C++"));
    printGraph(g);
    printAdjMatrix(g);
    printValueGraph(g);

    printf("\nDelete graph node : %d", deleteGraphNode(g, "A"));
    printf("\nDelete graph node : %d", deleteGraphNode(g, "B"));
    printGraph(g);
    printAdjMatrixWithoutNodes(g);
    printValueGraph(g);
    /*
    printf("\nClear graph : %d", clearGraph(g));
    printGraph(g);
    printAdjMatrix(g);
    printValueGraph(g);
    */

    printf("\nBefore : %d", g->numVertices);
    deallocGraph(g);
    printf("\nAfter : %d", g->numVertices);
    return 0;
}
