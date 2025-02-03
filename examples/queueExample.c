#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
    This is an example on how to use the queue.h to create a FIFO (First In First Out) structure;
*/

int main(){
    printf("-- QUEUE EXAMPLE -- \n \n");
    Queue* queue = newQueue();
    char in[100];
    printf("\n Created new queue...");
    system("pause");
    
    printf("\n Enqueue input, send '#' to STOP...");

    while(1){
        scanf("%s", in);
        if(*in == '#') break;

        enqueue(queue, in);
    }

    printf("\n Finished enqueue process...");
    system("pause");
    system("cls");

    printf("\n Result: ");
    printQueue(queue);

    system("pause");    
    system("cls");

    printf("\n First element: %s", dequeue(queue));
    printf("\n Second element: %s", dequeue(queue));

    printf("\n Proceed to free queue...");
    system("pause");
    system("cls");

    freeQueue(queue);

    return EXIT_SUCCESS;
}