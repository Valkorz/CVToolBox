#include "queue.h"
#include "tmatch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allocates memory for a new Queue struct and its members.
Queue *newQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->length = 0;
    queue->items = (char **)malloc(sizeof(char *));

    *(queue->items) = NULL;

    return queue;
}

// Add item in the back of the queue
void enqueue(Queue *queue, char *item)
{
    // printf("\n Adding %s to queue.... length: %d", item, queue->length);
    queue->length++;

    //If the queue has no items, pass the item argument as the first element instead.
    if (queue->length - 1 == 0)
    {
        char **target = queue->items;
        *target = strdup(item);
        return;
    }

    queue->items = (char **)realloc(queue->items, sizeof(char *) * queue->length);

    //Access each item in the queue, and allocate them one index forward so that the first element is NULL.
    //After the first element is null, it can be allocated for the item argument.
    for (int i = queue->length - 1; i >= 1; i--)
    {
        char **currentItem = queue->items + i;
        char **previousItem = queue->items + i - 1;
        // printf("\n Found item: %p (%d) to be set to %s (%d)", currentItem, i, *previousItem, i - 1);
        *currentItem = NULL;
        *currentItem = strdup(*previousItem);
        *previousItem = NULL;
        // printf("\n current item is now: %s", *currentItem);
    }
    free(*(queue->items));
    // printf("\n queueitems: %p", *(queue->items));
    *(queue->items) = (char *)realloc(*(queue->items), sizeof(char) * strlen(item));
    // printf("\n queue items: %p", *(queue->items));
    *(queue->items) = strdup(item);
    // printf("\n queue items: %s", *(queue->items));
}

// Return the first item that entered the queue (FIFO)
// After the item is located, the queue's size in the memory is decreased and the element is deleted.
char *dequeue(Queue *queue)
{
    // printf("\n Dequeueing item from %p", queue);
    if (queue->length <= 0)
    {
        printf("\n Queue is empty.");
        return NULL;
    }

    // printf("\n First item: %s (%p)", *(queue->items), *(queue->items));
    char *last = (*(queue->items + (queue->length) - 1));
    // printf("\n Last item: %s (%p)", last, last);
    char *item = strdup(last);

    // printf("\n copied to item: %s (%p)", item, item);
    free(last);
    printf("\n Dequeued item: %s", item);

    queue->length--;
    queue->items = (char **)realloc(queue->items, sizeof(char *) * queue->length);
    return item;
}

// Shows all elements of the queue
void printQueue(Queue *queue)
{

    printf("Queue: \n");

    if (queue->length <= 0)
    {
        printf("empty.");
        return;
    }

    for (int i = 0; i < queue->length; i++)
    {
        printf(" %s (%p)", *(queue->items + i), *(queue->items + i));
        printf(" - ");
    }

    printf("\n");
}

//Frees all allocated memory used for the queue
void freeQueue(Queue *queue)
{
    for (int i = 0; i < queue->length; i++)
    {
        free(*(queue->items + i));
    }

    free(queue->items);
    free(queue);
}