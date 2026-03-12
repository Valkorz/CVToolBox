#include "collections.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

/*
###################################
QUEUES
################################### 
*/

Queue* queue_new(size_t data_size){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (Link*)malloc(sizeof(Link) * QUEUE_DEFAULT_LENGTH);
    queue->length = QUEUE_DEFAULT_LENGTH;
    queue->data_size = data_size;

    if(queue == NULL || queue->items == NULL){
        free(queue->items);
        free(queue);
        return NULL;
    }

    // set all values to null
    int i;
    for(i = 0; i < QUEUE_DEFAULT_LENGTH; i++){
        (queue->items + i)->value == NULL;
    }

    return queue;
}

/// @brief Copies the memory of an item to the queue
/// @param queue the queue
/// @param item memory address of the value to be pushed
void queue_push(Queue* queue, Link* item){
    printf("\n adding item: %p (%d)...", item, *((int*)item));
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        if((queue->items + i)->value == NULL){
            printf("\n memory updated (%p) > ", (queue->items + i)->value);
            (queue->items + i)->value = (Link*)malloc(sizeof(Link) * queue->data_size);
            memcpy((queue->items + i)->value, item, queue->data_size);
            printf("(%p) value = %d", (queue->items + i)->value, *((int*)(queue->items + i)->value));
            return;
        }
    }

    queue->items = (Queue*)realloc(queue->items, sizeof(Link) * QUEUE_DEFAULT_LENGTH + QUEUE_DEFAULT_LENGTH);
    (queue->items + i + 1)->value = item;
    queue->length += QUEUE_DEFAULT_LENGTH;
}

Link* queue_pop(Queue* queue){
    Link* item = (Link*)malloc(queue->data_size), *next = malloc(queue->data_size);
    int len = queue->length, i;
    memcpy(item, (queue->items)->value, queue->data_size);
    // printf("\n allocated poppable memory: %p", item);

    if(item == NULL){
        return NULL;
    }


    for(i = 0; i < len; i++){
        if((i + 1) >= len){
            free((queue->items + len - 1)->value);
            (queue->items + len - 1)->value = NULL;
        }

        next = (queue->items + i + 1);
        if(next == NULL){
            break;
        }

        free((queue->items + i)->value);
        (queue->items + i)->value = malloc(queue->data_size);
        memcpy((queue->items + i)->value, next, queue->data_size);
        // printf("\n Copied for %d: %p", i, (queue->items + i)->value);
    }

    printf("Got value: %d", *((int*)item));


    free(next);

    return item;
}

void queue_print(Queue* queue){
    printf("\n Printing the queue %p \n", queue);
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        printf("%p > ", (queue->items + i)->value);
    }
}

void queue_free(Queue* queue){
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        free((queue->items + i)->value);
    }
    free(queue->items);
    free(queue);
}

void queue_clear(Queue* queue){
    int len = queue->length, i;
    for(i = 0; i < len; i++){
        free((queue->items + i)->value);
        (queue->items + i)->value = NULL;
    }
}

void queue_sortByAscending(Queue** queue, char* nameof_identifier){
    int len = (*queue)->length, i,c;
    int int_s_value = 30000; //variable to store smallest value
    Link* void_s_value = NULL;
    Queue* newQueue = queue_new((*queue)->data_size);

    //unfinished
    for(i = 0; i < len; i++){
        void_s_value = NULL;
        for(c = 0; c < len; c++){
            Link* current_value = ((*queue)->items + c);
            if(*((int*)current_value) < int_s_value){
                void_s_value = current_value;
                printf("\n Current smallest value: %p (%d)", void_s_value, *((int*)void_s_value));
            }
        }
        queue_push(newQueue, void_s_value);

    }
}

Queue* queue_clone(Queue* src){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (Link*)malloc(sizeof(Link) * src->length);
    queue->length = src->length;
    queue->data_size = src->data_size; 

    if(queue == NULL || queue->items == NULL){
        free(queue->items);
        free(queue);
        return NULL;
    }

    int i;
    for(i = 0; i < queue->length; i++){
        (queue->items + i)->value = malloc(queue->data_size);
        memcpy((queue->items + i)->value, (src->items + i), src->data_size);
        printf("\n (%d) copied from src (%p) to target (%p): %p > %p", i, queue, src, (queue->items + i)->value, *(src->items + i));
    }

    return queue;
}