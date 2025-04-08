#include "collections.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue* queue_new(size_t data_size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (void**)malloc(sizeof(void*) * QUEUE_DEFAULT_LENGTH);
    queue->length = QUEUE_DEFAULT_LENGTH;
    queue->data_size = data_size;

    //set all values to null
    int i;
    for(i = 0; i < QUEUE_DEFAULT_LENGTH; i++){
        *(queue->items + i) = NULL;
    }

    return queue;
}

/// @brief Copies the memory of an item to the queue
/// @param queue the queue
/// @param item memory address of the value to be pushed
void queue_push(Queue* queue, void* item){
    printf("\n adding item: %p (%d)...", item, *((int*)item));
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        if(*(queue->items + i) == NULL){
            printf("\n memory updated (%p) > ", *(queue->items + i));
            *(queue->items + i) = malloc(queue->data_size);
            memcpy(*(queue->items + i), item, queue->data_size);
            printf("(%p) value = %d", *(queue->items + i), *((int*)*(queue->items + i)));
            return;
        }
    }

    queue->items = (Queue*)realloc(queue->items, sizeof(void*) * QUEUE_DEFAULT_LENGTH + QUEUE_DEFAULT_LENGTH);
    *(queue->items + i + 1) = item;
    queue->length += QUEUE_DEFAULT_LENGTH;
}

void* queue_pop(Queue* queue){
    void* item = malloc(queue->data_size), *next = malloc(queue->data_size);
    int len = queue->length, i;
    memcpy(item, *(queue->items), queue->data_size);
    // printf("\n allocated poppable memory: %p", item);

    if(item == NULL){
        return NULL;
    }


    for(i = 0; i < len; i++){
        if((i + 1) >= len){
            free(*(queue->items + len - 1));
            *(queue->items + len - 1) = NULL;
        }

        next = *(queue->items + i + 1);
        if(next == NULL){
            break;
        }

        free(*(queue->items + i));
        *(queue->items + i) = malloc(queue->data_size);
        memcpy(*(queue->items + i), next, queue->data_size);
        // printf("\n Copied for %d: %p", i, *(queue->items + i));
    }

    printf("Got value: %d", *((int*)item));


    free(next);

    return item;
}

void queue_print(Queue* queue){
    printf("\n Printing the queue %p \n", queue);
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        printf("%p > ", *(queue->items + i));
    }
}

void queue_free(Queue* queue){
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        free(*(queue->items + i));
    }
    free(queue->items);
    free(queue);
}