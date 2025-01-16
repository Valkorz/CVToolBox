#ifndef CSV_H
#define CSV_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hmap.h"
#include "tmatch.h"

#define MAX_LENGTH 100 

/*
    This header implements logic for converting .csv files to an array of hash maps,
    using the HASHMAP_H header.
    Example:

    id, name, age, year
    0, bob, 25, 2000
    1, kate, 20, 2005

    would be equal to:

    HashMap** people;

    printf("%s", get(*(people), "name")); -> will print out "bob" since it's getting the KeyValuePair
    pointed at the first position of the HashMap array. 'get' is a function of the HASHMAP_H header.

    Also implements logic for creating and manipulating panda-like dataFrames.
*/

typedef struct DataFrame{
    HashMap** dataFrame;
    unsigned long headCount;
    unsigned long length;
}DataFrame;

void clearBuffer(const int len, char* buffer);
DataFrame* df_load(const char* fname);
void df_save(DataFrame* df, const char* fname);
DataFrame* df_new();
void df_append(DataFrame* df, HashMap* data);
void df_mean(DataFrame* df, const char* header);

#endif