#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calclib.h"
#include "encode.h"
#include <math.h>

int main()
{
    unsigned int num1 = 49, num2 = 0, bits = 8;
    printf("\n Converting %d to binary...", num1);
    unsigned int* binary = uint_to_bin(num1, bits);
    printf("Converted: %d", *binary);

    system("pause");
    printf("\n Result: %d", bin_to_uint(binary, bits));
    system("pause");

    free(binary);
}