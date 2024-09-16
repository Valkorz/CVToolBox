#include <stdio.h>
#include <stdlib.h>
#include "../../include/linkedList.h"

int main(){
    printf("\n Initializing program... \n");
    int data1 = 10, data2 = 20, data3 = 30;
    
    LinkedList linkedList;
    linkedList.head = createNode(&data1);
    printf("\n Created list: %p", &linkedList);

    linkNode(&linkedList, &data2);
    linkNode(&linkedList, &data3);
    printf("\n Linked data: %d into %p", data2, &linkedList);

    int* gotData = getData(&linkedList, 1);
    printf("\n Got data '%d' from %p", *gotData, &linkedList);
    gotData = getData(&linkedList, 2);
    printf("\n Got data '%d' from %p", *gotData, &linkedList);

    clear(&linkedList);
    printf("\n Cleared list.");

    system("pause");

    return 0;
}