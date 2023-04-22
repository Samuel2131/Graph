#include "list.h"

//Todo: Control duplicates, remove, update...;
adjList* newList(){
    adjList* newIstanceOfList = (adjList*) malloc(sizeof(adjList));
    newIstanceOfList->head = NULL;
    newIstanceOfList->last = NULL;
    newIstanceOfList->len = 0;
    return newIstanceOfList;
}

char* toLowerStr(char* str, int len) {
    char* lowerStr = (char*) malloc(sizeof(char) * len);
    for(int i=0;i<len;i++) *(lowerStr+i) = tolower((*(str+i)));
    return lowerStr;
}

void printItem(listNode* ln){
    if(ln == NULL) printf("\nNULL\n");
    else {
        printf("\nValue node: %s", ln->value);
        printf("\nIndex node: %u", ln->index);
        printf("\nThis node: %p", ln);
        printf("\nNext node: %p", ln->next);
        printf("\nPrev node: %p\n", ln->prev);
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
    if(l == NULL) return 0;
    unsigned int len = 0;
    listNode* current = l->head;
    while(current != NULL){
        len++;
        current = current->next;
    }
    return len;
}

bool add(adjList* l, char* value){
    if(l == NULL) return false;
    listNode* newNode = (listNode*) malloc(sizeof(listNode));
    if(newNode == NULL) return false;

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
        if(!strcmp(toLowerStr(value, strlen(value)), toLowerStr(current->value, strlen(value)))) return current;
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
