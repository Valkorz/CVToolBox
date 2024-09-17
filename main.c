#include <stdio.h>
#include <stdlib.h>
#include "include/hashMap.h"
#include "include/calclib.h"

int main(){
    printf("Initializing hash map... \n \n");
    HashMap hashMap;
    createHashMap(&hashMap);

    char stdinVal = ' ';
    do{
        if(stdinVal == 'q' || stdinVal == 'Q') break;
        printf("\n Add a new key: ");
        char key[100], value[100];
        gets(key);
        printf("\n Add a value for it: ");
        gets(value);
        add(&hashMap, key, value);

        printf("\n \n adding into hash map... \n Press Q to quit or ENTER to add more.");
        scanf("%c", &stdinVal);
    }while(stdinVal != 'q' || stdinVal != 'Q');

    printf("\n Entries: \n");
    printAll(&hashMap);

    printf("\n Clearing hashmap...");
    clearMap(&hashMap);

    system("pause");
    
    return 0;
}