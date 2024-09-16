#include <stdio.h>
#include <stdlib.h>
#include "include/hashMap.h"
#include "include/calclib.h"

int main(){
    // printf("Initializing hash map... \n \n");
    // HashMap hashMap;
    // createHashMap(&hashMap);

    // printf("\n Adding keypairs...");
    // int value1 = 15, value2 = 25;
    // add(&hashMap, "Banana", &value1);
    // add(&hashMap, "Apple", &value2);

    // printf("\n Reading values...");
    // printf("\n Value of banana: %i", (int)get(&hashMap, "Banana"));
    // printf("\n Value of apple: %i", (int)get(&hashMap, "Apple"));

    // printf("\n Modifying values...");
    // value1 = 22, value2 = 36;
    // add(&hashMap, "Banana", &value1);
    // add(&hashMap, "Apple", &value2);

    // printf("\n Reading values...");
    // printf("\n Value of banana: %i", (int)get(&hashMap, "Banana"));
    // printf("\n Value of apple: %i", (int)get(&hashMap, "Apple"));

    // printf("\n Clearing hashmap...");
    // clear(&hashMap);
    printf("Factorial of 0: %d", factorial(0));
    printf("\n prime number 2: %.2f", prime(2));
    // for(int i = 1; i <= 10; i++){
    //     printf("\n prime number %d: %d", i, prime(i));
    // }

    system("pause");
    
    return 0;
}