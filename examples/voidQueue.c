#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calclib.h"
#include "encode.h"
#include "collections.h"
#include <math.h>

//Creating a void queue
int main()
{
    Queue* queue = queue_new(sizeof(int));
    int num = 10, num1 = 12, num2 = 13;
    printf("\n Pushing into queue...");
    system("pause");
    queue_push(queue, &num);
    queue_push(queue, &num1);
    queue_push(queue, &num2);
    printf("\n Reading from queue...");
    system("pause");
    queue_print(queue);
    printf("\n Popping from queue...");
    system("pause");
    int* qval = (int*)queue_pop(queue);
    qval = (int*)queue_pop(queue);
    qval = (int*)queue_pop(queue);
    printf("\n freeing queue...");
    system("pause");
    queue_free(queue);
}