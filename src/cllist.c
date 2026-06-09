#include "cllist.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/// @brief Creates a new CLList instance
/// @param va_list reference to CLList
/// @param l_size maximum size
void createCLL(CLList* va_list, unsigned int l_size){
    va_list->entries = NULL;
    
    va_list->entries = (Node*)malloc(sizeof(Node) * l_size);
    va_list->l_size = l_size;

    //Initialize elements
    for(int i = 0; i < l_size; i++){
        Node* curr_node = va_list->entries;
        curr_node->_next = curr_node + 1;
        
        if(i == 0)
            curr_node->_prev = curr_node + (l_size - 1);
        else 
            curr_node->_prev = curr_node - 1;

        curr_node->value = NULL;
    }    
}

/// @brief Prints every item in the list to the console
void printCLL(CLList list){
    printf("-- CIRCULAR LINKED LIST --\n\n");
    for(int i = 0;i < list.l_size; i++){
        printf("%d: %p\r\n", i, list.entries + i);
    }
}

int addEntry(CLList va_list, void* val)
{
    if(va_list.entries == NULL)
        return -1;

    Node* null_node = va_list.entries;
    for(int i = 0; i < va_list.l_size; i++){
        if(null_node->value == NULL){
            null_node->value = val;
            break;
        }
        else{
            null_node = null_node->_next;
        }
    }
    return 0;
}