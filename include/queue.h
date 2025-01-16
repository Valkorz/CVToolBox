#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
    char **items;
    int length;
} Queue;

Queue* newQueue();
void enqueue(Queue* queue, char* item);
char *dequeue(Queue *queue);
void printQueue(Queue *queue);
void freeQueue(Queue* queue);

#endif