#include "graph.h"

int main() {
    /*
    adjList* l = newList();
    printList(l);
    printf("%d\n", add(l, "New item"));
    printf("%d\n", add(l, "Second item"));
    printf("%d\n", add(l, "Third item"));
    printf("%d\n", add(l, "Last item"));
    printList(l);
    printf("\nList len = %d", lenght(l));

    listNode* ln = getNode(l, "LasT iTeM");
    if(ln != NULL) printf("\nNode by value = %s", ln->value);
    else printf("\nNode by value not found...");

    listNode* ln2 = getNodeByIndex(l, 10);
    if(ln2 != NULL) printf("\nNode by index = %s", ln2->value);
    else printf("\nNode by index not found...");

    printf("\nRemove : %d", deleteNode(l, "last item"));
    printf("\nLength : %u", lenght(l));
    printList(l);

    printf("\nUpdate : %d", updateNode(l, "third item", "last item"));
    printList(l);

    printf("\nLength a : %u", lenght(l));
    printf("\n%d\n", add(l, "second item"));
    printf("\nLength a : %u", lenght(l));
    */

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
    printf("\nDelete graph node : %d", deleteGraphNode(g, "C++"));
    printf("\nDelete graph node : %d", deleteGraphNode(g, "D"));
    printf("\nDelete graph node : %d", deleteGraphNode(g, "E"));
    printGraph(g);
    printAdjMatrix(g);
    printValueGraph(g);

    return 0;
}
