#ifndef HASHMAP_H
#define HASMAP_H
#define DEFAULT_START_SIZE 10
#include <stdlib.h>
#include <stdio.h>

typedef struct Hash{
    char* key;
    void* value;
} Hash;

typedef struct HashMap{
    Hash* map;
    int size;
}HashMap;

//Initialize hashmap with default values
void createHashMap(HashMap* hashMap){
    Hash* newMap = (Hash*)malloc(sizeof(Hash) * DEFAULT_START_SIZE);

    //Loop to set all hashes to null, just to make sure.
    int i = 0;
    for(i < DEFAULT_START_SIZE; i++;){
        newMap[i].key = NULL;
        newMap[i].value = NULL;
    }
    hashMap->map = newMap;
    hashMap->size = DEFAULT_START_SIZE;

    printf("\n Created hashmap %p with size %i and map %p. \n",hashMap, DEFAULT_START_SIZE, newMap);
}

//adds or modifies a value into the hash map with a specified key.
void add(HashMap* hashMap, char* key, void* value){
    printf("Adding entry '%s':'%p' to %p", key, value, hashMap);

    int i = 0;
    Hash* currentHash = NULL;
    for(i < hashMap->size; i++;){
        currentHash = hashMap->map + i; 
        if(currentHash->key == key){
            currentHash->value = value;
            return;
        }
        if(currentHash->key == NULL){
            currentHash->value = value;
            currentHash->key = key;
            break;
        }
    }

    int newSize = hashMap->size + DEFAULT_START_SIZE;
    Hash* newMap = (Hash*)realloc(hashMap->map, sizeof(Hash) * newSize);
    if(newMap == NULL){
        fprintf(stderr, "Failed to reallocate memory for hash map\n");
        return;
    }

    for(i = newSize - DEFAULT_START_SIZE; i < newSize; i++){
        newMap[i].key = NULL;
        newMap[i].value = NULL;
    }

    hashMap->map = newMap;
    hashMap->size = newSize;

    hashMap->map[newSize - DEFAULT_START_SIZE].key = key;
    hashMap->map[newSize - DEFAULT_START_SIZE].value = value;
}

//Removes a specified keyvalue from the hashmap. Throws an error if key is not found.
void removeEntry(HashMap* hashMap, char* key){
    int i = 0;
    Hash* currentHash = hashMap->map + i;

    for(i < hashMap->size; i++;){
        currentHash = hashMap->map + i;
        if(currentHash->key == key){
            currentHash->value = NULL;
            currentHash->key = NULL;
            return;
        }
    }
    fprintf(stderr, "Key %s not found in %p.\n", key, hashMap);
}

//Returns a pointer to the value defined by the key in the hashmap
void* get(HashMap* hashMap, char* key){
    int i = 0;
    Hash* currentHash = hashMap->map + i;

    for(i < hashMap->size; i++;){
        currentHash = hashMap->map + i;
        if(currentHash->key == key){
            return currentHash->value;
        }
    }
    fprintf(stderr, "Key %s not found in %p.\n", key, hashMap);
}

void clear(HashMap* hashMap){
    free(hashMap->map);
}


#endif