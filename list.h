#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct dijkstraInfo{
    struct listNode* prevStep;
    double potential;
}dijkstraInfo;

typedef struct listNode{
    unsigned int index;
    char* value;
    struct listNode* next;
    struct listNode* prev;
    struct adjList* adjL;
    struct arch* arch;
    struct dijkstraInfo* dI;
}listNode;

typedef struct arch{
    listNode* startingNode;
    unsigned int weight;
}arch;

typedef struct adjList{
    struct listNode* head;
    struct listNode* last;
    unsigned int len;
}adjList;

extern adjList* newList();
extern void printItem(listNode* ln);
extern void printList(adjList* l);
extern void printAdjList(adjList* l);
extern unsigned int lenght(adjList* l);
extern bool setArch(adjList* l, char* value, listNode* n, unsigned int weight);
extern bool addNode(adjList* l, listNode* ln);
extern listNode* addNewNode(adjList* l, char* value);
extern listNode* getNode(adjList* l, char* value);
extern listNode* getNodeByIndex(adjList* l, unsigned int index);
extern bool isIn(adjList* l, char* value);
extern bool updateNode(adjList* l, char* value, char* newValue);
extern listNode* shift(adjList* l);
extern bool deleteNode(adjList* l, char* value, bool freeNode);
extern adjList* copyList(adjList* l);
extern void switchMin(adjList* l1, adjList* l2);
extern void deallocList(adjList* l);

#endif
