#ifndef COLLECTIONS_H
#define COLLECTIONS_H
#define QUEUE_DEFAULT_LENGTH 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

/*
####################################
UTILS
####################################
*/

//Used to create links for storing sorting parameters for queues and other data structures.
//A "Link" has the address reference to a target object, and "LinkIdentifier"s for different 
//types of information about the value itself.
//
//A "LinkIdentifier" array is created, and each element contains data and a hash (for lookup).
//The user can create, for example, a link identifier with hash "serial_number", with an integer as data.
//This serial number can be used for sorting, if the sorting function requests the reading of all LinkIdentifiers
//hashed as "serial_number"
//
typedef struct Link{
    void* value;
    LinkIdentifier* identifier;
}Link;

typedef struct LinkIdentifier{
    void* data;
    char* hash;
}LinkIdentifier;

Link* create_link(void* value, int i_count, ...);
void destroy_link(Link* link);

/*
###################################
QUEUES
################################### 
*/

typedef struct Queue{
    Link* items;
    unsigned int length;
    size_t data_size;
}Queue;

Queue* queue_new(size_t data_size);
void queue_push(Queue* queue, Link* item);
Link* queue_pop(Queue* queue);
void queue_remove(Queue* queue);
void queue_free(Queue* queue);
void queue_print(Queue* queue);
void queue_clear(Queue* queue);
void queue_sortByDescending(Queue** queue, char* nameof_identifier);
void queue_sortByAscending(Queue** queue, char* nameof_identifier);
Queue* queue_clone(Queue* src);


#endif