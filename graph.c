#include "graph.h"

graph* newGraph(){
    graph* newIstanceOfGraph = (graph*) malloc(sizeof(graph));
    newIstanceOfGraph->numVertices = 0;
    newIstanceOfGraph->adjlist = newList();
    return newIstanceOfGraph;
}

void printGraph(graph* g){
    if(g == NULL) return;

    printf("\nNum graph vertices : %u", g->numVertices);
    listNode* current = g->adjlist->head;
    while(current != NULL){
        printf("\nVertex : ");
        printItem(current);
        if(current->adjL != NULL){
            printf("\n\tConnected vertices : \n");
            printList(current->adjL);
        }
        else printf("\n\tNo vertex connected...\n");
        current = current->next;
    }
}

void printValueGraph(graph* g){
    if(g == NULL) return;

    listNode* current = g->adjlist->head;
    unsigned int index = 1;
    printf("\nValues of graph vertices : \n\t");
    while(current != NULL){
        printf("%u : %s, ", index, current->value);
        index++;
        current = current->next;
    }
    printf("\n");
}

unsigned int graphSize(graph* g){
    return g->numVertices;
}

bool addVertex(graph* g, char* value) {
    if(addNode(g->adjlist, value)){
        g->numVertices++;
        return true;
    }
    else return false;
}

//bool addArch();


