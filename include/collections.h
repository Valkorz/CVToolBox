#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#define QUEUE_DEFAULT_LENGTH 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//QUEUES
typedef void(*QueueSorter)(Queue** queue);

typedef struct Queue{
    void** items;
    unsigned int length;
    size_t data_size;
    QueueSorter sort;
}Queue;

Queue* queue_new(size_t data_size);
void queue_push(Queue* queue, void* item);
void* queue_pop(Queue* queue);
void queue_remove(Queue* queue);
void queue_free(Queue* queue);
void queue_print(Queue* queue);
void queue_clear(Queue* queue);
void queue_sortByDescending(Queue** queue);
void queue_sortByAscending(Queue** queue);
Queue* queue_clone(Queue* src);


#endif