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
        printf("\n\tPrev node: %p\n", ln->prev);
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

bool addNode(adjList* l, char* value){
    if(l == NULL || isIn(l, value)) return false;
    listNode* newNode = (listNode*) malloc(sizeof(listNode));
    if(newNode == NULL) return false;

    newNode->adjL = NULL;
    newNode->value = value;
    newNode->next = NULL;
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

    return true;
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

bool deleteNode(adjList* l, char* value) {
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
            free(current);
            return true;
        }
        current = current->next;
    }
    return false;
}
