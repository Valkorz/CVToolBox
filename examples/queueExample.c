#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    Queue* queue = newQueue();
    enqueue(queue, "bananas");
    enqueue(queue, "apples");
    enqueue(queue, "oranges");
    enqueue(queue, "tomatos");
    printQueue(queue);

    system("pause");
    system("cls");

    printf("\n Dequeueing...");
    printf("\n result: %s", dequeue(queue));
    printf("\n new Queue: ");
    printQueue(queue);
    printf("\n result: %s", dequeue(queue));
    printf("\n new Queue: ");
    printQueue(queue);
    printf("\n result: %s", dequeue(queue));
    printf("\n new Queue: ");
    printQueue(queue);
    printf("\n result: %s", dequeue(queue));
    printf("\n new Queue: ");
    printQueue(queue);
    printf("\n result: %s", dequeue(queue));
    printf("\n new Queue: ");
    printQueue(queue);

    system("pause");
    free(queue);

    return EXIT_SUCCESS;
}