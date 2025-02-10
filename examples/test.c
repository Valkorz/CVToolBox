#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tmatch.h"

//this is just a test hahaha bobobo

int main()
{
    const char* msg = "HELLO BANANAS I LOVE BANANAS HAHAH BANANAS BANANAS LOL BANANAS TEEHEE BANANAS BANANAS hahha ohoho bna";
    printf("\n Message: %s \n Count of word 'BANANAS': %d \n Upper case ratio %f percent", msg, strcount(msg, "BANANAS"), upperRatio(msg) * 100);

    system("pause");
    return EXIT_SUCCESS;
}