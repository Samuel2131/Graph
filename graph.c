#include "graph.h"

graph* newGraph(){
    graph* newIstanceOfGraph = (graph*) malloc(sizeof(graph));
    newIstanceOfGraph->numVertices = 0;
    newIstanceOfGraph->adjlist = newList();
    newIstanceOfGraph->adjMatrix = NULL;
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
            printf("\n\tConnected vertices : ");
            printAdjList(current->adjL);
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

void printAdjMatrix(graph* g){
    if(g->adjMatrix != NULL){
        for(unsigned int i=0;i<g->numVertices;i++){
            printf("\n");
            for(unsigned int j=0;j<g->numVertices;j++) printf(" %d ", g->adjMatrix[i][j]);
        }
    }
}

void setMatrix(bool** oldMatrix, bool** newMatrix, unsigned int numVertex){
    for(unsigned int i=0;i<numVertex-1;i++){
        for(unsigned int j=0;j<numVertex-1;j++) newMatrix[i][j] = oldMatrix[i][j];
    }
    for(unsigned int i=0;i<numVertex;i++) newMatrix[i][numVertex-1] = 0;
    for(unsigned int j=0;j<numVertex;j++) newMatrix[numVertex-1][j] = 0;
}

bool addVertex(graph* g, char* value) {
    if(addNewNode(g->adjlist, value)){
        g->numVertices++;
        bool** newMatrix;
        newMatrix = (bool**) malloc(g->numVertices * sizeof(bool*));
        for(unsigned int i=0;i<g->numVertices;i++) *(newMatrix+i) = (bool*) malloc(g->numVertices * sizeof(bool));

        setMatrix(g->adjMatrix, newMatrix, g->numVertices);

        if(g->adjMatrix != NULL) free(g->adjMatrix);
        g->adjMatrix = newMatrix;
        return true;
    }
    else return false;
}

bool addArch(graph* g, char* value1, char* value2){
    if(g == NULL || (!isIn(g->adjlist, value1)) || (!isIn(g->adjlist, value2))) return false;
    listNode* nodeValue1 = getNode(g->adjlist, value1);
    if(nodeValue1->adjL == NULL) nodeValue1->adjL = newList();
    if(isIn(nodeValue1->adjL, value2)) return false;

    if(addNewNode(nodeValue1->adjL, value2)){
        g->adjMatrix[nodeValue1->index][getNode(g->adjlist, value2)->index] = 1;
        return true;
    }
    else return false;
}

int getNumArch(graph* g, char* value){
    if(g == NULL) return -1;

    listNode* node = getNode(g->adjlist, value);
    if(node == NULL) return -1;
    else {
        return node->adjL->len;
    }
}


