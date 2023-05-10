#include "list.h"

adjList* newList(){
    adjList* newIstanceOfList = (adjList*) malloc(sizeof(adjList));
    newIstanceOfList->head = NULL;
    newIstanceOfList->last = NULL;
    newIstanceOfList->len = 0;
    return newIstanceOfList;
}

void printItem(listNode* ln){
    if(ln == NULL) printf("\nNULL\n");
    else {
        printf("\n\tValue node: %s", ln->value);
        printf("\n\tIndex node: %u", ln->index);
        printf("\n\tThis node: %p", ln);
        printf("\n\tNext node: %p", ln->next);
        printf("\n\tPrev node: %p", ln->prev);
        if(ln->dI != NULL){
            printf("\n\tPrev dijkstra step : %s", (ln->dI->prevStep != NULL) ? ln->dI->prevStep->value : "NULL");
            printf("\n\tPotential : %lf\n", ln->dI->potential);
        }
        else printf("\n");
    }
}

void printList(adjList* l){
    if(l == NULL) return;
    printf("\nList len = %u", l->len);
    listNode* current = l->head;
    while(current != NULL){
        printItem(current);
        current = current->next;
    }
}

void printAdjList(adjList* l) {
    if(l == NULL) return;
    listNode* current = l->head;
    while(current != NULL){
        printf(" %s(weight=%u), ", current->value, current->arch->weight);
        current = current->next;
    }
}

unsigned int lenght(adjList* l) {
    return l->len;
}

bool isIn(adjList* l, char* value) {
    listNode* current = l->head;
    while(current != NULL){
        if(!strcasecmp(current->value, value)) return true;
        current = current->next;
    }
    return false;
}

bool addNode(adjList* l, listNode* ln){
    if(l == NULL || isIn(l, ln->value)) return false;

    ln->prev = l->last;
    if(l->head == NULL) l->head = ln;
    if(l->last != NULL) l->last->next = ln;
    l->last = ln;
    l->len++;
    return true;
}

bool setArch(adjList* l, char* value, listNode* n, unsigned int weight){
    listNode* newNode = addNewNode(l, value);
    if(newNode == NULL) return false;

    arch* a = (arch*) malloc(sizeof(arch));
    if(a == NULL) return false;
    a->startingNode = n;
    a->weight = weight;
    newNode->arch = a;

    return true;
}

listNode* addNewNode(adjList* l, char* value){
    if(l == NULL || isIn(l, value)) return false;
    listNode* newNode = (listNode*) malloc(sizeof(listNode));
    if(newNode == NULL) return false;

    newNode->adjL = NULL;
    newNode->value = value;
    newNode->next = NULL;
    newNode->dI = NULL;
    if(l->head == NULL) {
        newNode->index = 0;
        l->head = newNode;
        newNode->prev = NULL;
    } else {
        newNode->index = l->last->index+1;
        l->last->next = newNode;
        newNode->prev = l->last;
    }
    l->last = newNode;
    l->len++;

    return newNode;
}

listNode* getNode(adjList* l, char* value) {
    if(l == NULL) return NULL;
    listNode* current = l->head;
    while(current != NULL){
        if(!strcasecmp(value, current->value)) return current;
        current = current->next;
    }
    return NULL;
}

listNode* getNodeByIndex(adjList* l, unsigned int index) {
    if(l == NULL) return NULL;
    if(index <= (l->len/2)){
        listNode* current = l->head;
        while(current != NULL){
            if(index == current->index) return current;
            current = current->next;
        }
    } else {
        listNode* current = l->last;
        while(current != NULL){
            if(index == current->index) return current;
            current = current->prev;
        }
    }
    return NULL;
}

bool updateNode(adjList* l, char* value, char* newValue){
    if(l == NULL) return false;

    listNode* current = l->head;
    while(current != NULL){
        if(!strcasecmp(current->value, value)){
            current->value = newValue;
            return true;
        }
        current = current->next;
    }
    return false;
}

void fixIndex(listNode* current) {
    while(current != NULL){
        current->index--;
        current = current->next;
    }
}

listNode* shift(adjList* l){
    if(l == NULL) return NULL;
    listNode* n = l->head;
    n->next->prev = NULL;
    l->head = n->next;
    n->next = NULL;
    l->len--;
    return n;
}

bool deleteNode(adjList* l, char* value, bool freeNode) {
    if(l == NULL) return false;

    listNode* current = l->head;
    while(current != NULL) {
        if(!strcasecmp(current->value, value)){
            if(current->prev != NULL) current->prev->next = current->next;
            else l->head = current->next;
            if(current->next != NULL) current->next->prev = current->prev;
            else l->last = current->prev;
            l->len--;
            fixIndex(current);
            if(freeNode) free(current);
            return true;
        }
        current = current->next;
    }
    return false;
}

adjList* copyList(adjList* l){
    if(l == NULL) return NULL;
    adjList* lCopy = newList();

    listNode* current = l->head;
    while(current != NULL){
        listNode* n = addNewNode(lCopy, current->value);
        n->dI = (dijkstraInfo*) malloc(sizeof(dijkstraInfo));
        n->dI->potential = INFINITY;
        n->dI->prevStep = NULL;
        n->adjL = current->adjL;
        current = current->next;
    }

    return lCopy;
}

char* getMinValue(adjList* l){
    listNode* current = l->head->next;
    double min = l->head->dI->potential;
    char* minValue = l->head->value;
    while(current != NULL){
        if(current->dI->potential < min) {
            min = current->dI->potential;
            minValue = current->value;
        }
        current = current->next;
    }
    return minValue;
}

void switchMin(adjList* l1, adjList* l2){
    listNode* n = getNode(l2, getMinValue(l2));
    deleteNode(l2, n->value, false);
    n->next = NULL;
    n->prev = NULL;
    addNode(l1, n);
}


