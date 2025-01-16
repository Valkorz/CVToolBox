#ifndef HMAP_H
#define HMAP_H
#define DEFAULT_START_SIZE 10
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Hash{
    char* key;
    char* value;
}Hash;

typedef struct HashMap{
    Hash* map;
    int size;
    int count;
}HashMap;

HashMap* createHashMap();
void add(HashMap* hashMap, char* _key, char* value);
void removeEntry(HashMap* hashMap, char* key);
char* get(HashMap* hashMap, char* key);
char** get_keys(HashMap* HashMap);
void printAll(HashMap* hashMap);
void clearMap(HashMap* hashMap);

#endif