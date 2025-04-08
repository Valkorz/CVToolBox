#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#define QUEUE_DEFAULT_LENGTH 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This header defines diferent data structures
typedef struct Queue{
    void** items;
    unsigned int length;
    size_t data_size;
}Queue;

typedef void(*QueueSorter)(Queue* queue);

Queue* queue_new(size_t data_size);
void queue_push(Queue* queue, void* item);
void* queue_pop(Queue* queue);
void queue_free(Queue* queue);
void queue_sort(Queue* queue, QueueSorter q_sorter);
void queue_print(Queue* queue);


#endif