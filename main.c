#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "calclib.h"
#include "encode.h"
// #include "collections.h"
#include <math.h>
#include "cllist.h"

//Creating a void queue
int main()
{
    CLList l = (CLList)malloc(sizeof(CLList));
    CLList l2 = l;
    printf("\ncclist mem: %p", l2);
    CreateCLL(&l);
    printf("\ncclist mem: %p", l2);

    system("pause");
}