#ifndef LLIST_H
#define LLIST_H
#include <stdlib.h>
#include <stdio.h>

/*
    |||| LINKED LIST |||

*/
typedef struct Node{
    void *data;
    struct Node *next;
} Node;

// Holds root node
typedef struct LinkedList{
    Node *head;
} LinkedList;

Node* createNode(void* data);
void linkNode(LinkedList* targetList, void* data);
void* getData(LinkedList* targetList, int index);
void clear(LinkedList* LinkedList);

#endif