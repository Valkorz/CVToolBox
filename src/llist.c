#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* createNode(void* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void linkNode(LinkedList* targetList, void* data){
    Node* targetNode = NULL;
    Node* currentNode = targetList->head;
    Node* nextNode = NULL;
    Node* newNode = NULL;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        if(nextNode == NULL){
            targetNode = currentNode;
            break;
        } else{
            currentNode = nextNode;
        }
    }

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    targetNode->next = newNode;
}

void* getData(LinkedList* targetList, int index){
    int currentIndex = 0;
    Node* currentNode = targetList->head;
    Node* nextNode = NULL;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        if(currentIndex == index)
            return currentNode->data;
        else
            currentNode = nextNode;

        currentIndex++;
    }

    return NULL;
}

void clear(LinkedList* linkedList){
    Node* currentNode = linkedList->head;
    Node* nextNode;

    while(currentNode != NULL){
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    linkedList->head = NULL;
}
