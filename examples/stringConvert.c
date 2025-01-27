#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmatch.h"

int main(){

    printf("\n 5.023 to float: %f", stringToFloat("5.023"));
    printf("\n 0.005 to float: %f", stringToFloat("0.005"));
    printf("\n 123.0543 to float: %f", stringToFloat("123.0543"));
    printf("\n 11123.0235235 to float: %f", stringToFloat("11123.0235235"));
    printf("\n 345.000005 to float: %f", stringToFloat("345.000005"));

    return EXIT_SUCCESS;
}