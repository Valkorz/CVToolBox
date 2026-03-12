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

typedef Node* CLList;

void CreateCLL(CLList* va_list);

#endif