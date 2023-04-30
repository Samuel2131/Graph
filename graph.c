#include "graph.h"

graph* newGraph(){
    graph* newIstanceOfGraph = (graph*) malloc(sizeof(graph));
    newIstanceOfGraph->numVertices = 0;
    newIstanceOfGraph->adjlist = newList();
    newIstanceOfGraph->adjMatrix = NULL;
    return newIstanceOfGraph;
}

bool** createMatrix(unsigned int size){
    bool** newMatrix;
    newMatrix = (bool**) malloc(size * sizeof(bool*));
    for(unsigned int i=0;i<size;i++) *(newMatrix+i) = (bool*) malloc(size * sizeof(bool));
    return newMatrix;
}

bool isEmpty(graph* g){
    if(g->numVertices == 0){
        printf("\nGraph is empty...\n");
        return true;
    }
    return false;
}

unsigned int getMaxNode(graph* g){
    unsigned int max = 0;
    listNode* current = g->adjlist->head;
    while(current != NULL){
        if(strlen(current->value) > max) max = strlen(current->value);
        current = current->next;
    }
    return max;
}

void printGraph(graph* g){
    if(g == NULL) return;
    if(isEmpty(g)) return;

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
    if(isEmpty(g)) return;

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
    if(g == NULL) return;
    if(isEmpty(g)) return;

    if(g->adjMatrix != NULL){
        printf("\n");
        for(unsigned int i=0;i<g->numVertices;i++) printf("%s%s ", (i==0 ? "    " : " "),getNodeByIndex(g->adjlist, i)->value);
        for(unsigned int i=0;i<g->numVertices;i++){
            printf("\n");
            for(unsigned int j=0;j<g->numVertices;j++){
                if(j == 0) printf(" %s ", getNodeByIndex(g->adjlist, i)->value);
                printf(" %d ", g->adjMatrix[i][j]);
            }
        }
    }
}

void printAdjMatrixWithoutVertex(graph* g){
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
        bool** newMatrix = createMatrix(g->numVertices);
        if(newMatrix == NULL) return false;
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

bool isConnected(graph* g, char* node1, char* node2){
    if(g == NULL) return false;
    listNode* n1 = getNode(g->adjlist, node1);
    listNode* n2 = getNode(g->adjlist, node2);
    if(n1 == NULL || n2 == NULL) return false;
    return g->adjMatrix[n1->index][n2->index];
}

bool updateGraphNode(graph* g, char* oldValue, char* newValue){
    if(g == NULL) return false;
    listNode* node = getNode(g->adjlist, oldValue);
    if(node == NULL || isIn(g->adjlist, newValue)) return false;

    for(unsigned int i=0;i<g->numVertices;i++){
        if(g->adjMatrix[i][node->index]) getNode(getNodeByIndex(g->adjlist, i)->adjL, oldValue)->value = newValue;
    }
    return updateNode(g->adjlist, oldValue, newValue);
}

bool deleteGraphNode(graph* g, char* value){
    if(g == NULL) return false;
    listNode* node = getNode(g->adjlist, value);
    if(node == NULL) return false;

    unsigned int index = node->index;
    for(unsigned int i=0;i<g->numVertices;i++){
        if(g->adjMatrix[i][index]) deleteNode(getNodeByIndex(g->adjlist, i)->adjL, value);
    }

    bool** newMatrix = createMatrix(g->numVertices-1);
    unsigned int x = 0, y = 0;
    for(unsigned int i=0;i<g->numVertices;i++){
        if(i == index) continue;
        for(unsigned int j=0;j<g->numVertices;j++) {
            if(j != index) newMatrix[x][y] = g->adjMatrix[i][j];
            else continue;
            y++;
        }
        y = 0;
        x++;
    }
    g->adjMatrix = newMatrix;

    if(deleteNode(g->adjlist, value)){
        g->numVertices--;
        return true;
    }
    else return false;
}

bool clearGraph(graph* g){
    if(g == NULL) return false;

    listNode* current = g->adjlist->last;
    while(current != NULL){
        listNode* temp = current;
        current = current->prev;
        free(temp);
    }
    free(g->adjlist);
    free(g->adjMatrix);
    g->adjlist = newList();
    g->adjMatrix = NULL;
    g->numVertices = 0;

    return true;
}

void deallocGraph(graph* g){
    if(g == NULL) return;
    clearGraph(g);
    free(g->adjlist);
    free(g);
}

