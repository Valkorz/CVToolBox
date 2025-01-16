#include "llist.h"
#include "tmatch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    THIS CODE IS OLD AND *NEEDS* TO BE REWRITTEN. SYNTAX IS BAD AND USES
    INCORRECT POINTER TYPE CONVERSION (WHICH CAN LEAD TO DATA LOSS).
    still works tho
*/

//Use this to initialize the head node in the Linked List
Node* createNode(void* data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Link a node to a LinkedList, if it already has a non-null head Node.
void linkNode(LinkedList* targetList, void* data){
    Node* targetNode = NULL;
    Node* currentNode = targetList->head;
    Node* nextNode = NULL;
    Node* newNode = NULL;

    //Visit every node until the last
    printf("\n Looking at node list...");
    while(currentNode != NULL){      
        printf("\n Current node: %p", currentNode);
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
    printf("\n Set next node %p to target node: %d", newNode, targetNode);
}

//Search the LinkedList for data in a specified index
void* getData(LinkedList* targetList, int index){
    int currentIndex = 0;
    Node* currentNode = targetList->head;
    Node* nextNode = NULL;

    //Visit every node until the last
    printf("\n Looking at node list...");
    while(currentNode != NULL){
        printf("\n Current index: %d", currentIndex);

        nextNode = currentNode->next;
        if(currentIndex == index)
            return currentNode->data;
        else currentNode = nextNode;

        currentIndex++;
    }
}

//Clear entire LinkedList and the reserved memory
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