#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct listNode{
    unsigned int index;
    char* value;
    struct listNode* next;
    struct listNode* prev;
    //struct adjList* adjL;
}listNode;

typedef struct adjList{
    struct listNode* head;
    struct listNode* last;
    unsigned int len;
}adjList;

extern adjList* newList();
extern void printList(adjList* l);
extern unsigned int lenght(adjList* l);
extern bool add(adjList* l, char* value);
extern listNode* getNode(adjList* l, char* value);
extern listNode* getNodeByIndex(adjList* l, unsigned int index);
extern bool updateNode(adjList* l, char* value, char* newValue);
extern bool deleteNode(adjList* l, char* value);

#endif
