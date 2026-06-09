#ifndef CCLIST_H
#define CCLIST_H
#include <stdio.h>
#include <stdlib.h>
/*
    |||| CIRCULAR LINKED LIST
*/

typedef struct Node{
    void* value;
    struct Node* _prev;
    struct Node* _next;
}Node;

typedef struct CLList{
    Node* entries;
    int l_size;
}CLList;

void createCLL(CLList* va_list, unsigned int l_size);
void printCLL(CLList list);
int addEntry(CLList va_list, void* val);

#endif